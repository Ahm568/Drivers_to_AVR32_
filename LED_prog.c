/*
 * LED_prog.c
 *
 *  Created on: 3 Sep 2024
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "LED_init.h"
#include "LED_cfg.h"
#include "../../MCAL/MDIO/DIO_init.h"

void HLED_voidLEDInit(u8 A_u8LEDNum)
{
	if(A_u8LEDNum >= LED_1 && A_u8LEDNum <= LED_8)
	{
		switch(A_u8LEDNum)
		{
		case LED_1 : MDIO_voidSetPinDir( LED_1_PORT, LED_1_PIN , DIO_OUTPUT);break;
		case LED_2 : MDIO_voidSetPinDir( LED_2_PORT, LED_2_PIN , DIO_OUTPUT);break;
		case LED_3 : MDIO_voidSetPinDir( LED_3_PORT, LED_3_PIN , DIO_OUTPUT);break;
		case LED_4 : MDIO_voidSetPinDir( LED_4_PORT, LED_4_PIN , DIO_OUTPUT);break;
		case LED_5 : MDIO_voidSetPinDir( LED_5_PORT, LED_5_PIN , DIO_OUTPUT);break;
		case LED_6 : MDIO_voidSetPinDir( LED_6_PORT, LED_6_PIN , DIO_OUTPUT);break;
		case LED_7 : MDIO_voidSetPinDir( LED_7_PORT, LED_7_PIN , DIO_OUTPUT);break;
		case LED_8 : MDIO_voidSetPinDir( LED_8_PORT, LED_8_PIN , DIO_OUTPUT);break;
		}
	}
}
void HLED_voidLEDON  (u8 A_u8LEDNum)
{
	if(A_u8LEDNum >= LED_1 && A_u8LEDNum <= LED_8)
	{
		switch(A_u8LEDNum)
		{
		case LED_1 : MDIO_voidWritePinValue ( LED_1_PORT, LED_1_PIN , PIN_HIGH);break;
		case LED_2 : MDIO_voidWritePinValue ( LED_2_PORT, LED_2_PIN , PIN_HIGH);break;
		case LED_3 : MDIO_voidWritePinValue ( LED_3_PORT, LED_3_PIN , PIN_HIGH);break;
		case LED_4 : MDIO_voidWritePinValue ( LED_4_PORT, LED_4_PIN , PIN_HIGH);break;
		case LED_5 : MDIO_voidWritePinValue ( LED_5_PORT, LED_5_PIN , PIN_HIGH);break;
		case LED_6 : MDIO_voidWritePinValue ( LED_6_PORT, LED_6_PIN , PIN_HIGH);break;
		case LED_7 : MDIO_voidWritePinValue ( LED_7_PORT, LED_7_PIN , PIN_HIGH);break;
		case LED_8 : MDIO_voidWritePinValue ( LED_8_PORT, LED_8_PIN , PIN_HIGH);break;
		}
	}
}
void HLED_voidLEDOFF (u8 A_u8LEDNum)
{
	if(A_u8LEDNum >= LED_1 && A_u8LEDNum <= LED_8)
	{
		switch(A_u8LEDNum)
		{
		case LED_1 : MDIO_voidWritePinValue ( LED_1_PORT, LED_1_PIN , PIN_LOW);break;
		case LED_2 : MDIO_voidWritePinValue ( LED_2_PORT, LED_2_PIN , PIN_LOW);break;
		case LED_3 : MDIO_voidWritePinValue ( LED_3_PORT, LED_3_PIN , PIN_LOW);break;
		case LED_4 : MDIO_voidWritePinValue ( LED_4_PORT, LED_4_PIN , PIN_LOW);break;
		case LED_5 : MDIO_voidWritePinValue ( LED_5_PORT, LED_5_PIN , PIN_LOW);break;
		case LED_6 : MDIO_voidWritePinValue ( LED_6_PORT, LED_6_PIN , PIN_LOW);break;
		case LED_7 : MDIO_voidWritePinValue ( LED_7_PORT, LED_7_PIN , PIN_LOW);break;
		case LED_8 : MDIO_voidWritePinValue ( LED_8_PORT, LED_8_PIN , PIN_LOW);break;
		}
	}
}
void HLED_voidLEDTog (u8 A_u8LEDNum)
{
	if(A_u8LEDNum >= LED_1 && A_u8LEDNum <= LED_8)
	{
		switch(A_u8LEDNum)
		{
		case LED_1 : MDIO_voidTogglePin( LED_1_PORT, LED_1_PIN );break;
		case LED_2 : MDIO_voidTogglePin( LED_2_PORT, LED_2_PIN );break;
		case LED_3 : MDIO_voidTogglePin( LED_3_PORT, LED_3_PIN );break;
		case LED_4 : MDIO_voidTogglePin( LED_4_PORT, LED_4_PIN );break;
		case LED_5 : MDIO_voidTogglePin( LED_5_PORT, LED_5_PIN );break;
		case LED_6 : MDIO_voidTogglePin( LED_6_PORT, LED_6_PIN );break;
		case LED_7 : MDIO_voidTogglePin( LED_7_PORT, LED_7_PIN );break;
		case LED_8 : MDIO_voidTogglePin( LED_8_PORT, LED_8_PIN );break;
		}
	}
}
