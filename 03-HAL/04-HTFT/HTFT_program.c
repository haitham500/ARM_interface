/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 08 Aug. 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MSPI_interface.h"

#include "HTFT_interface.h"
#include "HTFT_private.h"
#include "HTFT_config.h"


static void HTFT_voidWriteCommand ( u8 HTFT_u8Command )
{
  //pin A0 in TFT diplay are used to control type of signal which is passing through
  //pin SDA which is used to communicate as MOSI pin in SPI protocol
  //if A0->1 then SDA->DATA , and if A0->0 then SDA-> command
  //A0 ----> HTFT_DataCommand_PORT_PIN
  MGPIO_voidSetPinValue ( HTFT_DataCommand_PORT_PIN , MGPIO_LOW);
  MSPI_voidSendCharSynch( HTFT_u8Command);

}

static void HTFT_voidWriteData ( u8 HTFT_u8Data )
{
  //pin A0 in TFT diplay are used to control type of signal which is passing through
  //pin SDA which is used to communicate as MOSI pin in SPI protocol
  //if A0->1 then SDA->DATA , and if A0->0 then SDA-> command
  //A0 ----> HTFT_DataCommand_PORT_PIN
  MGPIO_voidSetPinValue ( HTFT_DataCommand_PORT_PIN , MGPIO_HIGH);
  MSPI_voidSendCharSynch( HTFT_u8Data);


}

void HTFT_voidInit ( void )
 {
  /* Reset Puls To Initializing All registers*/
  //RESET pin in TFT display ---->HTFT_Reset_Port_Pin
  MGPIO_voidSetPinValue( HTFTResetPortPin , MGPIO_LOW );
  MSTK_voidDelay(1000);
  MGPIO_voidSetPinValue( HTFTResetPortPin , MGPIO_HIGH );
  MSTK_voidDelay(150000);

  HTFT_voidWriteCommand( SLPOUT ) ;   // take display out of sleep mode
  MSTK_voidDelay       ( 150000 ) ;   // wait 150mS for TFT driver circuits


  HTFT_voidWriteCommand( COLMOD ) ;   // select color mode:
  HTFT_voidWriteData   ( 0x05   ) ;   // mode 5 = 16bit pixels (RGB565)


  HTFT_voidWriteCommand( DISPON ) ;   // turn display on!
  MSTK_voidDelay   ( 1000 );

  	/* Remap TFT addresses ( x = 0 , y = 0 Start From The Left Top Of The TFT ) */
    //so we change the zero point of cordination to (x=127,y=159) look at page67
    //of datasheet 9.11.1 When 128RGBx160 (GM= “11”)
  HTFT_voidWriteCommand( MADCTL );
  HTFT_voidWriteData   ( 0xC0 );
}

//we use (const) word to save image in flash memory as temporary solution for
//training
void HTFT_voidFillImage ( const u16 * HTFT_ptrImage )
{

	u8 LOC_u8CountX ;
	u8 LOC_u8CountY ;
	u16 LOC_u8Data  ;

	for( LOC_u8CountY  = 0 ; LOC_u8CountY  < 160 ; LOC_u8CountY ++ )
	{
		HTFT_voidWriteCommand( CASET         ) ; // set column range (x0,x1)
		HTFT_voidWriteData   ( 0             ) ;
		HTFT_voidWriteData   ( 0             ) ;
		HTFT_voidWriteCommand( RASET         ) ; // set row range (y0,y1)
		HTFT_voidWriteData   ( 0             ) ;
		HTFT_voidWriteData   ( LOC_u8CountY  ) ;

		HTFT_voidWriteCommand( RAMWR         ) ; // memory write

		for ( LOC_u8CountX = 0 ; LOC_u8CountX < 128 ; LOC_u8CountX++ )
		{
			/* Get Pixel To Send */
			LOC_u8Data = *HTFT_ptrImage ;

			HTFT_voidWriteData ( LOC_u8Data >> 8   ); // write high byte
			HTFT_voidWriteData ( LOC_u8Data & 0xFF ); // write low byte

			/* Move to next Pixel */
			HTFT_ptrImage ++;

		}
	}

}
