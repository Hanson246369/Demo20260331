/******************** (C) COPYRIGHT 2020 sinowealth ***************************
 * @file  : lcd.c
 * @describe    lcd module
 * @brief    ---------------------------------------------------------------
 *          |   PB4 - COM1    |  PB12-15 -- SEG1-4          |
 *          |   PB5 - COM2    |  PC0 -11 -- SEG5-16         |
 *          |   PB6 - COM3    |  PB13-15 -- SEG17-19        |
 *              PB7 - COM4    |  PD0-6   -- SEG20-26
 *           ---------------------------------------------------------------
 *            lcd pin: 
 *             1     2     3    4     5     6     7     8     9     10    11 ----  30
 *            SEG1  SEG2  SEG3  SEG4  SEG5  COM1  COM2  COM3  COM4  SEG6  SEG7----SEG26
 * @author    sinowealth
**********************************************************************************/
#include "sh32f9xx_sb0_libcfg.h"
#include "lcd.h"
#include "delay.h"
#include "app.h"

//举例：第8个NUM的ABCD对应LCDBUF0的低4位，第8个NUM的FGE对应LCDBUF1的低4位。
#define S_A (1<< 3)
#define S_B (1<< 2)
#define S_C (1<< 1)
#define S_D (1<< 0)
#define S_E (1<< 5)
#define S_F (1<< 7)
#define S_G (1<< 6)

uint8_t LCD_NUM_CODE[eLCD_NUM_CODE_MAX] = 
{
	S_A|S_B|S_C|S_D|S_E|S_F,				//eNUM_0 	
	S_B|S_C,								//eNUM_1 	
	S_A|S_B|S_D|S_E|S_G,					//eNUM_2 	
	S_A|S_B|S_C|S_D|S_G,					//eNUM_3	
	S_B|S_C|S_F|S_G,						//eNUM_4 	
	S_A|S_C|S_D|S_F|S_G,					//eNUM_5 	
	S_A|S_C|S_D|S_E|S_F|S_G,				//eNUM_6 	
	S_A|S_B|S_C,							//eNUM_7 	
	S_A|S_B|S_C|S_D|S_E|S_F|S_G,			//eNUM_8 	
	S_A|S_B|S_C|S_D|S_F|S_G,				//eNUM_9 	
	0,										//eNUM_BLANK 
	S_A|S_D|S_E|S_F|S_G,        	 		//eNUM_E
	S_G, 							 		//eNUM_CROSS
	S_D|S_E|S_F,        					//eNUM_L
	S_A|S_C|S_D|S_F|S_G,   					//eNUM_S
	S_A|S_B|S_E|S_F|S_G,    				//eNUM_P
	S_E|S_G,                				//eNUM_r
	S_C|S_D|S_E|S_G,         				//eNUM_o
	S_A|S_E|S_F|S_G,          				//eNUM_F
	S_D|S_E|S_F|S_G,          				//eNUM_t
	S_C|S_E|S_F|S_G,           				//eNUM_h
	S_C|S_D|S_E,           					//eNUM_u
};

//void START_LED_GPIO_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);	
//	
//	GPIO_InitStructure.GPIO_Pin = START_LED_IND_PIN;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_Init(START_LED_IND_GPIO_PORT, &GPIO_InitStructure);
//	GPIO_PinAFConfig(START_LED_IND_GPIO_PORT, START_LED_IND_PIN, GPIO_AF_GPIO);
//	START_LED_IND_OFF();
//}

void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);
	
    GPIO_InitStructure.GPIO_Pin = LED_CTL_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 
    GPIO_Init(LED_CTL_GPIO_PORT, &GPIO_InitStructure);
    GPIO_PinAFConfig(LED_CTL_GPIO_PORT, LED_CTL_PIN, GPIO_AF_GPIO);
	LED_CTL_OFF();
}

/**
  ******************************************************************************
  * @name     void LCD_GPIO_Config(void)
  * @author   SinoWealth
  * @date     23-June-2021
  * @brief    GPIO initialization configuration
  * @param    None
  * @retval   None
  ******************************************************************************
  */
