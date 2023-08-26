/*
 * Finger_Print_Program_v3.c
 *
 *  Created on: Mar 17, 2023
 *      Author: Dell
 */
/*
 * Finger_Print_Program_v2.c
 *
 *  Created on: Mar 17, 2023
 *      Author: Dell
 */
/*
 * FINGER_PRINT_Program.c
 *
 *  Created on: Mar 15, 2023
 *      Author: Dell
 */

#include"STD_TYPES.h"
#include"Port_int.h"
#include"USART_CONFIG.h"
#include"USART_Init.h"
#include"GIE_init.h"
#include"FINGER_PRINT_Private_v2.h"
#include"FINGER_PRINT_CONFIG.h"
#include"FINGER_PRINT_Types.h"
#include"FINGER_PRINT_Init_v2.h"
#include"CLCD_Init.h"
#include<util/delay.h>
void Display_data(void);
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
UART_CONFIG ARR_UART_CFG_3={Baud_16MHz_57600,Word_Size_8,Disabled,One_Stop_bit};
u8 Store[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x06,0x06,0x01,0x00,0x01,0x00,0x0F};
static u8 Buffer[30];
static u8 Local_counter=0;

static u8 Gen_Img_Flag=1;
static u8 Img_2_TZ_Flag=1;
static u8 Reg_Model_Flag=1;
static u8 Store_Flag=1;
static u8 Search_Flag=1;

static u8 Empty_Flag=0;

void Finger_Print_Init(void)
{
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	UART_Init(&ARR_UART_CFG_3);
	UART_SetCallBack(Display_data);
	M_GIE_Void_Enable();
	Config_Led(Flashing_light,Purple_led,LED_SPEED,LED_COUNTS);
	Config_Led(Light_always_on,Purple_led,LED_SPEED,LED_COUNTS);
	Flush_Buffer();
}

void Config_Led(u8 CTRL, u8 LED_COLOR, u8 Speed, u8 Counts)
{
	u8 Check_Sum_Value=0;
	u8 Counter=0;
	AuraLedConfig_LED[10]=CTRL;
	AuraLedConfig_LED[11]=Speed;
	AuraLedConfig_LED[12]=LED_COLOR;
	AuraLedConfig_LED[13]=Counts;
	for(Counter=Package_Identifier;Counter<AURA_LED_LENGTH-2;Counter++)
	{
		Check_Sum_Value+=AuraLedConfig_LED[Counter];
	}
	AuraLedConfig_LED[Check_Sum_Led_byte]=Check_Sum_Value;
	Finger_Print_Send_Led_Command(AuraLedConfig_LED);

}
/*
void FINGER_PRINT_LIGHT(u8 Light_Status)
{
	Finger_Print_Send_Command(AuraLedConfig_Purble,AURA_LED_LENGTH);
}
*/

void Finger_Print_Send_Led_Command(u8 *Ptr_Package)
{
	u8 counter=0;
	do
	{
		UART_SendByte(Ptr_Package[counter]);
		counter++;
		_delay_ms(50);
	}while(counter<AURA_LED_LENGTH);
}
void Finger_Print_Send_Command(u8 *Ptr_Package,u8 Package_Length )
{
	u8 counter=0;
	do
	{
		UART_SendByte(Ptr_Package[counter]);
		counter++;
		_delay_ms(50);
	}while(counter<Package_Length);
	_delay_ms(500);
}

Error_States_FB Finger_Print_Enroll(u8 FB_ID)
{
	Error_States_FB Status;
	GEN_Image Return_Status_Gen;
	Image2Tz Return_Status_Char;
	REG_MODEL Return_Status_RegModel;
	STORE_TEMP Return_Status_Store;
	//Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
	//Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
	Return_Status_Gen=Generate_Image();
	if(Return_Status_Gen==Finger_Collection_Success)
	{
		Return_Status_Char=Char_File_Generate(CharBuffer1);
		if(Return_Status_Char==Generate_character_file_complete)
		{
			Return_Status_Gen=Generate_Image();
			if(Return_Status_Gen==Finger_Collection_Success)
			{
				Return_Status_Char=Char_File_Generate(CharBuffer2);
				if(Return_Status_Char==Generate_character_file_complete)
				{
					Return_Status_RegModel=Generate_Template();
					if(Return_Status_RegModel==Operation_Sucess)
					{
						Return_Status_Store=Store_Template(FB_ID);
						if(Return_Status_Store==Storage_Success)
						{
							Status = No_Error;
						}
					}
				}
			}
		}
	}

	return Status;
}
u8 Finger_Print_Match(void)
{
	u8 User_ID;
	GEN_Image Return_Status_Gen;
	Image2Tz Return_Status_Char;
	SEARCH_TEMP Return_Status_Search;
//	Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
	//Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
	Return_Status_Gen=Generate_Image();
	if(Return_Status_Gen==Finger_Collection_Success)
	{
		Return_Status_Char=Char_File_Generate(CharBuffer1);
		if(Return_Status_Char==Generate_character_file_complete)
		{
			Return_Status_Search=Search_For_Template(&User_ID);
			if(Return_Status_Search==Found_matching_finger)
			{
				return User_ID;
			}
		}
	}
	return User_ID;
}
GEN_Image Generate_Image(void)
{
	GEN_Image Status;
	while(Gen_Img_Flag)
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Check Finger!");
		//_delay_ms(2000);
		Finger_Print_Send_Command(GetImage,GEN_IMAGE_LENGTH);
		if(Buffer[Confirmation_Code]==Finger_Collection_Success)
		{
				Status=Finger_Collection_Success;
				//H_LCD_void_ClearDisplay();
				//H_LCD_void_sendString("Check  done");
				//Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
				//Flush_Buffer();
				Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
				Flush_Buffer();
				return Status;
		}
		else if(Buffer[Confirmation_Code]==Error_When_Receiving_Package_Gen)
		{
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();

		}
		else if(Buffer[Confirmation_Code]==Can_not_detect_finger)
		{
		//	Flush_Buffer();
			H_LCD_void_ClearDisplay();
			//H_LCD_void_sendString("Check Finger again");
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
		}
		else
		{
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
		//	Flush_Buffer();

			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
		}
	}
	return Status;
}
Image2Tz  Char_File_Generate(u8 Buffer_ID)
{
	Image2Tz Status;
	while(Img_2_TZ_Flag)
	{
		if(Buffer_ID==CharBuffer1)
		{
			Finger_Print_Send_Command(Img2TZ_1,IMAGE_2TZ_1_LENGTH);
		}
		else if(Buffer_ID==CharBuffer2)
		{
			Finger_Print_Send_Command(Img2TZ_2,IMAGE_2TZ_2_LENGTH);
		}
		if(Buffer[Confirmation_Code]==Generate_character_file_complete)
		{
			Status = Generate_character_file_complete;
			//H_LCD_void_ClearDisplay();
			//H_LCD_void_sendString("Buffer done");
			//_delay_ms(1000);
			//Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
		//	Flush_Buffer();

			Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
			return Status;
		}
		else
		{
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
			//Flush_Buffer();

			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
			//_delay_ms(250);
		}
	}
	return Status;
}

