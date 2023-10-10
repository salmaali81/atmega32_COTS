/***********************************************************/
/***********************************************************/
/***************      Author: Salma ALi      ***************/
/***************      Layer: MCAL            ***************/
/***************      SWC: DIO               ***************/
/***************      Version: 1.00          ***************/


//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/BIT_MATH.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

#include "SSD_interface.h"

u8 seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

u8 SSD_u8SetNum(u8 SSD_u8CopyNum, struct SSD_N* SSD){
	u8 Local_u8_ErrorState =0;
	DIO_u8SetPortDirection(SSD->SSD_u8CopyPort, DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(SSD->SSD_EN_u8CopyPort, DIO_u8PORT_OUTPUT);
	//DIO_u8SetPinDirection(SSD->SSD_EN_u8CopyPort, SSD->SSD_EN_u8CopyPin, DIO_u8PORT_OUTPUT);
	if(SSD->SSD_COMTYPE == COM_CATHODE)
	{
		DIO_u8SetPinValue(SSD->SSD_EN_u8CopyPort, SSD->SSD_EN_u8CopyPin, DIO_u8PIN_LOW );
		SSD_u8CopyNum = ~SSD_u8CopyNum;
		DIO_u8SetPortValue(SSD->SSD_u8CopyPort, seg[SSD_u8CopyNum]);
	}
	else if (SSD->SSD_COMTYPE == COM_ANODE)
	{
		DIO_u8SetPinValue(SSD->SSD_EN_u8CopyPort, SSD->SSD_EN_u8CopyPin, DIO_u8PIN_HIGH );
		DIO_u8SetPortValue(SSD->SSD_u8CopyPort, seg[SSD_u8CopyNum]);
	}
	
	return Local_u8_ErrorState;
}