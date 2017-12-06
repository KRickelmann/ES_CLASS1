#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "inc/hw_memmap.h"

#include "src/Uart_helper.h"
#include "CAN.h"
#include "driverlib/adc.h"
#include "driverlib/aes.h"
#include "driverlib/comp.h"
#include "driverlib/cpu.h"
#include "driverlib/crc.h"
#include "driverlib/debug.h"
#include "driverlib/des.h"
#include "driverlib/eeprom.h"
#include "driverlib/emac.h"
#include "driverlib/epi.h"
#include "driverlib/flash.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/hibernate.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"
#include "driverlib/lcd.h"
#include "driverlib/mpu.h"
#include "driverlib/onewire.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/qei.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/rtos_bindings.h"
#include "driverlib/shamd5.h"
#include "driverlib/ssi.h"
#include "driverlib/sw_crc.h"
#include "driverlib/sysctl.h"
#include "driverlib/sysexc.h"
#include "driverlib/systick.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/usb.h"
#include "driverlib/watchdog.h"
#include "./inc/tm4c123gh6pm.h"

//#include "src/HAL_UART.h"
//#include "src/HAL_GPIO.h"
//#include "src/LEDStick_helper.h"
//#include "src/LCD_helper.h"
//#include "src/HAL_PLL.h"
//#include "src/HAL_Systick.h"
//#include "src/HAL_ADC.h"
//#include "src/HAL_Sasu.h"

#include "src/ST7735.h"
//#include "CAN.h"