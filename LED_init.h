/*
 * LED_init.h
 *
 *  Created on: 3 Sep 2024
 *      Author: User
 */

#ifndef HAL_HLED_LED_INIT_H_
#define HAL_HLED_LED_INIT_H_

#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7
#define LED_8 8

void HLED_voidLEDInit(u8 A_u8LEDNum);
void HLED_voidLEDON  (u8 A_u8LEDNum);
void HLED_voidLEDOFF (u8 A_u8LEDNum);
void HLED_voidLEDTog (u8 A_u8LEDNum);
#endif /* HAL_HLED_LED_INIT_H_ */
