#ifndef SRC_HW_LED_LED_H_
#define SRC_HW_LED_LED_H_

#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define Led_0 	0
#define Led_1 	1
#define Led_2 	2
#define Led_3 	3
#define Led_4 	4
#define Led_5 	5
#define Led_6 	6
#define Led_7 	7

#define CHANNEL_1	1

typedef struct _led
{
	int ledNum;
}ledInst;

void Led_Init();
void Led_MakeInst(ledInst *led, int ledNum);
void Led_On(ledInst *led);
void Led_Off(ledInst *led);
void Led_Toggle(ledInst *led);
void Led_Lshift();
void Led_Rshift();

#endif /* SRC_HW_LED_LED_H_ */
