/*
 * SevenSeg_prog.c
 *
 *  Created on: 4 Sep 2024
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/MDIO/DIO_init.h"
#include "SevenSeg_cfg.h"
#include "SevenSeg_init.h"
#include "SevenSeg_private.h"

void HSevenSeg_voidSevenSegInit         (u8 A_u8SegID)
{
		switch(A_u8SegID)
		{
		case SEG_1_ID:
			MDIO_voidSetPortDir(Seg_1_PORT , PORT_OUTPUT);
			MDIO_voidSetPinDir(SEG_1_COMM_PORT , SEG_1_COMM_PIN , DIO_OUTPUT);
			break;
		case SEG_2_ID:
			MDIO_voidSetPortDir(Seg_2_PORT , PORT_OUTPUT);
			MDIO_voidSetPinDir(SEG_2_COMM_PORT , SEG_2_COMM_PIN , DIO_OUTPUT);
			break;
		}
}
void HSevenSeg_voidSevenSegON           (u8 A_u8SegID)
{
	switch(A_u8SegID)
	{
	case SEG_1_ID:
		if (Seg_1_Type == COMM_ANODE)
		{
			MDIO_voidWritePinValue (SEG_1_COMM_PORT , SEG_1_COMM_PIN , PIN_HIGH);
		}
		else if (Seg_1_Type == COMM_CATHODE)
		{
			MDIO_voidWritePinValue (SEG_1_COMM_PORT , SEG_1_COMM_PIN , PIN_LOW);
		}
		break;
	case SEG_2_ID:
		if (Seg_2_Type == COMM_ANODE)
		{
			MDIO_voidWritePinValue (SEG_2_COMM_PORT , SEG_2_COMM_PIN , PIN_HIGH);
		}
		else if (Seg_2_Type == COMM_CATHODE)
		{
			MDIO_voidWritePinValue (SEG_2_COMM_PORT , SEG_2_COMM_PIN , PIN_LOW);
		}
		break;
	}
}



void HSevenSeg_voidSevenSegDisplayNum   (u8 A_u8SegID , u8 A_u8NumToDisplay)
{
		if(A_u8NumToDisplay >= NUM_0 && A_u8NumToDisplay <= NUM_9)
		{
			switch(A_u8SegID)
			{
			case SEG_1_ID:
				if (Seg_1_Type == COMM_ANODE)
				{
					MDIO_voidWritePortValueWithOneNumber(Seg_1_PORT ,~R_u8ArrayOfDisplayNum[A_u8NumToDisplay]);
				}
				else if (Seg_1_Type == COMM_CATHODE)
				{
					MDIO_voidWritePortValueWithOneNumber(Seg_1_PORT ,R_u8ArrayOfDisplayNum[A_u8NumToDisplay]);
				}
				break;
			case SEG_2_ID:
				if (Seg_2_Type == COMM_ANODE)
				{
					MDIO_voidWritePortValueWithOneNumber(Seg_2_PORT ,~R_u8ArrayOfDisplayNum[A_u8NumToDisplay]);
				}
				else if (Seg_2_Type == COMM_CATHODE)
				{
					MDIO_voidWritePortValueWithOneNumber(Seg_2_PORT ,R_u8ArrayOfDisplayNum[A_u8NumToDisplay]);
				}
				break;
			}
		}
}



void HSevenSeg_voidSevenSegOFF           (u8 A_u8SegID)
{
	switch(A_u8SegID)
	{
	case SEG_1_ID:
		if (Seg_1_Type == COMM_ANODE)
		{
			MDIO_voidWritePinValue (SEG_1_COMM_PORT , SEG_1_COMM_PIN , PIN_LOW);
		}
		else if (Seg_1_Type == COMM_CATHODE)
		{
			MDIO_voidWritePinValue (SEG_1_COMM_PORT , SEG_1_COMM_PIN , PIN_HIGH);
		}
		break;
	case SEG_2_ID:
		if (Seg_2_Type == COMM_ANODE)
		{
			MDIO_voidWritePinValue (SEG_2_COMM_PORT , SEG_2_COMM_PIN , PIN_LOW);
		}
		else if (Seg_2_Type == COMM_CATHODE)
		{
			MDIO_voidWritePinValue (SEG_2_COMM_PORT , SEG_2_COMM_PIN , PIN_HIGH);
		}
		break;
	}
}
