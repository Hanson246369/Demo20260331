/****************************************************************************
*  INCLUDES
*****************************************************************************/
/* fist include must be the header */
//#include <stdio.h>  
//#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/* only static local functions are declared here */

/***************************************************************************
* FUNCTION IMPLEMENTATIONS
***************************************************************************/

bool Init_Queue( CIRCLEQUEUE *pg_stQueue)  
{  
	pg_stQueue->u16Front = pg_stQueue->u16Rear = 0;  
	pg_stQueue->u16Count = 0;  
	return true;  
}  

/*************************************************/  
bool Is_QueueEmpty( CIRCLEQUEUE *pg_stQueue)  
{  
	if(pg_stQueue->u16Count == 0)  
		return true;  
	else  
		return false;  
}  
  
/*************************************************/  
bool Is_QueueFull( CIRCLEQUEUE *pg_stQueue)  
{  
	if(pg_stQueue->u16Count == MAX_QUEUE_SIZE)  
		return true;  
	else  
		return false;  
}   
/*************************************************/  
bool En_Queue( CIRCLEQUEUE *pg_stQueue, uint8_t e)  
{  
	if(pg_stQueue->u16Count == MAX_QUEUE_SIZE)  
	{  
//		printf("The pg_stQueue is full");  
		return false;  
	}  

	pg_stQueue->data[pg_stQueue->u16Rear] = e;  
	pg_stQueue->u16Rear = (pg_stQueue->u16Rear + 1) % MAX_QUEUE_SIZE;  
	pg_stQueue->u16Count++;
	
	return true;  
}  
  
/*************************************************/ 
uint8_t De_Queue( CIRCLEQUEUE *pg_stQueue)  
{  
	if(pg_stQueue->u16Count == 0)  
	{  
//		printf("The pg_stQueue is empty!");  
		return 0;  
	}  

	uint8_t e = pg_stQueue->data[pg_stQueue->u16Front];  
	pg_stQueue->u16Front = (pg_stQueue->u16Front + 1) % MAX_QUEUE_SIZE;  
	pg_stQueue->u16Count--;  
  
	return e;  
}  
  
/*************************************************/  
uint8_t Queue_Front( CIRCLEQUEUE *pg_stQueue)  
{  
	if(pg_stQueue->u16Count == 0)  
	{  
//		printf("The pg_stQueue is empty!");  
		return 0;  
	}  
  
	return pg_stQueue->data[pg_stQueue->u16Front];    
} 
/*************************************************/   
bool Queue_Pop( CIRCLEQUEUE* pg_stQueue)
{
	if(pg_stQueue->u16Count > 0)
	{
		pg_stQueue->u16Front = (pg_stQueue->u16Front+1) % MAX_QUEUE_SIZE;
		pg_stQueue->u16Count--;
		return true;
	}
	else
	{
		return false;
	}
}

/************************************************
bool Clear_Queue( CIRCLEQUEUE *pg_stQueue )  
{  
	pg_stQueue->u16Front = pg_stQueue->u16Rear = 0;  
	pg_stQueue->u16Count = 0;  
	return true;    
}  
*/   
/*************************************************/  
uint16_t GetLength(CIRCLEQUEUE *pg_stQueue)  
{  
	return pg_stQueue->u16Count;    
}


/*
check queue buffer if correct.
return:
true --> OK;
false --> error;
**************************************************/
bool CheckQueue(CIRCLEQUEUE *pg_stQueue)
{
	static uint16_t u16FrontTemp = 0;
	static uint16_t u16RearTemp = 0;
	static uint16_t u16CountTemp = 0;
	
	u16FrontTemp = pg_stQueue->u16Front;
	u16RearTemp = pg_stQueue->u16Rear;
	u16CountTemp = pg_stQueue->u16Count;
	
	if(u16RearTemp < u16FrontTemp)
	{
		u16RearTemp +=  MAX_QUEUE_SIZE;
	}
	
	if((u16RearTemp - u16FrontTemp) == u16CountTemp)
	{
		return true;
	}
	else
	{
		return false;
	}
}


