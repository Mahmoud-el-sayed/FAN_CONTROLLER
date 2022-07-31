/*
 * dc_motor.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Mahmoud
 */
#include"dc_motor.h"
#include"pwm.h"
#include"gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC MOTOR:
 * 1. Setup the MOROR pins directions by use the GPIO driver.
 * 2. INIT IT B ZERO TO BE STOP .
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_INPUT1_PORTID,DC_MOTOR_INPUT1_PINID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_INPUT2_PORTID,DC_MOTOR_INPUT2_PINID,PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_INPUT1_PORTID,DC_MOTOR_INPUT1_PINID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_INPUT2_PORTID,DC_MOTOR_INPUT2_PINID,LOGIC_LOW);


}


/*
 * Description :
 * MAKE the DC MOTOR DIRECTION AND SPEED:
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	GPIO_writePin(DC_MOTOR_INPUT1_PORTID,DC_MOTOR_INPUT1_PINID,1&state);
	GPIO_writePin(DC_MOTOR_INPUT2_PORTID,DC_MOTOR_INPUT2_PINID,1&(state>>1));
	PWM_Timer0_Init(speed);

}