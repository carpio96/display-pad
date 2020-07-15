#ifndef _tactil_h_
#define _tactil_h_

#include "stdbool.h"
#include "lvgl.h"
#include "main.h"
#include "i2c.h"

//-------------------------------------macros
#define OBJ_I2C &hi2c2

#define EJE_X 0
#define EJE_Y 1

#define ADDRESS_TOUCHSCREEN 0x70
#define NOMBRE_MAXIM_TOUCH 5
#define NOMBRE_MAXIM_REGISTRES 31 // amb els 31 primers que pillen la tàctil anem sobrats
#define NOMBRE_MAXIM_DITS_REALS 1 // si vols més dits en el multitouch, canvia això

#define DIT_1 0 // son per a comoditat en arrays
#define DIT_2 1
#define DIT_3 2
#define DIT_4 3
#define DIT_5 4

// coses de dits
#define PUT_DOWN 0x00 // pg 33/49 datasheet
#define PUT_UP 0x40
#define CONTACT 0x80
#define RESERVED 0xC0

#define RESET_ON HAL_GPIO_WritePin(CTP_NRST_GPIO_Port, CTP_NRST_Pin, 0)
#define RESET_OFF HAL_GPIO_WritePin(CTP_NRST_GPIO_Port, CTP_NRST_Pin, 1)

#define SLEEP_TACTIL HAL_GPIO_WritePin(CTP_WAKE_GPIO_Port, CTP_WAKE_Pin, 0)
#define WAKE_TACTIL HAL_GPIO_WritePin(CTP_WAKE_GPIO_Port, CTP_WAKE_Pin, 1)

#define READ_PIN_INT() HAL_GPIO_ReadPin(CTP_NINT_GPIO_Port, CTP_NINT_Pin) // lo niego porque quiero un true cuando valga 0

//-------------------------------------registres FT56206
#define REG_DEVICE_MODE (0x00)
#define REG_GEST_ID (0x01)
#define REG_TD_STATUS (0x02)
#define REG_TOUCH1_XH (0x03)
#define REG_TOUCH2_XH (0x09)
#define REG_TOUCH3_XH (0x0F)
#define REG_TOUCH4_XH (0x15)
#define REG_TOUCH5_XH (0x1B)

//extern uint16_t array_touchScreen_dits[5][2];

void tactil_init(void);
void init_data_tactil_lvgl(void);
void tactil_get_coordenades(void);

extern bool my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

#endif
