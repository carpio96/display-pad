#ifndef _comandos_SSD1963_h_
#define _comandos_SSD1963_h_

// macros comandos
#define CMD_SOFT_RESET 0x01 /* Software reset */
#define CMD_OFF_DISPLAY 0x28
#define CMD_ON_DISPLAY 0x29
#define CMD_SET_COLUMN 0x2A
#define CMD_SET_PAGE 0x2B
#define CMD_WR_MEMSTART 0x2C
#define CMD_SET_PANEL_MODE 0xB0
#define CMD_SET_HOR_PERIOD 0xB4
#define CMD_SET_VER_PERIOD 0xB6
#define CMD_SET_PWM_CONF 0xBE
#define CMD_PLL_START 0xE0 /* start the PLL */
#define CMD_SET_PLL_MN 0xE2
#define CMD_SET_PCLK 0xE6 /* set pixel clock (LSHIFT signal) frequency */
#define CMD_SET_DATA_INTERFACE 0xF0

/*
	A[2:0] : Pixel Data Interface Format (POR = 101)
	000 8-bit
	001 12-bit
	010 16-bit packed
	011 16-bit (565 format)
	100 18-bit
	101 24-bit
	110 9-bit
	Others Reserved
*/

#define DISP_HOR_PULSE_WIDTH 20			/* 20 */
#define DISP_HOR_BACK_PORCH 51 /* 48 */ // abans 51
#define DISP_HOR_FRONT_PORCH 20			/* 20 */

#define DISP_VER_PULSE_WIDTH 2			/* 2 */
#define DISP_VER_BACK_PORCH 16 /* 16 */ // bans 12
#define DISP_VER_FRONT_PORCH 4			/* 4 */

#endif
