/*
 * KeyPad_prog.c
 *
 *  Created on: 8 Sep 2024
 *      Author: User
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/MDIO/DIO_init.h"
#include "KeyPad_init.h"
#include "KeyPad_cfg.h"
#include "KeyPad_private.h"
#include "util/delay.h"


void HKeyPad_voidKeyPadInit       (void)
{
	if(Cols_PINS_Dir != Rows_PINS_Dir)
	{

	for(u8 Col_PIN = Start_PIN_Cols ; Col_PIN <= Stop_PIN_Cols ; Col_PIN++)
	{
		MDIO_voidSetPinDir(Cols_PORT , Col_PIN , Cols_PINS_Dir);
	}

	for(u8 Row_PIN = Start_PIN_Rows ; Row_PIN <= Stop_PIN_Row ; Row_PIN++)
	{
		MDIO_voidSetPinDir(Rows_PORT , Row_PIN , Rows_PINS_Dir);
	}


	for(u8 Col_PIN = Start_PIN_Cols ; Col_PIN <= Stop_PIN_Cols ; Col_PIN++)
	{
		MDIO_voidWritePinValue(Cols_PORT , Col_PIN , PIN_HIGH);
	}
	}
}
u8   HKeyPad_u8ReadKeyPadValue    (void)
{
	u8 L_u8KeyPadValue = 255;
	for(u8 Col_PIN = Start_PIN_Cols ; Col_PIN <= Stop_PIN_Cols ; Col_PIN++)
	{
		MDIO_voidWritePinValue(Cols_PORT , Col_PIN ,PIN_LOW);  // Active
		for(u8 Row_PIN = Start_PIN_Rows ; Row_PIN <= Stop_PIN_Row ; Row_PIN++)
		{
			if(MDIO_u8ReadPinValue(Rows_PORT , Row_PIN) == Pressed)
			{
				_delay_ms(20);
				while(MDIO_u8ReadPinValue(Cols_PORT , Row_PIN) == 0 );
				L_u8KeyPadValue = R_u8AssignKeyPad [Col_PIN][Row_PIN - 4];
			}
		}
		MDIO_voidWritePinValue(Cols_PORT ,Col_PIN, PIN_HIGH);  // Deactive
	}
	return L_u8KeyPadValue;
}
