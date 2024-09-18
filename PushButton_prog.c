/*
 * PushButton_prog.c
 *
 *  Created on: 5 Sep 2024
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/MDIO/DIO_init.h"
#include "PushButton_init.h"
#include "PushButton_cfg.h"
#include <util/delay.h>



void  HPushButton_voidInit     (u8 A_u8PbID)
{
	if(A_u8PbID >= PB_1 && A_u8PbID <= PB_3)
	{
		switch(A_u8PbID)
		{
		case PB_1:
			MDIO_voidSetPinDir      (PB_1_PORT , PB_1_PIN , DIO_INPUT);
			MDIO_voidWritePinValue  (PB_1_PORT , PB_1_PIN , PIN_HIGH); //enable internal pull up
			break ;
		case PB_2:
			MDIO_voidSetPinDir      (PB_2_PORT , PB_2_PIN , DIO_INPUT);
			MDIO_voidWritePinValue  (PB_2_PORT , PB_2_PIN , PIN_HIGH); //enable internal pull up
			break ;
		case PB_3:
			MDIO_voidSetPinDir      (PB_3_PORT , PB_3_PIN , DIO_INPUT);
			MDIO_voidWritePinValue  (PB_3_PORT , PB_3_PIN , PIN_HIGH); //enable internal pull up
			break ;
		}
	}
}
u8    HPushButton_u8ReadState  (u8 A_u8PbID)
{
	if(A_u8PbID >= PB_1 && A_u8PbID <= PB_3)
	{
		u8 L_u8PBState = NOT_PRESSED;
		switch(A_u8PbID)
		{
		case PB_1:
			L_u8PBState = MDIO_u8ReadPinValue (PB_1_PORT , PB_1_PIN );
			_delay_ms(20);
			if (PRESSED == MDIO_u8ReadPinValue (PB_1_PORT , PB_1_PIN ))
			{
				while (PRESSED == MDIO_u8ReadPinValue (PB_1_PORT , PB_1_PIN )) ; // still here until pick up my finger
				L_u8PBState = PRESSED;
			}
			else
			{
				L_u8PBState = NOT_PRESSED;
			}
			break;
		case PB_2:
			L_u8PBState = MDIO_u8ReadPinValue (PB_2_PORT , PB_2_PIN );
			break;
		case PB_3:
			L_u8PBState = MDIO_u8ReadPinValue (PB_3_PORT , PB_3_PIN );
			break;
		}
		return L_u8PBState;
	}
}
