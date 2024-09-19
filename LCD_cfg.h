/*
 * LCD_cfg.h
 *
 *  Created on: 6 Sep 2024
 *      Author: User
 */

#ifndef HAL_HLCD_LCD_CFG_H_
#define HAL_HLCD_LCD_CFG_H_


#define LCD_RS_PORT DIO_PORTB
#define LCD_RS_PIN  PIN_0


#define LCD_RW_PORT DIO_PORTB
#define LCD_RW_PIN  PIN_1

#define LCD_E_PORT  DIO_PORTB
#define LCD_E_PIN   PIN_2

#define LCD_Command_PORT DIO_PORTA

#define Max_Number_Of_Digit  50


#define MODE 8

#endif /* HAL_HLCD_LCD_CFG_H_ */
