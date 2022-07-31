/*
 * dc_motor.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Mahmoud
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
#include"common_macros.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_INPUT1_PORTID PORTB_ID
#define DC_MOTOR_INPUT2_PORTID PORTB_ID
#define DC_MOTOR_INPUT1_PINID PIN0_ID
#define DC_MOTOR_INPUT2_PINID PIN1_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	STOP,C_W,A_C_W
}DcMotor_State ;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Initialize the DC MOTOR:
 * 1. Setup the MOROR pins directions by use the GPIO driver.
 * 2. INIT IT B ZERO TO BE STOP .
 */
void DcMotor_Init(void);
/*
 * Description :
 * MAKE the DC MOTOR DIRECTION AND SPEED:
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