void LCD_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIOE clock */
    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);

    /* LCD MOULD COM PB4/5/6/7 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // must turn off pull up/down
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOB, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_AF_LCD);

    /* LCD MOULD SEG1-4 PB12/13/14/15  */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOB, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15, GPIO_AF_LCD);

    /* LCD MOULD SEG5-19   PC0-15 except pc12 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOC,
                     GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15, GPIO_AF_LCD); //?????????????AF?????????AF=0,???IO

    /* LCD MOULD SEG20-26   PD0-6  */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOD,
                     GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6, GPIO_AF_LCD);
}

/**
  ******************************************************************************
  * @name     void LCD_Config_Init(void)
  * @author   SinoWealth
  * @date     23-June-2021
  * @brief    LCD initialization configuration
  * @param    None
  * @retval   None
  ******************************************************************************
  */
void LCD_Config_Init(void)
{
    LCD_InitTypeDef LCD_InitStructure;

    // LCD MOULD GPIO CONFIG
    LCD_GPIO_Config();

    // Open LCDMOULD clock gate
    RCC_APB1PeriphClockOnOff(RCC_APB1_LCD, SH_ON);

    LCD_StructInit(&LCD_InitStructure);

    LCD_InitStructure.LcdEN = SH_OFF;                           /*!< LCD driver : SH_ON or SH_OFF */
    LCD_InitStructure.ClockSel = LCD_CLKSEL_LSI;                /*!< select clock :    0: LSI  1: 32.768kHZ Crystal*/
    LCD_InitStructure.Duty = LCD_DUTY_SEL0;                     /*!< DUTY*/
    LCD_InitStructure.VolSel = LCD_VOLSEL_1000VDD;              /*!< LCD Contrast*/
    LCD_InitStructure.ContrastEn = SH_ON;                       /*!< LCD Contrast :ON or OFF*/
    LCD_InitStructure.LcdPortSel = LCD_SHARE_SELECT;            /*share control switch bit */
    LCD_InitStructure.BiasResistance = LCD_BIASRES_900K;       /*LCD BIAS RESISTANCE*/  //LCD_BIASRES_900K LCD_BIASRES_1500K
    LCD_InitStructure.LcdDriverMode = LCD_DRVMOD_60K;           /*LCD driver mode*/ //  LCD_DRVMOD_60K   LCD_DRVMOD_900K_1500K LCD_DRVMOD_MID
    LCD_InitStructure.ChargeTime = LCD_CHARGE_TIM_64;           /*LCD charge time*/
    LCD_InitStructure.ScanfCounter = LCD_SCANFCONT_MODCTR_STOP; /*LCD SCAN conunter control*/
    LCD_InitStructure.ClockDIV = LCD_LSI_CLKSEL_4;              /*LCD clock division*/

    LCD_InitStructure.LcdCOM = LCD_SEC_COM1 | LCD_SEC_COM2 | LCD_SEC_COM3 | LCD_SEC_COM4; /*!< LCD COM MODE SELECT */
    LCD_InitStructure.LcdSEG1 = LCD_SEC_SEG_ALL1;                                         /*!< LCD SEG1 MODE SELECT*/
    LCD_InitStructure.LcdSEG2 = LCD_SEC_SEG_ALL2;                                         /*!< LCD SEG2 MODE SELECT*/
    LCD_InitStructure.LcdSEG3 = LCD_SEC_SEG_ALL3;                                         /*!< LCD SEG3 MODE SELECT*/

    LCD_InitStructure.LcdSEG4 = LCD_SEC_SEG25 | LCD_SEC_SEG26; /*!< LCD SEG4 MODE SELECT*/
    LCD_InitStructure.LcdSEG5 = LCD_SEC_SEG_NOP5;              /*!< LCD SEG5 MODE SELECT*/

    LCD_Init(LCD, &LCD_InitStructure);

    /* LCD driver mould ENABLE */
    LCD_OnOff(SH_ON);
}

/**
  ******************************************************************************
  * @name     void LCD_GPIO_Config(void)
  * @author   SinoWealth
  * @date     23-June-2021
  * @brief    turn on LSI
  * @param    None
  * @retval   None
  ******************************************************************************
  */
void LSI_TURNON(void)
{
    RCC->RCCLOCK = 0x33CC;
    RCC->CR.BIT.LSION = 1; //Turn on LSI
    while (!RCC->CR.BIT.LSIRDY)
    {
    }; //Wait for stability
    RCC->RCCLOCK = 0;
}

