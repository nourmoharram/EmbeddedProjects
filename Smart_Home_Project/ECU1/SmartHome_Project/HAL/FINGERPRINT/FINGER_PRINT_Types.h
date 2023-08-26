/*
 * FINGER_PRINT_Types.h
 *
 *  Created on: Mar 12, 2023
 *      Author: Dell
 */

#ifndef HAL_FINGER_PRINT_FINGER_PRINT_TYPES_H_
#define HAL_FINGER_PRINT_FINGER_PRINT_TYPES_H_



typedef enum
{
	No_Error,
	Enrollement_Done,
	Match_Done,
	Error_Enrollement,
	Error_Match,
}Error_States_FB;

typedef enum
{
	Finger_Collection_Success=0x00,
	Error_When_Receiving_Package_Gen=0x01,
	Can_not_detect_finger=0x02,
	fail_to_collect_finger=0x03,
}GEN_Image;


typedef enum
{
	Generate_character_file_complete=0x00,
	Error_When_Receiving_Package_Img=0x01,
	Over_disorder_FP=0x06,
	Lackness_char_point=0x07,
	Lackness_valid_primary_image=0x15
}Image2Tz;

typedef enum
{
	Operation_Sucess=0x00,
	Error_When_Receiving_Package_Reg=0x01,
	Failed_to_combine_chars=0x0A,
}REG_MODEL;

typedef enum
{
	Storage_Success=0x00,
	Error_When_Receiving_Package_Store=0x01,
	Addressing_pageID_beyond_lib=0x0B,
	Error_when_writing_flash=0x18,
}STORE_TEMP;

typedef enum
{
	Found_matching_finger=0x00,
	Error_When_Receiving_Package_Search=0x01,
	No_matching_in_lib=0x09,
}SEARCH_TEMP;

typedef enum
{
	Empty_success=0x00,
	Error_When_Receiving_Package_Empty=0x01,
	Fail_to_clear_Flibrary=0x11,
}EMPTY;

typedef enum
{
	Delete_Success=0x00,
	Error_When_Receiving_Package_Deletchar=0x01,
	Faile_to_delete_templates=0x10,
}DeletChar;

typedef enum
{
	Device_is_Normal=0x00,
}HandShake;

#endif /* HAL_FINGER_PRINT_FINGER_PRINT_TYPES_H_ */
