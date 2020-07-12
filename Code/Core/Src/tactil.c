#include "lvgl.h"
#include "tactil.h"

uint16_t array_dits[NOMBRE_MAXIM_TOUCH][2] = {0};
uint8_t reg_inici_touch[NOMBRE_MAXIM_TOUCH] = {REG_TOUCH1_XH, REG_TOUCH2_XH, REG_TOUCH3_XH, REG_TOUCH4_XH, REG_TOUCH5_XH};
uint8_t _maxTouch = NOMBRE_MAXIM_DITS_REALS;
uint8_t reg_touch[NOMBRE_MAXIM_REGISTRES] = {0};

lv_indev_drv_t indev_drv;

void tactil_init(void)
{
    HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, 0);

    RESET_OFF;
    WAKE_TACTIL;

    uint8_t temp[2] = {REG_DEVICE_MODE, 0};
    int err = HAL_I2C_Master_Transmit(OBJ_I2C, ADDRESS_TOUCHSCREEN, &temp, 2, 100);

    init_data_tactil_lvgl();
}

void init_data_tactil_lvgl(void)
{
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
}
void tactil_get_coordenades(void)
{
    // leemos los registros del panel táctil
    uint16_t err = HAL_I2C_Mem_Read(OBJ_I2C, ADDRESS_TOUCHSCREEN, REG_DEVICE_MODE, I2C_MEMADD_SIZE_8BIT, reg_touch, 31, 100);

    uint8_t touches = reg_touch[REG_TD_STATUS] & 0x0F;

    for (uint8_t i = 1; i <= touches; i++) // permite más de un dedo, solamente usaremos 1 para esto
    {
        array_dits[i - 1][EJE_X] = ((reg_touch[reg_inici_touch[i - 1]] & 0x0f) << 8) | reg_touch[reg_inici_touch[i - 1] + 1];
        array_dits[i - 1][EJE_Y] = ((reg_touch[reg_inici_touch[i - 1] + 2] & 0x0f) << 8) | reg_touch[reg_inici_touch[i - 1] + 3];

        if (i == _maxTouch)
        {
            touches = i; // si quieres saber cuántos dedos se pulsaron, devuelve touches
            break;
        }
    }
}

// capa abstracción LVGL
bool my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    if (READ_PIN_INT() == 0)
    {
        HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, 1);
        tactil_get_coordenades();
        data->point.x = array_dits[DIT_1][EJE_X];
        data->point.y = array_dits[DIT_1][EJE_Y];
        data->state = LV_INDEV_STATE_PR; // botón apretado
    }
    else
    {
        data->state = LV_INDEV_STATE_REL; // botón suelto
    }

    return false; /*Return `false` because we are not buffering and no more data to read*/
}
