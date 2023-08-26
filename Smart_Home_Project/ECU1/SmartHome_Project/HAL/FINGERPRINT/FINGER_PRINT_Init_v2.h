/*
 * FINGER_PRINT_Init.h
 *
 *  Created on: Mar 12, 2023
 *      Author: Dell
 */

#ifndef HAL_FINGER_PRINT_FINGER_PRINT_INIT_H_
#define HAL_FINGER_PRINT_FINGER_PRINT_INIT_H_

#include"STD_TYPES.h"
#include"FINGER_PRINT_Types.h"
void Finger_Print_Init(void);

void Finger_Print_Send_Led_Command(u8 *Ptr_Package);

void Finger_Print_Send_Command(u8 *Ptr_Package,u8 Package_Length );

Error_States_FB Finger_Print_Enroll(u8 FB_ID);
u8 Finger_Print_Match(void);

GEN_Image Generate_Image(void);
Image2Tz  Char_File_Generate(u8 Buffer_ID);
REG_MODEL Generate_Template(void);
STORE_TEMP Store_Template(u8 Page_ID);
SEARCH_TEMP Search_For_Template(u8 *Page_ID);
//void Finger_Print_Delete_Template(u8 FB_ID);
void Finger_Print_Empty_Templates(void);
void Flush_Buffer(void);

//void FINGER_PRINT_LIGHT(u8 Light_Status);
void Check_Sum(u8 FB_ID);
void Config_Led(u8 CTRL, u8 LED_COLOR, u8 Speed, u8 Counts);
#endif /* HAL_FINGER_PRINT_FINGER_PRINT_INIT_H_ */
