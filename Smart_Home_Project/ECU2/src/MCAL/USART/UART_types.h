/*
 * UART_types.h
 *
 * Created: 3/4/2023 8:56:02 AM
 *  Author: ahmed57
 */ 


#ifndef UART_TYPES_H_
#define UART_TYPES_H_

typedef enum{
	Disable,
	Enable
}UART_STATE;

typedef enum{
	Asynchronous,
	Synchronous
}UART_Mode_Select;

typedef enum{
	Disabled = 0b00,
	Reserved = 0b01,
	Even_Parity = 0b10,
	Odd_Parity = 0b11

}UART_Parity_Mode_Select;

typedef enum{
	Stop_1BIT = 0,
	Stop_2BIT = 1,

}UART_Stop_Bit_Select;


typedef enum{
	Word_Size_5BIT = 0b00,
	Word_Size_6BIT = 0b01,
	Word_Size_7BIT = 0b10,
	Word_Size_8BIT	= 0b11,
	Word_Size_9BIT = 0b11
}UART_Word_Size;



typedef enum{
	TX_RISING_RX_FALLING = 0,
	TX_FALLING_RX_RISING = 1,

}UART_Clk_Polarity_Select;


typedef enum{
	UBRRH_Select = 0,
	UCSRC_Select = 1,

}UART_URSEL_Register_Select;


typedef enum{
	Baud_9600= 103,
	Baud_57k= 16,
	Baud_115K= 8,
	
}UART_BaudeRate_Select_t;

#endif /* UART_TYPES_H_ */