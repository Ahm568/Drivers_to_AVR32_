/*
 * SevenSeg_init.h
 *
 *  Created on: 4 Sep 2024
 *      Author: User
 */

#ifndef HAL_HSEVENSEG_SEVENSEG_INIT_H_
#define HAL_HSEVENSEG_SEVENSEG_INIT_H_

#define NUM_0 0
#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_4 4
#define NUM_5 5
#define NUM_6 6
#define NUM_7 7
#define NUM_8 8
#define NUM_9 9

#define SEG_1_ID 1
#define SEG_2_ID 2

void HSevenSeg_voidSevenSegInit         (u8 A_u8SegID);
void HSevenSeg_voidSevenSegON           (u8 A_u8SegID);
void HSevenSeg_voidSevenSegDisplayNum   (u8 A_u8SegID , u8 A_u8NumToDisplay);
void HSevenSeg_voidSevenSegOFF           (u8 A_u8SegID);
#endif /* HAL_HSEVENSEG_SEVENSEG_INIT_H_ */
