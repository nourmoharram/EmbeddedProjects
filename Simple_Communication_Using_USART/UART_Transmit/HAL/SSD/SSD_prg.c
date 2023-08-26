/*
 * SSD_prg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

#include"STD_TYPES.h"
#include"DIO/Dio_int.h"
#include"SSD_priv.h"
#include"SSD_types.h"
#include"SSD_CFG.h"
#include"SSD_int.h"
#include<util/delay.h>

void H_SSD_void_displayIntNumber(u16 Copy_number)
{
	u8 arr[4]={0};
	u8 i=0;
	while(Copy_number >0 && i<4)
	{
		arr[i]= Copy_number %10;
		Copy_number /= 10;
		i++;
	}
	/*prepare units to be send to BCD(4bits)*/
	for(u8 j=0;j<SSD_DISPLAY_TIME*4;j++)
	{
		/*prepare units to be send to BCD*/
		i=0;
		M_Dio_void_setPinValue(SSD_A_PIN,(arr[i]>>0)&1);
		M_Dio_void_setPinValue(SSD_B_PIN,(arr[i]>>1)&1);
		M_Dio_void_setPinValue(SSD_C_PIN,(arr[i]>>2)&1);
		M_Dio_void_setPinValue(SSD_D_PIN,(arr[i]>>3)&1);
		/*Enable digit 1 (remember it is pnp - active low*/
		M_Dio_void_setPinValue(SSD_DIG1_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG1_EN,DIO_HIGH);
		/*prepare Tens to be send to BCD(4bits)*/
		i=1;
		M_Dio_void_setPinValue(SSD_A_PIN,(arr[i]>>0)&1);
		M_Dio_void_setPinValue(SSD_B_PIN,(arr[i]>>1)&1);
		M_Dio_void_setPinValue(SSD_C_PIN,(arr[i]>>2)&1);
		M_Dio_void_setPinValue(SSD_D_PIN,(arr[i]>>3)&1);
		/*Enable digit 2 (remember it is pnp - active low*/
		M_Dio_void_setPinValue(SSD_DIG2_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG2_EN,DIO_HIGH);
		/*prepare hundreds to be send to BCD*/
		i=2;
		M_Dio_void_setPinValue(SSD_A_PIN,(arr[i]>>0)&1);
		M_Dio_void_setPinValue(SSD_B_PIN,(arr[i]>>1)&1);
		M_Dio_void_setPinValue(SSD_C_PIN,(arr[i]>>2)&1);
		M_Dio_void_setPinValue(SSD_D_PIN,(arr[i]>>3)&1);
		/*Enable digit 2 (remember it is pnp - active low*/
		M_Dio_void_setPinValue(SSD_DIG3_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG3_EN,DIO_HIGH);
		/*prepare hundreds to be send to BCD*/
		i=3;
		M_Dio_void_setPinValue(SSD_A_PIN,(arr[i]>>0)&1);
		M_Dio_void_setPinValue(SSD_B_PIN,(arr[i]>>1)&1);
		M_Dio_void_setPinValue(SSD_C_PIN,(arr[i]>>2)&1);
		M_Dio_void_setPinValue(SSD_D_PIN,(arr[i]>>3)&1);
		/*Enable digit 2 (remember it is pnp - active low*/
		M_Dio_void_setPinValue(SSD_DIG4_EN,DIO_LOW);
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG4_EN,DIO_HIGH);

	}



}
