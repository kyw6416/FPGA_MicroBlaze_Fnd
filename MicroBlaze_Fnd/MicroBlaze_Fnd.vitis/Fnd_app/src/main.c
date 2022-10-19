#include "main.h"

#define TICK_GENERATOR_DEV_BASE_ADDR 0x44A10000
#define TICK_DATA_REG *(uint32_t *)TICK_GENERATOR_DEV_BASE_ADDR

#define BCDtoFND_DEV_BASE_ADDR 0x44A00000
#define FND_SELECT_REG *(uint32_t *)(BCDtoFND_DEV_BASE_ADDR + 0)
#define FND_VALUE_REG *(uint32_t *)(BCDtoFND_DEV_BASE_ADDR + 4)

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
	uint32_t prevFndTick = 0;
	uint32_t prevCounterTick = 0;
	int fndSelect = 0;
	int counter = 0;
    while (1)
    {
    	if(TICK_DATA_REG - prevFndTick >= 3)
		{
			prevFndTick = TICK_DATA_REG;
			fndSelect = (fndSelect + 1) % 4;
			FND_SELECT_REG = fndSelect;
			if(fndSelect == 0)
			{
				FND_VALUE_REG = counter % 10;
			}
			else if(fndSelect == 1)
			{
				FND_VALUE_REG = counter /10 % 10;
			}
			if(fndSelect == 2)
			{
				FND_VALUE_REG = counter /100 % 10;
			}
			if(fndSelect == 3)
			{
				FND_VALUE_REG = counter /1000 % 10;
			}
		}
		if(TICK_DATA_REG - prevCounterTick >= 100)
		{
			prevCounterTick = TICK_DATA_REG;
			counter++;
		}
		if(TICK_DATA_REG - prevTick >= 500)
		{
			prevTick = TICK_DATA_REG;
			Led_Toggle(&modeButton);
			if(fndSelect == 3)
			{
				FND_VALUE_REG = counter /1000 % 10;
			}
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
