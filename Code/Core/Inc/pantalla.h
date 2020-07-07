#ifndef pantalla_h
#define pantalla_h

#include "comandos_SSD1963.h"
#include "main.h"

// macros capa abstracción pines LCD
#define LCD_READ_OFF HAL_GPIO_WritePin(LCD_READ_GPIO_Port, LCD_READ_Pin, 1)
#define LCD_READ_ON HAL_GPIO_WritePin(LCD_READ_GPIO_Port, LCD_READ_Pin, 0)

#define LCD_WRITE_OFF HAL_GPIO_WritePin(LCD_WRITE_GPIO_Port, LCD_WRITE_Pin, 1)
#define LCD_WRITE_ON HAL_GPIO_WritePin(LCD_WRITE_GPIO_Port, LCD_WRITE_Pin, 0)

#define LCD_DC(_N) HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, _N)
#define DATA 1
#define COMMAND 0

#define LCD_CS_HIGH HAL_GPIO_WritePin(LCD_NCS_GPIO_Port, LCD_NCS_Pin, 1)
#define LCD_CS_LOW HAL_GPIO_WritePin(LCD_NCS_GPIO_Port, LCD_NCS_Pin, 0)

#define LCD_RESET_ON HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, 0)
#define LCD_RESET_OFF HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, 1)

#define LCD_RESET     \
	LCD_RESET_ON;     \
	HAL_Delay(10); \
	LCD_RESET_OFF // pulso de 10ms (pg 79/94)

#define LCD_DATA_WRITE(_N)                                                  \
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (0x01 & (_N >> 0)));    \
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (0x01 & (_N >> 1)));    \
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (0x01 & (_N >> 2)));    \
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (0x01 & (_N >> 3)));    \
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (0x01 & (_N >> 4)));    \
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (0x01 & (_N >> 5)));    \
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (0x01 & (_N >> 6)));    \
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (0x01 & (_N >> 7)));    \
	HAL_GPIO_WritePin(LCD_D8_GPIO_Port, LCD_D8_Pin, (0x01 & (_N >> 8)));    \
	HAL_GPIO_WritePin(LCD_D9_GPIO_Port, LCD_D9_Pin, (0x01 & (_N >> 9)));    \
	HAL_GPIO_WritePin(LCD_D10_GPIO_Port, LCD_D10_Pin, (0x01 & (_N >> 10))); \
	HAL_GPIO_WritePin(LCD_D11_GPIO_Port, LCD_D11_Pin, (0x01 & (_N >> 11))); \
	HAL_GPIO_WritePin(LCD_D12_GPIO_Port, LCD_D12_Pin, (0x01 & (_N >> 12))); \
	HAL_GPIO_WritePin(LCD_D13_GPIO_Port, LCD_D13_Pin, (0x01 & (_N >> 13))); \
	HAL_GPIO_WritePin(LCD_D14_GPIO_Port, LCD_D14_Pin, (0x01 & (_N >> 14))); \
	HAL_GPIO_WritePin(LCD_D15_GPIO_Port, LCD_D15_Pin, (0x01 & (_N >> 15)))

void Pantalla_init();
void LCD_Write(uint8_t D_C, uint16_t dada);
void LCD_SetBacklight(uint8_t intensity);
void LCD_Fill(uint16_t start_x, uint16_t start_y, uint16_t ample, uint16_t alt, uint16_t color);
void LCD_PintarImatge(uint16_t start_x, uint16_t start_y, uint16_t tamany_x, uint16_t tamany_y, uint16_t *color);
void LCD_donarTamany(uint16_t start_x, uint16_t start_y, uint16_t ample, uint16_t alt);

#endif