void LCD_DispalyAll(void)
{
	LCD->LCD_BUFS0.V32 = 0X0F0F0F0F;
	LCD->LCD_BUFS1.V32 = 0X0F0F0F0F;
	LCD->LCD_BUFS2.V32 = 0X0F0F0F0F;
	LCD->LCD_BUFS3.V32 = 0X0F0F0F0F;
	LCD->LCD_BUFS4.V32 = 0X0F0F0F0F;
	LCD->LCD_BUFS5.V32 = 0X0F0F0F0F;
	LCD->LCD_BUFS6.V32 = 0X000F0F0F;
}

void LCD_ClearAll(void)
{
	LCD->LCD_BUFS0.V32 = 0;
	LCD->LCD_BUFS1.V32 = 0;
	LCD->LCD_BUFS2.V32 = 0;
	LCD->LCD_BUFS3.V32 = 0;
	LCD->LCD_BUFS4.V32 = 0;
	LCD->LCD_BUFS5.V32 = 0;
	LCD->LCD_BUFS6.V32 = 0;
	
}

void LCD_PowerOnDisplay(void)
{
	static uint8_t count_500ms = 0;
	
	LED_CTL_ON();
	if(count_500ms < 4)
		LCD_DispalyAll();
	
	if(count_500ms == 4)
		LCD_ClearAll();

	if((count_500ms >= 4) && (count_500ms < 7))
	{
		LCD_DispNum(LCD_NUM_CODE[eNUM_F], LP_AREA_1);// F
		LCD_DispNum(LCD_NUM_CODE[eNUM_P], LP_AREA_2);// P
		LCD_DispNum(LCD_NUM_CODE[eNUM_0], LP_AREA_3);// 0
		LCD_DispNum(LCD_NUM_CODE[eNUM_5], LP_AREA_4);// 5
		
		LCD_DispNum(LCD_NUM_CODE[eNUM_CROSS], HP_AREA_1);//-
		LCD_DispNum(LCD_NUM_CODE[eNUM_0], HP_AREA_2);//0
		LCD_DispNum(LCD_NUM_CODE[eNUM_2], HP_AREA_3);//2
	}
	
	if(count_500ms == 7)
	{
		LCD_ClearAll();
		LCD_DispOrClrFlag(F_IN_OUT, LCD_DISP);
		LCD_DispOrClrFlag(F_M1, LCD_DISP);
		LCD_DispOrClrFlag(F_M2, LCD_DISP);
		
		if(MAC_SET.mute == MUTE_ON) 
			LCD_DispOrClrFlag(F_MUTE, LCD_DISP);//显示静音图标
		
		MAC_STA.powerOnReady = 1;
	}
	
	if(count_500ms < 8)
		count_500ms++;
}

void LCD_DispDemo(void)
{
	uint8_t i,j;
	for(i=0;i<eLCD_NUM_CODE_MAX;i++)
    {
		for(j=0;j<=8;j++)
        {
			LCD_DispNum(LCD_NUM_CODE[i], j);
        }
		IWDG_ReloadCounter(); // feed dog
		delay_ms(2000);
    }
	
	LCD_ClearAll();
	IWDG_ReloadCounter();
	delay_ms(2000);
	for(i=0;i<=46;i++)
    {
		LCD_DispOrClrFlag(i, LCD_DISP);
		IWDG_ReloadCounter(); // feed dog
		delay_ms(1000);
		LCD_DispOrClrFlag(i, LCD_CLR);
		IWDG_ReloadCounter(); // feed dog
		delay_ms(1000);
    }
}

