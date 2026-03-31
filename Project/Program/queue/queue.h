#ifndef __QUEUE_H
#define __QUEUE_H

/****************************************************************************
*  INCLUDES
*****************************************************************************/

#include <stdint.h>
#include <stdbool.h>
/* for use in C++ u8Code C-file header must use extern C define! */
#if defined (__cplusplus)
extern "C"
{
#endif

  /****************************************************************************
  * DEFINES
  *****************************************************************************/

  /* as few as possible */

#define MAX_QUEUE_SIZE 100 //modify  
  /****************************************************************************
  *  TYPE DECLARATIONS
  *****************************************************************************/

  /**
  *****************************************************************************
  @typedef SomeStruct
  some structure for something
  *****************************************************************************/
typedef struct _CIRCLEQUEUE  
{  
	uint8_t data[MAX_QUEUE_SIZE];// 
	uint16_t u16Front;// 
	uint16_t u16Rear;			//  
	volatile uint16_t u16Count;		// 
}CIRCLEQUEUE, Circlequeue; 

  /****************************************************************************
  *  FUNCTION DECLARATIONS
  *****************************************************************************/

  /**
  *****************************************************************************
  @brief Short descripion of some function doing something

  Detailed description ......
  ...... ........ ...... ......... .........
  ...... ......... ..... ... ....... .......... ..

  @param [in]  some parameter in
  @param [in]  some parameter in
  @param [out]  some parameter out

  @return some return value
  *****************************************************************************/

  /* note the decl is defined in the config file and must be used for shared builds! */

bool Init_Queue( CIRCLEQUEUE *pg_stQueue);  
bool Is_QueueEmpty( CIRCLEQUEUE *pg_stQueue); 
bool Is_QueueFull( CIRCLEQUEUE *pg_stQueue);  
bool En_Queue( CIRCLEQUEUE *pg_stQueue, uint8_t e); 
uint8_t De_Queue( CIRCLEQUEUE *pg_stQueue);  
uint8_t Queue_Front( CIRCLEQUEUE *pg_stQueue); 
bool Queue_Pop( CIRCLEQUEUE* pg_stQueue);
//bool Clear_Queue( CIRCLEQUEUE *pg_stQueue );
uint16_t GetLength( CIRCLEQUEUE *pg_stQueue);  
bool CheckQueue(CIRCLEQUEUE *pg_stQueue);

#if defined (__cplusplus)
}
#endif

#endif /* __Queue__ */


 