REG_MODEL Generate_Template(void)
{
	REG_MODEL Status;
	while(Reg_Model_Flag)
	{
		Finger_Print_Send_Command(Reg_Model,REG_MODEL_LENGTH);
		if(Buffer[Confirmation_Code]==Operation_Sucess)
		{
			Status=Operation_Sucess;
			H_LCD_void_ClearDisplay();
			//H_LCD_void_sendString("Register Model done");
			H_LCD_void_sendString("PLS Wait :)");
			_delay_ms(1000);
			//Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
			//Flush_Buffer();

			Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
			return Status;
		}
		else
		{
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
			//Flush_Buffer();

			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
		}
	}

	return Status;
}
STORE_TEMP Store_Template(u8 Page_ID)
{
	STORE_TEMP Status;
	while(Store_Flag)
	{
		Check_Sum(Page_ID);
		Finger_Print_Send_Command(Store,STORE_LENGTH);
		H_LCD_void_sendIntNum(Buffer[Confirmation_Code]);
		if(Buffer[Confirmation_Code]==Storage_Success)
		{
			Status=Storage_Success;
			//H_LCD_void_ClearDisplay();
			//H_LCD_void_sendString("Storing done");
			//_delay_ms(1000);
			//Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
			//Flush_Buffer();

			Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
			return Status;
		}
		else
		{
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
			//Flush_Buffer();

			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();
		}
	}

	return Status;

}
SEARCH_TEMP Search_For_Template(u8 *Page_ID)
{
	SEARCH_TEMP Status;
	while(Search_Flag)
	{
		Finger_Print_Send_Command(Search,SEARCH_LENGTH);
		if(Buffer[Confirmation_Code]==Found_matching_finger)
		{
			Status=Found_matching_finger;
			//H_LCD_void_ClearDisplay();
			//H_LCD_void_sendString("FingerPrint Found");
			//_delay_ms(2000);

			*Page_ID=Buffer[PAGE_ID];
			//Config_Led(Flashing_light,Blue_led,LED_SPEED,LED_COUNTS);
			//Config_Led(Light_always_on,Blue_led,LED_SPEED,LED_COUNTS);
			//Flush_Buffer();
			//_delay_ms(1000);
			//_delay_ms(500);
			//Config_Led(Flashing_light,Purple_led,LED_SPEED,LED_COUNTS);
			Config_Led(Light_always_on,Purple_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();



			return Status;
		}
		else if(Buffer[Confirmation_Code]==No_matching_in_lib)
		{
			Status=No_matching_in_lib;
			//H_LCD_void_ClearDisplay();
			//H_LCD_void_sendString("No matching Found");
			*Page_ID=NO_USER_RETURN;
			//Flush_Buffer();
			//_delay_ms(1000);
			//_delay_ms(500);
			//Config_Led(Flashing_light,Red_led,LED_SPEED,LED_COUNTS);
			Config_Led(Light_always_on,Red_led,LED_SPEED,LED_COUNTS);
			Flush_Buffer();


			return Status;
		}
	}

	return Status;
}

void Finger_Print_Empty_Templates(void)
{
	Empty_Flag=1;
	while(Empty_Flag)
	{
		Finger_Print_Send_Command(Empty_Library,EMPTY_LIBRARY_LENGTH);
		if(Buffer[Confirmation_Code]==Empty_success)
		{
			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Template list empty");
			Flush_Buffer();
			_delay_ms(1000);
			Empty_Flag=0;
		}
		else
		{
			Flush_Buffer();
			_delay_ms(500);
		}
	}

}
void Flush_Buffer(void)
{
	Local_counter=0;
	for(u8 i=0;i<30;i++)
	{
		Buffer[i]=0xAA;
	}
}
void Check_Sum(u8 FB_ID)
{
	u8 Check_Sum_Value=0;
	u8 Counter=0;
	Store[PAGE_ID_STORE]=FB_ID;
	for(Counter=Package_Identifier;Counter<STORE_LENGTH-2;Counter++)
	{
		Check_Sum_Value+=Store[Counter];
	}
	Store[Check_Sum_byte]=Check_Sum_Value;
}

void Display_data(void)
{
	Buffer[Local_counter]=UART_RecieveByteASynchCallback();
	Local_counter++;
}