void LCD_DispOrClrFlag(uint8_t flag, eLCD_SW_Type sw)
{
	switch (flag)
    {
    	case F_IN_OUT:		(sw == LCD_CLR) ? (LCD->LCD_BUFS2.BIT.LCDBUF8 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS2.BIT.LCDBUF8 |= ((uint8_t)1 << 0));break;
		case F_COMPLETE:	(sw == LCD_CLR) ? (LCD->LCD_BUFS2.BIT.LCDBUF8 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS2.BIT.LCDBUF8 |= ((uint8_t)1 << 1));break;
		case F_LP_MINUS:	(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF16 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS4.BIT.LCDBUF16 |= ((uint8_t)1 << 0));break;
		case F_LP_KPA:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF17 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS4.BIT.LCDBUF17 |= ((uint8_t)1 << 1));break;
		case F_LP_MPA:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF18 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS4.BIT.LCDBUF18 |= ((uint8_t)1 << 0));break;
		case F_LP_INHG:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF19 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS4.BIT.LCDBUF19 |= ((uint8_t)1 << 0));break;
		case F_LP_BAR:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF20 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS5.BIT.LCDBUF20 |= ((uint8_t)1 << 0));break;
		case F_LP_CMHG:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF21 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS5.BIT.LCDBUF21 |= ((uint8_t)1 << 0));break;
		case F_LP_PSIG:		(sw == LCD_CLR) ? (LCD->LCD_BUFS3.BIT.LCDBUF14 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS3.BIT.LCDBUF14 |= ((uint8_t)1 << 0));break;
		case F_HP_KPA:		(sw == LCD_CLR) ? (LCD->LCD_BUFS1.BIT.LCDBUF7 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS1.BIT.LCDBUF7 |= ((uint8_t)1 << 0));break;
		case F_HP_MPA:		(sw == LCD_CLR) ? (LCD->LCD_BUFS1.BIT.LCDBUF5 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS1.BIT.LCDBUF5 |= ((uint8_t)1 << 0));break;
		case F_HP_INHG:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF22 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS5.BIT.LCDBUF22 |= ((uint8_t)1 << 0));break;
		case F_HP_BAR:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF23 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS5.BIT.LCDBUF23 |= ((uint8_t)1 << 0));break;
		case F_HP_CMHG:		(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF24 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS6.BIT.LCDBUF24 |= ((uint8_t)1 << 0));break;
		case F_HP_PSIG:		(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF25 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS6.BIT.LCDBUF25 |= ((uint8_t)1 << 0));break;
		case F_INPUT:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF17 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS4.BIT.LCDBUF17 |= ((uint8_t)1 << 2));break;
		case F_OUTPUT:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF18 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS4.BIT.LCDBUF18 |= ((uint8_t)1 << 1));break;
		case F_CLOSED:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF19 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS4.BIT.LCDBUF19 |= ((uint8_t)1 << 1));break;
		case F_OPEN:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF20 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS5.BIT.LCDBUF20 |= ((uint8_t)1 << 1));break;
		case F_VOL_HIGH:	(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF22 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS5.BIT.LCDBUF22 |= ((uint8_t)1 << 2));break;
		case F_VOL_LOW:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF23 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS5.BIT.LCDBUF23 |= ((uint8_t)1 << 2));break;
		case F_VOLTAGE:		(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF24 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS6.BIT.LCDBUF24 |= ((uint8_t)1 << 2));break;
		case F_WARNING:		(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF25 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS6.BIT.LCDBUF25 |= ((uint8_t)1 << 1));break;
		case F_MUTE:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF18 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS4.BIT.LCDBUF18 |= ((uint8_t)1 << 3));break;
		case F_SERVICE:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF17 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS4.BIT.LCDBUF17 |= ((uint8_t)1 << 3));break;
		case F_VALVE:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF18 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS4.BIT.LCDBUF18 |= ((uint8_t)1 << 2));break;
		case F_COMPRESSOR:	(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF19 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS4.BIT.LCDBUF19 |= ((uint8_t)1 << 2));break;
		case F_PRS_HIGH:	(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF22 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS5.BIT.LCDBUF22 |= ((uint8_t)1 << 3));break;
		case F_PRS_LOW:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF23 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS5.BIT.LCDBUF23 |= ((uint8_t)1 << 3));break;
		case F_PRESSURE:	(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF24 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS6.BIT.LCDBUF24 |= ((uint8_t)1 << 3));break;
		case F_CUTOFF:		(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF25 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS6.BIT.LCDBUF25 |= ((uint8_t)1 << 2));break;
		case F_MOTOR:		(sw == LCD_CLR) ? (LCD->LCD_BUFS4.BIT.LCDBUF19 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS4.BIT.LCDBUF19 |= ((uint8_t)1 << 3));break;
		case F_FAULT:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF20 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS5.BIT.LCDBUF20 |= ((uint8_t)1 << 2));break;
		case F_FAULT_1:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF20 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS5.BIT.LCDBUF20 |= ((uint8_t)1 << 3));break;
		case F_FAULT_2:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF21 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS5.BIT.LCDBUF21 |= ((uint8_t)1 << 1));break;
		case F_FAULT_3:		(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF21 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS5.BIT.LCDBUF21 |= ((uint8_t)1 << 2));break;
		case F_OK_TO_START:	(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF21 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS5.BIT.LCDBUF21 |= ((uint8_t)1 << 3));break;
		case F_TANK_FULL:	(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF25 &= ~((uint8_t)1 << 3)) : (LCD->LCD_BUFS6.BIT.LCDBUF25 |= ((uint8_t)1 << 3));break;
		case F_HP_MINUS:	(sw == LCD_CLR) ? (LCD->LCD_BUFS2.BIT.LCDBUF8 &= ~((uint8_t)1 << 2)) : (LCD->LCD_BUFS2.BIT.LCDBUF8 |= ((uint8_t)1 << 2));break;
		case F_LP_P1:		(sw == LCD_CLR) ? (LCD->LCD_BUFS3.BIT.LCDBUF12 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS3.BIT.LCDBUF12 |= ((uint8_t)1 << 0));break;
		case F_LP_P2:		(sw == LCD_CLR) ? (LCD->LCD_BUFS2.BIT.LCDBUF10 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS2.BIT.LCDBUF10 |= ((uint8_t)1 << 0));break;
		case F_HP_P3:		(sw == LCD_CLR) ? (LCD->LCD_BUFS0.BIT.LCDBUF3 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS0.BIT.LCDBUF3 |= ((uint8_t)1 << 0));break;	
		case F_HP_P4:		(sw == LCD_CLR) ? (LCD->LCD_BUFS0.BIT.LCDBUF1 &= ~((uint8_t)1 << 0)) : (LCD->LCD_BUFS0.BIT.LCDBUF1 |= ((uint8_t)1 << 0));break;
		case F_M1:			(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF23 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS5.BIT.LCDBUF23 |= ((uint8_t)1 << 1));break;
		case F_M2:			(sw == LCD_CLR) ? (LCD->LCD_BUFS5.BIT.LCDBUF22 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS5.BIT.LCDBUF22 |= ((uint8_t)1 << 1));break;
		case F_M3:			(sw == LCD_CLR) ? (LCD->LCD_BUFS6.BIT.LCDBUF24 &= ~((uint8_t)1 << 1)) : (LCD->LCD_BUFS6.BIT.LCDBUF24 |= ((uint8_t)1 << 1));break;	
		
    	default:
    		break;
    }
}

