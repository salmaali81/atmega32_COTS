/***********************************************************/
/***********************************************************/
/***************      Author: Salma ALi      ***************/
/***************      Layer: HAL          	 ***************/
/***************      SWC: SSD               ***************/
/***************      Version: 1.00          ***************/

#ifndef SSD_INTERFACE_H_ 
#define SSD_INTERFACE_H_

#define COM_CATHODE 	0
#define COM_ANODE		1






struct SSD_N{
	u8 SSD_COMTYPE;
	u8 SSD_u8CopyPort;
	u8 SSD_EN_u8CopyPort;
	u8 SSD_EN_u8CopyPin;	
};

u8 SSD_u8SetNum(u8 SSD_u8CopyNum, struct SSD_N* SSD);


#endif