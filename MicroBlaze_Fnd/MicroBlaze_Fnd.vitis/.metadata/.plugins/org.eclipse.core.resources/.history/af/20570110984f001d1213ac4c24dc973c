#include "main.h"

#define TICK_GENERATOR_DEV_BASE_ADDR 0x44A00000
#define TICK_DATA_REG *(uint32_t *)TICK_GENERATOR_DEV_BASE_ADDR

int main()
{
    init_platform();

    Led_Init();
    ledInst modeLed;
    ledInst upLed;
    ledInst downLed;
    ledInst blinkLed;
    Led_MakeInst(&modeLed, Led_0);
    Led_MakeInst(&upLed, Led_1);
    Led_MakeInst(&downLed, Led_2);
    Led_MakeInst(&blinkLed, Led_3);

    buttonInst modeButton;
    buttonInst LshiftButton;
    buttonInst RshiftButton;
    buttonInst offButton;

    Button_Init();
    Button_MakeInst(&modeButton, Button_0);
    Button_MakeInst(&LshiftButton, Button_3);
    Button_MakeInst(&RshiftButton, Button_2);
    Button_MakeInst(&offButton, Button_1);

    uint32_t prevTick = 0;
//    static int button_count = 0;
    while (1)
    {
    	if (TICK_DATA_REG - prevTick >= 500)	// 500 차이가 나면
			{
				prevTick = TICK_DATA_REG;
				Led_Toggle(&blinkLed);
			}
    	if(Buttom_GetState(&modeButton)){
    		print("pushed mode button\n\r");
    		Led_Toggle(&modeLed);
//    		button_count ++;
//			button_count %= 2;
//			if(button_count)
//			{
//				Led_On();
//			}
//			else
//			{
//				Led_Off();
//				button_count = 0;
//			}
    	}
    	if(Buttom_GetState(&LshiftButton)){
    		print("pushed LshiftButton button\n\r");
    		Led_On(&upLed);
    		Led_Off(&downLed);
//    		Led_Lshift();
    	}
    	if(Buttom_GetState(&RshiftButton)){
			print("pushed RshiftButton button\n\r");
			Led_On(&downLed);
			Led_Off(&upLed);
//			Led_Rshift();
		}
    }
    cleanup_platform();
    return 0;
}
