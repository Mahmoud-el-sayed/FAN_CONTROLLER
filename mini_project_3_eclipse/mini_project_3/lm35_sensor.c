/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "lm35_sensor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 * 1. set 0 to temp and adc
 * 2- take adc_ref from struct (dynamic configuration)
 */
uint8 LM35_getTemperature(const ADC_ConfigType * Config_Ptr)
{
	uint8 temp_value = 0;
	uint16 adc_value = 0;
	uint8 adc_ref_valuee=Config_Ptr->ref_volt;
	/* Read ADC channel where the temperature sensor is connected */
		adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	switch  (adc_ref_valuee)
	{
	case 0:
		/* in case using 5 volt */
		temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*(ADC_REF))/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
		break;
	case 1:
		/* in case using A_refrence internal volt */
		temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*(ADC_REF_INTENAL_VOLT))/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
		break;
	case 3:
		/* in case using A_refrence internal volt */
		temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*(ADC_REF_INTENAL_VOLT))/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
		break;
	}




	return temp_value;
}

