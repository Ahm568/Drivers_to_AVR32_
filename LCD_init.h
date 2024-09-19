/*
 * LCD_init.h
 *
 *  Created on: 6 Sep 2024
 *      Author: User
 */

#ifndef HAL_HLCD_LCD_INIT_H_
#define HAL_HLCD_LCD_INIT_H_

#define First_Letter  0
#define Last_Letter   50

#define Line_1 1
#define Line_2 2

#define First_X_Location 0
#define Last_X_Location  16


#define ROW_0 0
#define ROW_1 1

#define COL_0 0
#define COL_1 1
#define COL_2 2
#define COL_3 3
#define COL_4 4
#define COL_5 5
#define COL_6 6
#define COL_7 7
#define COL_8 8
#define COL_9 9
#define COL_10 10
#define COL_11 11
#define COL_12 12
#define COL_13 13
#define COL_14 14
#define COL_15 15

#define Block_0 0
#define Block_1 1
#define Block_2 2
#define Block_3 3
#define Block_4 4
#define Block_5 5
#define Block_6 6
#define Block_7 7



#define CommandClearScreen 0b00000001
#define CommandShiftLeft   0b00011100
#define CommandShiftRight  0b00011000


#define First_Iteration  0


#define CommandGoToSecondLine	0b11000000
#define CommandGoToFirstLine	0b10000000

void HLCD_voidSendCommand   (u8 A_u8Comm);
void HLCD_voidSendData      (u8 A_u8Comm);
void HLCD_voidInit          (void);
void HLCD_voidCLRScreen     (void);
void HLCD_voidShiftLeft     (void);
void HLCD_voidShiftRight    (void);
void HLCD_voidDisplayString (u8 A_u8[50]);
void HLCD_voidDisplayNumber (u32 A_u8Number);//task
void HLCD_voidLCDGoToFirstLine(void);
void HLCD_voidLCDGoToSecondLine(void);
void HLCD_voidMoveCurser(u8 A_u8Row , u8 A_u8Col);
void HLCD_voidCustomerChar(u8 R_u8SpecialCharcter[]  ,
		                   u8 A_u8BlockNum           ,
		                   u8 A_u8Row                ,
						   u8 A_u8Col                );


u32 power(u32 exponent);
#endif /* HAL_HLCD_LCD_INIT_H_ */
