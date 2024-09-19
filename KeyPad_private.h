/*
 * KeyPad_private.h
 *
 *  Created on: 8 Sep 2024
 *      Author: User
 */

#ifndef HAL_HKEYPAD_KEYPAD_PRIVATE_H_
#define HAL_HKEYPAD_KEYPAD_PRIVATE_H_


u8 R_u8AssignKeyPad [4][4] = {
		{
				'7' ,  /** Row 0 Col 0**/
				'4' ,  /** Row 1 Col 0**/
				'1' ,
				'D'
		}
		,
		{
				'8' ,  // Row 0 Col 1
				'5' ,  // Row 1 Col 1
				'2' ,
				'0'
		}
		,
		{
				'9' ,  // Row 0 Col 2
				'6' ,  // Row 1 Col 2
				'3' ,
				'='
		}
		,
		{
				'/' ,  // Row 0 Col 3
				'*' ,  // Row 1 Col 3
				'-' ,
				'+'
		}
};


#endif /* HAL_HKEYPAD_KEYPAD_PRIVATE_H_ */
