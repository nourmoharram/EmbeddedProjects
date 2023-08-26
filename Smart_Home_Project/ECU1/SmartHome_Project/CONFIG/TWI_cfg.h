/*
 * TWI_cfg.h
 *
 *  Created on: Mar 8, 2023
 *      Author: LENOVO
 */

#ifndef TWI_CFG_H_
#define TWI_CFG_H_

/*
 * from :	SCL fre = CPU CLK freq / 16+ 2(TWBR)*4^TWPS
*/
#define TWI_TWBR_Defult_value 0x07
/*
 * Write the required SCL Frequency
 * */
#define TWI_SCL_FREQUENCY 400000


#endif /* TWI_CFG_H_ */
