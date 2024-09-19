/*
 * KeyPad_cfg.h
 *
 *  Created on: 8 Sep 2024
 *      Author: User
 */

#ifndef HAL_HKEYPAD_KEYPAD_CFG_H_
#define HAL_HKEYPAD_KEYPAD_CFG_H_

#define Cols_PINS_Dir DIO_OUTPUT
#define Rows_PINS_Dir DIO_INPUT


#define Cols_PORT DIO_PORTD

#define Col_1_PIN  PIN_0
#define Col_2_PIN  PIN_1
#define Col_3_PIN  PIN_2
#define Col_4_PIN  PIN_3

#define Start_PIN_Cols 0
#define Stop_PIN_Cols  3




#define Rows_PORT DIO_PORTD

#define Row_1_PIN  PIN_4
#define Row_2_PIN  PIN_5
#define Row_3_PIN  PIN_6
#define Row_4_PIN  PIN_7


#define Start_PIN_Rows 4
#define Stop_PIN_Row   7


#endif /* HAL_HKEYPAD_KEYPAD_CFG_H_ */
