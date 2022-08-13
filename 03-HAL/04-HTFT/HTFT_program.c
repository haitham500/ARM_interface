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

#include " HTFT_interface.h"
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

////////////////

void HTFT_voidFillColor ( u16 HTFT_u16Color )
{
	u8 LOC_u8CountX ;
	u8 LOC_u8CountY ;

	for( LOC_u8CountY = 0 ; LOC_u8CountY < 160 ; LOC_u8CountY++ )
	{
		HTFT_voidWriteCommand( CASET        ) ; // set column range (x0,x1)
		HTFT_voidWriteData   ( 0            ) ;
		HTFT_voidWriteData   ( 0            ) ;
		HTFT_voidWriteCommand( RASET        ) ; // set row range (y0,y1)
		HTFT_voidWriteData   ( 0            ) ;
		HTFT_voidWriteData   ( LOC_u8CountY ) ;

		HTFT_voidWriteCommand( RAMWR        ); // memory write

		for ( LOC_u8CountX = 0 ; LOC_u8CountX < 128 ; LOC_u8CountX++ )
		{
			HTFT_voidWriteData ( HTFT_u16Color >> 8   ) ; // write hi byte
			HTFT_voidWriteData ( HTFT_u16Color & 0xFF ) ; // write lo byte

		}
	}

}
//////////////////

void HTFT_voidDrawHLine ( u8 Xaxis , u8 Yaxis , u8 HTFT_u8Length , u16 HTFT_u8Color )
{
	for ( ; HTFT_u8Length > 0 ; HTFT_u8Length-- ){

		HTFT_voidWriteCommand( CASET ); // set column range (x0,x1)

		HTFT_voidWriteData   ( Xaxis );
		HTFT_voidWriteData   ( Xaxis );

		HTFT_voidWriteCommand( RASET ); // set row range (y0,y1)

		HTFT_voidWriteData   ( Yaxis );
		HTFT_voidWriteData   ( Yaxis );

		HTFT_voidWriteCommand( RAMWR ); // memory write

		HTFT_voidWriteData ( HTFT_u8Color >> 8   ); // write hi byte
		HTFT_voidWriteData ( HTFT_u8Color & 0xFF ); // write lo byte

		Xaxis++;

	}

}

void HTFT_voidDrawVLine ( u8 Xaxis , u8 Yaxis , u8 HTFT_u8Length , u16 HTFT_u8Color )
{
	for ( ; HTFT_u8Length > 0 ; HTFT_u8Length-- ){

		HTFT_voidWriteCommand( CASET ); // set column range (x0,x1)

		HTFT_voidWriteData   ( Xaxis );
		HTFT_voidWriteData   ( Xaxis );

		HTFT_voidWriteCommand( RASET ); // set row range (y0,y1)

		HTFT_voidWriteData   ( Yaxis );
		HTFT_voidWriteData   ( Yaxis );

		HTFT_voidWriteCommand( RAMWR ); // memory write

		HTFT_voidWriteData ( HTFT_u8Color >> 8   ); // write hi byte
		HTFT_voidWriteData ( HTFT_u8Color & 0xFF ); // write lo byte

		Yaxis++;

	}

}

void HTFT_voidDrawRectangle ( u8 HTFT_u8Height , u8 HTFT_u8Width , u8 Xaxis , u8 Yaxis , u16 HTFT_u8Color )
{
 HTFT_voidDrawHLine ( Xaxis , Yaxis , HTFT_u8Width  , HTFT_u8Color                 );
 HTFT_voidDrawVLine ( Xaxis , Yaxis , HTFT_u8Height , HTFT_u8Color                 );
 HTFT_voidDrawHLine ( Xaxis , HTFT_u8Height + Yaxis , HTFT_u8Width  , HTFT_u8Color );
 HTFT_voidDrawVLine ( HTFT_u8Width + Xaxis , Yaxis , HTFT_u8Height , HTFT_u8Color  );

}

void HTFT_voidWriteChar( u8 * HTFT_u8Char , u8 Xaxis , u8 Yaxis , u16 HTFT_u8Color )
{
	u8  LOC_u8Mask = 0x01 ;
	u8  LOC_u8DataMasked  ;
	u16 LOC_u8Pixel       ;

	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 5 ; LOC_u8Iterator1++ ){

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 7 ; LOC_u8Iterator2++ ){

			/* Set The Position Of 5x7 Character */
			HTFT_voidWriteCommand( CASET ); // set column range (x0,x1)

			HTFT_voidWriteData( Xaxis +  LOC_u8Iterator1 );
			HTFT_voidWriteData( Xaxis +  LOC_u8Iterator1 );

			HTFT_voidWriteCommand( RASET ); // set row range (y0,y1)

			HTFT_voidWriteData( Yaxis +  LOC_u8Iterator2 );
			HTFT_voidWriteData( Yaxis +  LOC_u8Iterator2 );

			HTFT_voidWriteCommand( RAMWR ); // memory write

			LOC_u8DataMasked = HTFT_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000       ; }
			else                         { LOC_u8Pixel = HTFT_u8Color ; }

			HTFT_voidWriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			HTFT_voidWriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask <<= 1 ;

		}

		LOC_u8Mask = 0x01 ;

	}

}
