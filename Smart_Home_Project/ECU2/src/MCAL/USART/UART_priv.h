/*
 * UART_priv.h
 *
 * Created: 3/4/2023 8:55:41 AM
 *  Author: ahmed57
 */ 


#ifndef UART_PRIV_H_
#define UART_PRIV_H_

//#include "Mcu_HW.h"
#include "STD_TYPES.h"

/* UART */

#define UART_UDR_REG	(*((volatile u8*)0x2C))
#define UART_UCSRA_REG	(*((volatile u8*)0x2B))
#define UART_UCSRB_REG	(*((volatile u8*)0x2A))
#define UART_UBRRL_REG	(*((volatile u8*)0x29))
#define UART_UCSRC_REG	(*((volatile u8*)0x40))
#define UART_UBRRH_REG	(*((volatile u8*)0x40))


/* Bit field of UDR REG */
typedef struct{

	volatile u8 UDR_REG	  : 8;

}UART_UDR;


volatile static UART_UDR *PtrUDR = ((volatile UART_UDR *)0x2C);


/* Bit field of UCSRA REG */
typedef struct{

	volatile u8 MPCM_BIT  : 1;
	volatile u8 U2X_BIT	  : 1;
	volatile u8 PE_BIT	  : 1;
	volatile u8 DOR_BIT	  : 1;
	volatile u8 FE_BIT	  : 1;
	volatile u8 UDRE_BIT  : 1;
	volatile u8 TXC_BIT	  : 1;
	volatile u8 RXC_BIT	  : 1;
	
}UART_UCSRA;


volatile static UART_UCSRA *PtrUCSRA = ((volatile UART_UCSRA *)0x2B);


/* Bit field of UCSRB REG */
typedef struct{

	volatile u8 TXB8_BIT      : 1;
	volatile u8 RXB8_BIT	  : 1;
	volatile u8 UCSZ2_BIT	  : 1;
	volatile u8 TXEN_BIT	  : 1;
	volatile u8 RXEN_BIT	  : 1;
	volatile u8 UDRIE_BIT     : 1;
	volatile u8 TXCIE_BIT	  : 1;
	volatile u8 RXCIE_BIT	  : 1;
	
}UART_UCSRB;


volatile static UART_UCSRB *PtrUCSRB = ((volatile UART_UCSRB *)0x2A);



/* Bit field of UCSRA REG */
typedef struct{

	volatile u8 UCPOL_BIT			: 1;
	volatile u8 UCSZ_BIT			: 2;
	volatile u8 USBS_BIT			: 1;
	volatile u8 UPM_BIT  			: 2;
	volatile u8 UMSEL_BIT			: 1;
	volatile u8 URSEL_BIT_UCSRC     : 1;

	
}UART_UCSRC;


volatile static UART_UCSRC *PtrUCSRC = ((volatile UART_UCSRC *)0x40);


/* USART Baud Rate Registers –
   UBRRL and UBRRH */
typedef struct{

	volatile u8 UBRRH_BIT        : 4 ;
	volatile u8 	             : 3;
	volatile u8 URSEL_BIT_UBRRH    : 1;

}UART_UBRRH;


volatile static UART_UBRRH *PtrUBRRH = ((volatile UART_UBRRH *)0x40);



/* USART Baud Rate Registers –
   UBRRL and UBRRL */
typedef struct{

	volatile u8 UBRRL_BIT    : 8 ;

}UART_UBRRL;


volatile static UART_UBRRL *PtrUBRRL = ((volatile UART_UBRRL *)0x29);

#endif /* UART_PRIV_H_ */