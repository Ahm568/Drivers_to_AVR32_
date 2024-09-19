/*
 * LCD_prog.c
 *
 *  Created on: 6 Sep 2024
 *      Author: User
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/MDIO/DIO_init.h"
#include "LCD_init.h"
#include "LCD_cfg.h"
#include "util/delay.h"


void HLCD_voidInit (void)
{
	_delay_ms(100); //Step in DataSheet
	MDIO_voidSetPinDir (LCD_RS_PORT , LCD_RS_PIN , DIO_OUTPUT);//RS
	MDIO_voidSetPinDir (LCD_RW_PORT , LCD_RW_PIN , DIO_OUTPUT);//RW
	MDIO_voidSetPinDir (LCD_E_PORT  , LCD_E_PIN  , DIO_OUTPUT);//E
	MDIO_voidSetPortDir(LCD_Command_PORT , PORT_OUTPUT);

	HLCD_voidSendCommand(0b00111000);
	_delay_ms(1);

	HLCD_voidSendCommand(0b00001110);
	_delay_ms(1);

	HLCD_voidSendCommand(CommandClearScreen);//clear screen
	_delay_ms(10);

	HLCD_voidSendCommand(0b00000110);
	_delay_ms(1);
}

void HLCD_voidSendCommand (u8 A_u8Comm)
{
	MDIO_voidWritePinValue(LCD_RS_PORT , LCD_RS_PIN , PIN_LOW);//RS
	MDIO_voidWritePinValue(LCD_RW_PORT , LCD_RW_PIN , PIN_LOW);//RW
	MDIO_voidWritePortValueWithOneNumber(LCD_Command_PORT , A_u8Comm);//comm
	MDIO_voidWritePinValue(LCD_E_PORT , LCD_E_PIN , PIN_HIGH);
	_delay_ms(10);
	MDIO_voidWritePinValue(LCD_E_PORT , LCD_E_PIN , PIN_LOW);
	_delay_ms(10);
}
void HLCD_voidSendData    (u8 A_u8Comm)
{
	MDIO_voidWritePinValue(LCD_RS_PORT , LCD_RS_PIN , PIN_HIGH);//RS
	MDIO_voidWritePinValue(LCD_RW_PORT , LCD_RW_PIN , PIN_LOW);//RW
	MDIO_voidWritePortValueWithOneNumber(LCD_Command_PORT , A_u8Comm);//comm
	MDIO_voidWritePinValue(LCD_E_PORT , LCD_E_PIN , PIN_HIGH);
	_delay_ms(10);
	MDIO_voidWritePinValue(LCD_E_PORT , LCD_E_PIN , PIN_LOW);
	_delay_ms(10);
}

void HLCD_voidCLRScreen   (void)
{
	HLCD_voidSendCommand(CommandClearScreen);//clear screen
	_delay_ms(10);
}

void HLCD_voidShiftLeft   (void)
{
	HLCD_voidSendCommand(CommandShiftLeft);//Shift left
		_delay_ms(1);
}


void HLCD_voidShiftRight  (void)
{
	HLCD_voidSendCommand(CommandShiftRight);//Shift Right
		_delay_ms(1);
}

void HLCD_voidDisplayString (u8 A_u8[50])
{
	for(int Number_Letter = First_Letter ; Number_Letter <= Last_Letter ; Number_Letter++)
	{
		if(A_u8[Number_Letter] != '\0') // '\0' == Null value
		{
			HLCD_voidSendData(A_u8[Number_Letter]);
		}
		if(A_u8[Number_Letter] == '\0')
		{
			Number_Letter = Last_Letter + 1 ;
		}
	}
}


void HLCD_voidDisplayNumber (u32 A_u8Number)
{
	u32 R_u8NumberToDisplayOnLCD[Max_Number_Of_Digit];
	u32 G_u8DivideOverTen = A_u8Number;
	u32 G_u8Counter = 0;
	u8 L_u8Iteration = 0 ;
	for (L_u8Iteration = First_Iteration ; L_u8Iteration<Max_Number_Of_Digit ; L_u8Iteration ++ )
	{
		R_u8NumberToDisplayOnLCD[L_u8Iteration]=(G_u8DivideOverTen % 10);
		G_u8DivideOverTen /= 10;
		G_u8Counter += 1;
		if(G_u8DivideOverTen == 0 )
		{
			L_u8Iteration=50;
		}
	}
	u8 L_u8IterationToDisplay = 0;
	for(L_u8IterationToDisplay = G_u8Counter-1 ; L_u8IterationToDisplay >=0 ; L_u8IterationToDisplay--)
	{
		HLCD_voidSendData   (R_u8NumberToDisplayOnLCD[L_u8IterationToDisplay] + '0');
		if(L_u8IterationToDisplay == 0 )
		{
			break;
		}
	}
}



void HLCD_voidLCDGoToSecondLine(void)
{
	HLCD_voidSendCommand(CommandGoToSecondLine);
}

void HLCD_voidLCDGoToFirstLine(void)
{
	HLCD_voidSendCommand(CommandGoToFirstLine);
}

void HLCD_voidMoveCurser(u8 A_u8Row , u8 A_u8Col)
{
	if((A_u8Row == ROW_0) || (A_u8Row == ROW_1))
	{
		if((A_u8Col >= COL_0) && (A_u8Col <= COL_15))
		{
			switch(A_u8Row)
			{
			case ROW_0:
				HLCD_voidSendCommand(A_u8Col + 0x80);//Put 1 in bit 7 to this code go to CGROM
				break;
			case ROW_1:
				HLCD_voidSendCommand(A_u8Col + (0x80 + 0x40)); //(0x80 + 0x40) = 0xc0
				break;
			}
		}
	}
}

void HLCD_voidCustomerChar(u8 R_u8SpecialCharcter[]  ,
		                   u8 A_u8BlockNum           ,
		                   u8 A_u8Row                ,
						   u8 A_u8Col                )
{
	if(A_u8BlockNum >= Block_0 , A_u8BlockNum <= Block_7)
	{
		if((A_u8Row == ROW_0) || (A_u8Row == ROW_1))
		{
			if((A_u8Col >= COL_0) && (A_u8Col <= COL_15))
			{
	HLCD_voidSendCommand(0x40 + (A_u8BlockNum*8));//to talk to Block With its number , 0100 0000 = 0x40
	u8 L_u8SaveChar = 0;
	for(L_u8SaveChar = 0 ; L_u8SaveChar < 8 ; L_u8SaveChar++)
	{
		HLCD_voidSendData(R_u8SpecialCharcter[L_u8SaveChar]);

	}

	HLCD_voidMoveCurser(A_u8Row , A_u8Col);
	HLCD_voidSendData(A_u8BlockNum);
			}
		}
	}
}


u32 power(u32 exponent)
{
    u32 result =  1; // Initialize result

    // Calculate 10^exponent
    for (int i = 0; i < exponent; i++)
    {
        result *= 10; // Multiply by 10 for each iteration
    }

    // If the exponent is negative, return a fractional result
    return exponent < 0 ? 1.0 / result : result;
}


