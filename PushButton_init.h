/*
 * PushButton_init.h
 *
 *  Created on: 5 Sep 2024
 *      Author: User
 */

#ifndef HAL_HPUSHBUTTON_PUSHBUTTON_INIT_H_
#define HAL_HPUSHBUTTON_PUSHBUTTON_INIT_H_


#define PB_1 1
#define PB_2 2
#define PB_3 3

#define NOT_PRESSED 1 // as pull up 0 for pull down
#define PRESSED     0


void  HPushButton_voidInit     (u8 A_u8PbID);
u8    HPushButton_u8ReadState  (u8 A_u8PbID);



#endif /* HAL_HPUSHBUTTON_PUSHBUTTON_INIT_H_ */