void LCD_DispNum(uint8_t code, uint8_t pos)
{
	switch (pos)
    {
    	case LP_AREA_1:
			LCD->LCD_BUFS3.BIT.LCDBUF15 = (LCD->LCD_BUFS3.BIT.LCDBUF15 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS4.BIT.LCDBUF16 = (LCD->LCD_BUFS4.BIT.LCDBUF16 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
    	case LP_AREA_2:
			LCD->LCD_BUFS3.BIT.LCDBUF13 = (LCD->LCD_BUFS3.BIT.LCDBUF13 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS3.BIT.LCDBUF14 = (LCD->LCD_BUFS3.BIT.LCDBUF14 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
		case LP_AREA_3:
			LCD->LCD_BUFS2.BIT.LCDBUF11 = (LCD->LCD_BUFS2.BIT.LCDBUF11 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS3.BIT.LCDBUF12 = (LCD->LCD_BUFS3.BIT.LCDBUF12 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
		case LP_AREA_4:
			LCD->LCD_BUFS2.BIT.LCDBUF9 = (LCD->LCD_BUFS2.BIT.LCDBUF9 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS2.BIT.LCDBUF10 = (LCD->LCD_BUFS2.BIT.LCDBUF10 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
		case HP_AREA_1:
			LCD->LCD_BUFS1.BIT.LCDBUF6 = (LCD->LCD_BUFS1.BIT.LCDBUF6 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS1.BIT.LCDBUF7 = (LCD->LCD_BUFS1.BIT.LCDBUF7 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
		case HP_AREA_2:
			LCD->LCD_BUFS1.BIT.LCDBUF4 = (LCD->LCD_BUFS1.BIT.LCDBUF4 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS1.BIT.LCDBUF5 = (LCD->LCD_BUFS1.BIT.LCDBUF5 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
		case HP_AREA_3:
			LCD->LCD_BUFS0.BIT.LCDBUF2 = (LCD->LCD_BUFS0.BIT.LCDBUF2 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS0.BIT.LCDBUF3 = (LCD->LCD_BUFS0.BIT.LCDBUF3 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
		case HP_AREA_4:
			LCD->LCD_BUFS0.BIT.LCDBUF0 = (LCD->LCD_BUFS0.BIT.LCDBUF0 & 0xF0) | (code & 0x0F);	
			LCD->LCD_BUFS0.BIT.LCDBUF1 = (LCD->LCD_BUFS0.BIT.LCDBUF1 & 0xF1) | ((code >> 4) & 0x0F);
    		break;
		
    	default:
    		break;
    }
}


void LCD_ClearAllErrorFlag(void)
{
	uint8_t i;
	for(i = F_INPUT; i <= F_WARNING; i++)
		LCD_DispOrClrFlag(i, LCD_CLR);
	
    for(i = F_SERVICE; i <= F_TANK_FULL; i++)
		LCD_DispOrClrFlag(i, LCD_CLR);
}

void LCD_ClearNumAndFlag(uint8_t area, eClrSymbolType type)
{
	uint8_t i;
	
	if(type == CLR_SYMBOL_ALL)
	{
		LCD_ClearMinusFlag(area);
		LCD_ClearPointFlag(area);
		LCD_ClearUnitFlag(area);
	}
	else if(type == CLR_SYMBOL_MINUS_POINT)
	{
		LCD_ClearMinusFlag(area);
		LCD_ClearPointFlag(area);
	}
	
	if(area == LP_AREA)
	{
		for(i = LP_AREA_1; i <= LP_AREA_4; i++)
			LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], i);
	}
	else if(area == HP_AREA)
	{
		for(i = HP_AREA_1; i <= HP_AREA_4; i++)
			LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], i);
	}
	else if(area == LP_HP_AREA)
	{
		for(i = LP_AREA_1; i <= HP_AREA_4; i++)
			LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], i);
	}
}


void LCD_ClearUnitFlag(uint8_t area)
{
	uint8_t i;
	if(area == LP_AREA)
	{
		for(i = F_LP_KPA; i <= F_LP_PSIG; i++)
			LCD_DispOrClrFlag(i, LCD_CLR);
	}
	else if(area == HP_AREA)
	{
		for(i = F_HP_KPA; i <= F_HP_PSIG; i++)
			LCD_DispOrClrFlag(i, LCD_CLR);
	}
	else if(area == LP_HP_AREA)
	{
		for(i = F_LP_KPA; i <= F_HP_PSIG; i++)
			LCD_DispOrClrFlag(i, LCD_CLR);
	}
}

void LCD_ClearMinusFlag(uint8_t area)
{
	if(area == LP_AREA)
	{
		LCD_DispOrClrFlag(F_LP_MINUS, LCD_CLR);
	}
	else if(area == HP_AREA)
	{
		LCD_DispOrClrFlag(F_HP_MINUS, LCD_CLR);
	}
	else if(area == LP_HP_AREA)
	{
		LCD_DispOrClrFlag(F_LP_MINUS, LCD_CLR);
		LCD_DispOrClrFlag(F_HP_MINUS, LCD_CLR);
	}
}

void LCD_ClearPointFlag(uint8_t area)
{
	uint8_t i;
	if(area == LP_AREA)
	{
		for(i = F_LP_P1; i <= F_LP_P2; i++)
			LCD_DispOrClrFlag(i, LCD_CLR);
	}
	else if(area == HP_AREA)
	{
		for(i = F_HP_P3; i <= F_HP_P4; i++)
			LCD_DispOrClrFlag(i, LCD_CLR);
	}
	else if(area == LP_HP_AREA)
	{
		for(i = F_LP_P1; i <= F_HP_P4; i++)
			LCD_DispOrClrFlag(i, LCD_CLR);
	}
}

//pos:LP_AREA_2或者HP_AREA_2
void LCD_DispNumSpecialCode(uint8_t code, uint8_t area)
{
	LCD_ClearMinusFlag(area);
	LCD_ClearPointFlag(area);
	LCD_ClearUnitFlag(area);
	
	switch (code)
    {
    	case NUM_CODE_ZEROERR:
			LCD_DispNum(LCD_NUM_CODE[eNUM_2], LP_AREA_1);			//z
			LCD_DispNum(LCD_NUM_CODE[eNUM_E], LP_AREA_2);			//e
			LCD_DispNum(LCD_NUM_CODE[eNUM_r], LP_AREA_3);			//r
			LCD_DispNum(LCD_NUM_CODE[eNUM_o], LP_AREA_4);			//o
			LCD_DispNum(LCD_NUM_CODE[eNUM_E], HP_AREA_1);			//e
			LCD_DispNum(LCD_NUM_CODE[eNUM_r], HP_AREA_2);			//r
			LCD_DispNum(LCD_NUM_CODE[eNUM_r], HP_AREA_3);			//r
			LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], HP_AREA_4);		//空
    		break;
		
    	case NUM_CODE_PLGUOFS:
			LCD_DispNum(LCD_NUM_CODE[eNUM_P], LP_AREA_1);			//P
			LCD_DispNum(LCD_NUM_CODE[eNUM_L], LP_AREA_2);			//L
			LCD_DispNum(LCD_NUM_CODE[eNUM_u], LP_AREA_3);			//U
			LCD_DispNum(LCD_NUM_CODE[eNUM_9], LP_AREA_4);			//G
			LCD_DispNum(LCD_NUM_CODE[eNUM_0], HP_AREA_1);			//O
			LCD_DispNum(LCD_NUM_CODE[eNUM_F], HP_AREA_2);			//F
			LCD_DispNum(LCD_NUM_CODE[eNUM_S], HP_AREA_3);			//S
			LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], HP_AREA_4);		//空 
    		break;
		
		case NUM_CODE_THROTTLE:
			LCD_DispNum(LCD_NUM_CODE[eNUM_t], LP_AREA_1);			//t
			LCD_DispNum(LCD_NUM_CODE[eNUM_h], LP_AREA_2);			//h
			LCD_DispNum(LCD_NUM_CODE[eNUM_r], LP_AREA_3);			//r
			LCD_DispNum(LCD_NUM_CODE[eNUM_o], LP_AREA_4);			//o
			LCD_DispNum(LCD_NUM_CODE[eNUM_t], HP_AREA_1);			//t
			LCD_DispNum(LCD_NUM_CODE[eNUM_t], HP_AREA_2);			//t
			LCD_DispNum(LCD_NUM_CODE[eNUM_L], HP_AREA_3);			//l
			LCD_DispNum(LCD_NUM_CODE[eNUM_E], HP_AREA_4);			//e 
    		break;
		
		case NUM_CODE_STOP:
			LCD_DispNum(LCD_NUM_CODE[eNUM_S], HP_AREA_1);			//S
			LCD_DispNum(LCD_NUM_CODE[eNUM_t], HP_AREA_2);			//t
			LCD_DispNum(LCD_NUM_CODE[eNUM_o], HP_AREA_3);			//o
			LCD_DispNum(LCD_NUM_CODE[eNUM_P], HP_AREA_4);			//P
    		break;
		
		case NUM_CODE_E1:
			if (area == LP_AREA)
            {
				LCD_DispNum(LCD_NUM_CODE[eNUM_E], LP_AREA_1);		//E
				LCD_DispNum(LCD_NUM_CODE[eNUM_1], LP_AREA_2);		//1
				LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], LP_AREA_3);
				LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], LP_AREA_4);
            }
            else if(area == HP_AREA)
            {
				LCD_DispNum(LCD_NUM_CODE[eNUM_E], HP_AREA_1);		//E
				LCD_DispNum(LCD_NUM_CODE[eNUM_1], HP_AREA_2);		//1
				LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], HP_AREA_3);
				LCD_DispNum(LCD_NUM_CODE[eNUM_BLANK], HP_AREA_4);
            }
    		break;
	
    	default:
    		break;
    }
}

void LCD_ClearAllMotorFlag(void)
{
	uint8_t i;
	for(i = F_M1; i <= F_M3; i++)
		LCD_DispOrClrFlag(i, LCD_CLR);
}


/******************* (C) COPYRIGHT 2020 sinowealth *****END OF FILE************/
