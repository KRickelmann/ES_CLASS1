#include "project.h"
#include "CAN.h"
#include "src/Uart_helper.h"

//Momentary switches are connected to
//

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

uint8_t test = 0;

//Hardware abstraction Layer.  Setup all the hardware
//Do it once.  
void SetupHardware()
{
	GpioSetup();							// GPIO
	
	ClockSetup();
	Uart1Setup();
	CAN_Init();
	initReceiver();

	ST7735_InitR(INITR_GREENTAB);  // init the ssi and LCD Screen
}

void lcd_setup()
{
	ST7735_FillRect(-5, -5, 150, 180, 0xFFFF);
	
	ST7735_DrawString(1, 0, "Embedded Systems", 0X0000);
	ST7735_DrawString(1, 1, "Final Project", 0X0000);
	ST7735_DrawString(1, 2, "Kurtis Rickelmann", 0X0000);
	
	ST7735_DrawString(1, 8, "MOTOR", 0X0000);
	ST7735_DrawString(1, 9, "SPEED", 0X0000);
	ST7735_DrawString(10, 5, "MAX", 0X0000);
	ST7735_DrawString(9, 14, "ZERO", 0X0000);
	
	ST7735_FillRect(78, 48, 44, 104, 0x0000);
	ST7735_FillRect(80, 50, 40, 100, 0xFFFF);
}

int  main(void)
{
		HALSasu();								//Custom Startup script for TIVA board
															//Unlocks pins, turns on all ports, etc.
		SetupHardware();					// Call all HAL setup functions
	
	
		GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_5);
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);

		lcd_setup();
	
		int speed = 0;
	
		while(1)
		{
			speed = MsgData[3][0];
			int i = (100 - speed * 90 / 255);
			if(i < 0)
				i = 0;
			ST7735_FillRect(80, 50, 40, i, 0xFFFF);
			ST7735_FillRect(80, 50+i, 40, 100 - i, 0xF000);
			
			ST7735_InvertDisplay(MsgData[5][2]);
			
			if(MsgData[6][2] == 2 || MsgData[5][2] == 64)
			{
				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 100);
			}
			else
			{
				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);
			}
		}		
}