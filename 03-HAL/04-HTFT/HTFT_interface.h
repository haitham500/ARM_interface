/**********************************************************************/
/* Author      : Haitham F. Hamdy                                     */
/* Date        : 08 Aug. 2022                                          */
/* Version     : V01                                                  */
/**********************************************************************/


#ifndef  HTFT_INTERFACE_H
#define  HTFT_INTERFACE_H


// ST7735 ROUTINES
#define SWRESET 0x01 // software reset
#define SLPOUT 0x11 // sleep out
#define DISPOFF 0x28 // display off
#define DISPON 0x29 // display on
#define CASET 0x2A // column address set
#define RASET 0x2B // row address set
#define RAMWR 0x2C // RAM write
#define MADCTL 0x36 // axis control
#define COLMOD 0x3A // color mode
// 1.8" TFT display constants
#define XSIZE 128
#define YSIZE 160
#define XMAX XSIZE-1
#define YMAX YSIZE-1
// Color constants
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x0400
#define LIME 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

void HTFT_voidInit ( void ) ;
void HTFT_voidFillImage ( const u16 * HTFT_ptrImage );
void HTFT_voidFillColor ( u16 HTFT_u16Color );
void HTFT_voidDrawHLine ( u8 Xaxis , u8 Yaxis , u8 HTFT_u8Length , u16 HTFT_u8Color );
void HTFT_voidDrawVLine ( u8 Xaxis , u8 Yaxis , u8 HTFT_u8Length , u16 HTFT_u8Color );
void HTFT_voidDrawRectangle ( u8 HTFT_u8Height , u8 HTFT_u8Width , u8 Xaxis , u8 Yaxis , u16 HTFT_u8Color );
void HTFT_voidWriteChar( u8 * HTFT_u8Char , u8 Xaxis , u8 Yaxis , u16 HTFT_u8Color );






#endif
