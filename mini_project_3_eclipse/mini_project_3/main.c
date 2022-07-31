/*
 ================================================================================================
 Name        : temp_sensor_example.c
 Author      : Mohamed Tarek
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/9/2015
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include"dc_motor.h"
/*******************************************************************************/

int main(void)
{
	/*
	init the struct (dynamic configuration) with AREF and F_CPU with/ 8
	 */
	ADC_ConfigType ADC_Config={AREF_INTRNAL,F_CPU_8};
	/* make pointer to struct */
	ADC_ConfigType *adc_config_ptr=& ADC_Config;
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(& ADC_Config); /* initialize ADC driver */
	DcMotor_Init();
	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_clearScreen();
	LCD_displayString("FAN IS ");
	//LCD_moveCursor(1,0);
	//LCD_displayString("TEMP = ");


	/*
	 1.switch on case of temperature
	 2.show temperature on lcd
	 3.and control motor depends on value of temperature

	 */
	while(1)
	{
		temp= LM35_getTemperature(& ADC_Config);
		if (temp>=120)
		{
			LCD_moveCursor(0,7);
			LCD_displayString("ON ");
			DcMotor_Rotate(C_W,100);
			LCD_moveCursor(1,0);
			LCD_displayString("temp =   c");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
		}
		else if (temp>=90)
		{

			LCD_moveCursor(0,7);
			LCD_displayString("ON ");
			DcMotor_Rotate(C_W,75);
			LCD_moveCursor(1,0);
			LCD_displayString("temp =   c");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
		}
		else if (temp>=60)
		{

			LCD_moveCursor(0,7);
			LCD_displayString("ON ");
			DcMotor_Rotate(C_W,50);
			LCD_moveCursor(1,0);
			LCD_displayString("temp =   c");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
		}
		else if (temp>=30)
		{

			LCD_moveCursor(0,7);
			LCD_displayString("ON ");
			DcMotor_Rotate(C_W,25);
			LCD_moveCursor(1,0);
			LCD_displayString("temp =   c");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_moveCursor(0,7);
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP,0);
			LCD_moveCursor(1,0);
			LCD_displayString("temp =   c");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
		}

	}
}

