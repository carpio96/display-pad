#include "lvgl.h"
#include "pantalla.h"

void Pantalla_init()
{
    LCD_READ_OFF; // no leeremos nada, lo dejamos apagado
    LCD_RESET;
    LCD_Write(COMMAND, CMD_OFF_DISPLAY); //display off

    // comandos init LCD
    LCD_Write(COMMAND, CMD_SET_PLL_MN); //PLL multiplier, set PLL clock to 120M
    LCD_Write(DATA, 0x1E);              //N=0x36 for 6.5M, 0x23 for 10M crystal
    LCD_Write(DATA, 0x02);
    LCD_Write(DATA, 0x54);

    LCD_Write(COMMAND, CMD_PLL_START); // PLL enable
    LCD_Write(DATA, 0x01);
    HAL_Delay(10);
    LCD_Write(COMMAND, CMD_PLL_START);
    LCD_Write(DATA, 0x03);
    HAL_Delay(10);

    LCD_Write(COMMAND, CMD_SOFT_RESET); // software reset
    HAL_Delay(100);
    LCD_Write(COMMAND, 0xE6); //PLL setting for PCLK, depends on resolution
    LCD_Write(DATA, 0x03);
    LCD_Write(DATA, 0xFF);
    LCD_Write(DATA, 0xFF);

    LCD_Write(COMMAND, CMD_SET_PANEL_MODE); //LCD SPECIFICATION
    LCD_Write(DATA, 0x20);
    LCD_Write(DATA, 0x00);
    LCD_Write(DATA, 0x03); //Set HDP	799
    LCD_Write(DATA, 0x1F);
    LCD_Write(DATA, 0x01); //Set VDP	479
    LCD_Write(DATA, 0xDF);
    LCD_Write(DATA, 0x00);

    LCD_Write(COMMAND, 0xB4); //HSYNC
    LCD_Write(DATA, 0x03);    //Set HT	928
    LCD_Write(DATA, 0xA0);
    LCD_Write(DATA, 0x00); //Set HPS	46
    LCD_Write(DATA, 0x2E);
    LCD_Write(DATA, 0x30); //Set HPW	48
    LCD_Write(DATA, 0x00); //Set LPS	15
    LCD_Write(DATA, 0x0F);
    LCD_Write(DATA, 0x00);

    LCD_Write(COMMAND, 0xB6); // VSYNC
    LCD_Write(DATA, 0x02);    // Set VT	525
    LCD_Write(DATA, 0x0D);
    LCD_Write(DATA, 0x00); // Set VPS	16
    LCD_Write(DATA, 0x10);
    LCD_Write(DATA, 0x10); // Set VPW	16
    LCD_Write(DATA, 0x00); // Set FPS	8
    LCD_Write(DATA, 0x08);

    LCD_Write(COMMAND, 0x36); //rotation
    LCD_Write(DATA, 0x08);    //RGB=BGR

    LCD_Write(COMMAND, CMD_SET_DATA_INTERFACE); //pixel data interface
    LCD_Write(DATA, 3);                         // modo color 16 bits, 565 ( R,G,B )

    HAL_Delay(1);

    //LCD_Fill(0, 0, 800, 480, 0xFFFF); // netejem la pantalla
    LCD_SetBacklight(255);
    LCD_Write(COMMAND, CMD_ON_DISPLAY); //display on
}

void LCD_Write(uint8_t D_C, uint16_t dada)
{
    LCD_DC(D_C); // DATA, COMMAND
    LCD_CS_LOW;
    LCD_DATA_WRITE(dada);
    LCD_WRITE_ON;
    LCD_WRITE_OFF;
    LCD_CS_HIGH;
}

void LCD_SetBacklight(uint8_t intensity)
{
    LCD_Write(COMMAND, CMD_SET_PWM_CONF); // Set PWM configuration for backlight control
    LCD_Write(DATA, 0x0E);                // PWMF[7:0] = 14, PWM base freq = PLL/(256*(1+14))/256 = 122Hz for a PLL freq = 120MHz
    LCD_Write(DATA, intensity);           //, abans intensity.    Set duty cycle, from 0x00 (total pull-down) to 0xFF

    // (99% pull-up , 255/256)
    LCD_Write(DATA, 0x01); // PWM enable, controlat pel DBC
    LCD_Write(DATA, 0x00); // manual brightness
    LCD_Write(DATA, 0x00); // minim nivell de llum
    LCD_Write(DATA, 0x00); // divisor de llum

    LCD_Write(COMMAND, 0xd0); // algo d'un modo dinàmic
    LCD_Write(DATA, 0x0d);
}

void LCD_Fill(uint16_t start_x, uint16_t start_y, uint16_t ample, uint16_t alt, uint16_t color)
{
    LCD_donarTamany(start_x, start_y, ample, alt);

    LCD_Write(COMMAND, CMD_WR_MEMSTART);

    for (uint32_t i = 0; i < (ample * alt); i++)
    {
        LCD_Write(DATA, color);
    }
}

void LCD_PintarImatge(uint16_t start_x, uint16_t start_y, uint16_t tamany_x, uint16_t tamany_y, uint16_t *color)
{
    LCD_donarTamany(start_x, start_y, tamany_x, tamany_y);
    LCD_Write(COMMAND, CMD_WR_MEMSTART);

    for (uint32_t i = 0; i < (tamany_x * tamany_y); i++)
    {
        LCD_Write(DATA, color[i]);
    }
}

void LCD_donarTamany(uint16_t start_x, uint16_t start_y, uint16_t ample, uint16_t alt)
{
    ample = ((start_x + ample) - 1);
    alt = ((start_y + alt) - 1);

    LCD_Write(COMMAND, CMD_SET_COLUMN);
    LCD_Write(DATA, start_x >> 8);
    LCD_Write(DATA, start_x);
    LCD_Write(DATA, ample >> 8);
    LCD_Write(DATA, ample);

    LCD_Write(COMMAND, CMD_SET_PAGE);
    LCD_Write(DATA, start_y >> 8);
    LCD_Write(DATA, start_y);
    LCD_Write(DATA, alt >> 8);
    LCD_Write(DATA, alt);
}
