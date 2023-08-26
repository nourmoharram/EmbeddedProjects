/*
 * system_init.c
 *
 *  Created on: Mar 16, 2023
 *      Author: ahmed
 */

/******************************************
  INCLUDES
*******************************************/
#define F_CPU 16000000UL
#include "system_init_cfg.h"
#include "Port_int.h"
#include "APP_int.h"


/* Port Config Extern */
extern const Port_ConfigType PORT_Config_Arr[];

/* UART Config Extern */
extern const UART_Config_t UART_CONFIG2;

/* External Interrupt Config */
extern EXTI_CONFIG_t EXTI_INT_ArrConfig[EXTI_INT_ArrConfig_Size];

System_cfg_t system_cfg = {PORT_Config_Arr};
	
	
ES_t sytem_init(){
	/* Initialize all Required Ports and Pins */
		//Port_Init(copy_system_cfg.port_cfg,20);
		Port_Init(PORT_Config_Arr , 21);

		
		/* LCD Initialization */
		H_LCD_void_Init();

		/* Global interrupt Initialization */
		M_vEnable_Global_Interrupts();

		/* UART Initialization */
		UART_Init(UART_CONFIG2);

		/* Timer0 Init */
		M_vTIMER0_Init( TIMER0_PWM_PhaseCorrect_MODE,  TIMER0_PWM_PHASECORRECT_NonInverted_MODE);
		
		/* Timer1 Init */
		M_TIMER1_void_Init(Timer_1_Fast_PWM, TIMER_1_NonINV );

		
		M_vEXTI_INT_Enable(EXTI_INT_ArrConfig);
		M_vEXTI_SetCallBack(ECU1_Login_Sucsess_Signal, EXTI_INT0);
		
		/* Wifi Init and Connect */
		

}


void ECU1_Login_Sucsess_Signal()
{
	Login_Sucsess_Flag = 1;
}


void Check_Login_Sucsess()
{
	Login_Sucsess_Flag =0;
	Logout_Request_Flag =1;
	H_LCD_void_sendString("Wait User Login");
	while(1)
	{
		
		//H_LCD_void_gotoXY(1,0);
		
		//_delay_ms(2000);		
		if (Login_Sucsess_Flag == 1)
		{
			H_LCD_void_Clear_Display();
			_delay_ms(200);
			H_LCD_void_sendString("welcome Home");
			_delay_ms(1000);
			H_LCD_void_Clear_Display();
			
			_delay_ms(200);
			wifi_connect();
			_delay_ms(200);
			
			Show_Menu_Wifi();
			H_LCD_void_Clear_Display();
			_delay_ms(200);
			break;
		}

		
	}
}

void Logout_Request_Handler()
{
	if(Logout_Request_Flag == Logout_Requested)
	{
		Login_Sucsess_Flag = 0;
		H_LCD_void_Clear_Display();
		_delay_ms(200);
		H_LCD_void_sendString(" System Logout Requested... ");
		_delay_ms(3000);
		H_LCD_void_Clear_Display();
		UART_sendString("AT+CIPCLOSE=1\r\n");
		H_LCD_void_sendString(" Wifi Closed ... ");
		_delay_ms(3000);
		H_LCD_void_Clear_Display();
		_delay_ms(200);
		
		Motor_State_Flag = 0;
		LED_State_Flag =0;
		MOTOR_ON(MOTOR_CW , 0);
		M_TIMER1_void_Stop();
		Check_Login_Sucsess();
		
	}
	
}