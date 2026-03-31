#include "sh32f9xx_sb0_libcfg.h"
#include "key.h"
#include "beep.h"
#include "app.h"

#define KEYBUFF_SIZE  		2     //键盘缓冲区大小
uint8_t KeyBuff[KEYBUFF_SIZE];   //定义按键缓冲队列FIFO
static uint8_t Key_Count = 0;             //键盘缓冲队列记录的按键次数
uint8_t cur_key_no;

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);	
	
	GPIO_InitStructure.GPIO_Pin = KEY_START_PIN | KEY_MUTE_PIN | KEY_ZERO_PIN | KEY_UNIT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(KEY_GPIO_PORT, KEY_START_PIN | KEY_MUTE_PIN | KEY_ZERO_PIN | KEY_UNIT_PIN, GPIO_AF_GPIO);
}

void Key_InBuff(uint8_t Key)
{
	static uint8_t Key_IndexW = 0;            //键盘缓冲队列写入指针
	if(Key_Count >= KEYBUFF_SIZE) 
		return;//若缓冲区已满，放弃本次按键
	//   _DINT();                           //涉及共享数据，关中断保护
	Key_Count++;                       //按键次数计数加1
	KeyBuff[Key_IndexW] = Key;           //从队列头部追加新的数据
	if(++Key_IndexW >= KEYBUFF_SIZE) 
		Key_IndexW = 0;//循环队列
	//   _EINT();                            //恢复中断
}

void Handle_GetKey(void)
{
	uint8_t Key;  
	static uint8_t Key_IndexR = 0;            //键盘缓冲队列读取指针	
	if(Key_Count == 0)  
		return;     //若无按键，返回0
	//   _DINT();                         //涉及共享数据，关中断保护
	Key_Count--;                     //按键次数计数减1
	Key = KeyBuff[Key_IndexR];         //从缓冲区尾部读取一个按键值
	if(++Key_IndexR >= KEYBUFF_SIZE)  
		Key_IndexR = 0; //队列尾指针回到队列起始位置
	//   _EINT();                           //恢复中断
	cur_key_no = Key;
	KeyTaskDeal();
}

void Handle_KeyDetect(void)
{
	uint8_t key_cnt, key_no;
	uint8_t keyin;
	static uint8_t keycnt_temp = 0;
	static uint8_t key_effective = 0;
	static uint32_t long_cnt = 0;
	static uint8_t key_delay = 0;
	static uint8_t debouce_cnt, pre_key_no;
	
	uint16_t temp;
	if(key_delay == 0)
	{
		key_cnt = 0;
		key_no = 0;
		temp = KEY_GPIO_READ();
		keyin = (~(temp >> 12)) & 0x0F; 
		while(keyin && (key_cnt < 2))
		{
			if(keyin & 0x01)
			{
				key_cnt++;	
			}
			keyin = (keyin >> 1);
			key_no++;
		}
		
		if(key_cnt > 1)
		{
			debouce_cnt = 2;  
			cur_key_no = 0; 
			/*预留添加组合键功能*/
		}
		else if(key_cnt == 0)
		{
			long_cnt = 0;
			debouce_cnt = 2;
			keycnt_temp = 0;
			if(key_effective)      //短按，按键按下小于1S
			{
				if(cur_key_no)
				{
					if(cur_key_no != 2) 
					{
						if((enterLPModeFlag == 1) && (cur_key_no == KEY_POWER)) 
						{;}
						else
						{
							Key_InBuff(cur_key_no);
						}
						Beep_SetMode1();
					}
					key_delay = 70;//有效按键按下后，700ms后才能按下一个按键,防止重复按键 
				}
			}
			cur_key_no = 0;
		}	
		else if(!cur_key_no)
		{             //key_cnt==1
			if(pre_key_no == key_no)
			{
				debouce_cnt--;
				if(!debouce_cnt)
				{
					cur_key_no = key_no;
				}	
			}
			else 
			{
				debouce_cnt = 2;
				pre_key_no = key_no;
			}
		}
		else			
		{
			if(long_cnt < 300) 
				long_cnt++;
			else 
				long_cnt = 300;

			if(long_cnt < 100)
			{
				key_effective = 1;		//短按
			}
			else 						//长按
			{
				key_effective = 0;
				if(keycnt_temp == 0)
				{ 
					if(long_cnt >= 300) 
					{
						keycnt_temp = 1;
						switch(key_no)
						{
							case 1:	//长按UNIT
								if(LPModeAutoQuitDelay_500ms == 0)
								{
									Key_InBuff(KEY_UNIT_LONG);
									Beep_SetMode1();
								}
								key_delay=50;//有效按键按下后，500ms后才能按下一个按键,防止重复按键 
								break;
								
							case 2://长按ZER0 调零
								if(enterLPModeFlag == 0)  
									Key_InBuff(KEY_ZERO_LONG);

								Beep_SetMode1();
								key_delay=50;//有效按键按下后，500ms后才能按下一个按键,防止重复按键 
								break;
								
							case 3: //长按Cancel alarm 静音
								Key_InBuff(KEY_MUTE_LONG);
								Beep_SetMode1();
								key_delay=50;//有效按键按下后，500ms后才能按下一个按键,防止重复按键 
								break;
							
							case 4://长按START
								break;
							
							default:
								break;
						}
					}
				}
			}
		}
	}
	else 
		key_delay--;
}

