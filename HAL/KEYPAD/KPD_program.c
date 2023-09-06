/***********************************************************/
/***********************************************************/
/***************      Author: Salma ALi      ***************/
/***************      Layer: HAL             ***************/
/***************      SWC: KEYPAD            ***************/
/***************      Version: 1.00          ***************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"



u8 KPD_u8GetPressedKey()
{
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY, Local_u8ColumnIndx, Local_u8RowIndx;
	u8 Local_u8PinState = 0xff;
	static u8 Local_u8PressedArr[ROWS_NUM][COLUMNS_NUM] = KPD_Arr_VAL;
	static u8 Local_u8KPDColumnArr[COLUMNS_NUM] = {KPD_COLUMN0_PIN	, KPD_COLUMN1_PIN,	KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	static u8 Local_u8KPDROWArr[ROWS_NUM] ={KPD_ROW0_PIN,  KPD_ROW1_PIN,  KPD_ROW2_PIN,  KPD_ROW3_PIN};
	
	for (Local_u8ColumnIndx = 0; Local_u8ColumnIndx<COLUMNS_NUM; Local_u8ColumnIndx++)
	{
		
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndx], DIO_u8PIN_LOW);
		for (Local_u8RowIndx = 0; Local_u8RowIndx<ROWS_NUM; Local_u8RowIndx++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPD_PORT, Local_u8KPDROWArr[Local_u8RowIndx], &Local_u8PinState);
			
			/*check if switch is pressed*/	
			if( DIO_u8PIN_LOW == Local_u8PinState  )
			{
				Local_u8PressedKey = Local_u8PressedArr[Local_u8RowIndx][Local_u8ColumnIndx];
				/*Polling(busy waiting until the key is release)*/
				while( DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT, Local_u8KPDROWArr[Local_u8RowIndx], &Local_u8PinState);
				}
				
				return Local_u8PressedKey;
			}
			
		}
		/*Deactivate current column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndx], DIO_u8PIN_HIGH);
	}
	  
	return Local_u8PressedKey;
}