#include "Led.h"

XGpio GPIO_LED;

void Led_Init()
{
	XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, 0x00);
}

void Led_MakeInst(ledInst *led, int ledNum) // ����ü�� ����� -> �ν��Ͻ� �����
{
	led -> ledNum = ledNum;
}

void Led_On(ledInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	// XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | ~(1<<0));		// 0�� led
	// XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | ~(1<<1));		// 1�� led
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1 << (led -> ledNum)));
}

void Led_Off(ledInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);	// �ش� ��ġ�� �о
	// XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState & ~(1<<0));
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState & ~(1 << (led -> ledNum)));
}

void Led_Toggle(ledInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState ^ (1 << (led -> ledNum)));
}


void Led_Lshift()
{
	for(int i = 0; i < 8; i++)
	{
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 1 << i);
		usleep(300000);
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0 << i);
	}
}

void Led_Rshift()
{
	for(int i = 0; i < 8; i++)
	{
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 128 >> i);
		usleep(300000);
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, (0 & (128 >> i)));
	}
}
