/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"
#include "i2c.h"
#include "sdio.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lvgl.h"
#include "pantalla.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

static lv_disp_drv_t disp_drv;
static lv_obj_t *slider;
static lv_color_t buffer_1[LV_HOR_RES_MAX * 10];

bool my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) // falta implementar
{
  return false; /*Return `false` because we are not buffering and no more data to read*/
}

static void ta_event_cb(lv_obj_t *ta, lv_event_t event);
static lv_obj_t *kb;

void test_lvgl_boto(void)
{
  /* Create the password box */
  lv_obj_t *pwd_ta = lv_textarea_create(lv_scr_act(), NULL);
  lv_textarea_set_text(pwd_ta, "");
  lv_textarea_set_pwd_mode(pwd_ta, true);
  lv_textarea_set_one_line(pwd_ta, true);
  lv_textarea_set_cursor_hidden(pwd_ta, true);
  lv_obj_set_width(pwd_ta, LV_HOR_RES / 2 - 20);
  lv_obj_set_pos(pwd_ta, 200, 100);
  lv_obj_set_event_cb(pwd_ta, ta_event_cb);

  lv_obj_t *pwd_label = lv_label_create(lv_scr_act(), NULL); // Create a label and position it above the text box
  lv_label_set_text(pwd_label, "Password:");
  lv_obj_align(pwd_label, pwd_ta, LV_ALIGN_OUT_TOP_MID, 0, 0);

  kb = lv_keyboard_create(lv_scr_act(), NULL); // Create a keyboard
  lv_obj_set_size(kb, LV_HOR_RES, LV_VER_RES / 2);

  lv_keyboard_set_textarea(kb, pwd_ta);    /* Focus it on one of the text areas to start */
  lv_keyboard_set_cursor_manage(kb, true); /* Automatically show/hide cursors on text areas */
}

static void ta_event_cb(lv_obj_t *ta, lv_event_t event)
{
  if (event == LV_EVENT_CLICKED)
  {
    /* Focus on the clicked text area */
    if (kb != NULL)
      lv_keyboard_set_textarea(kb, ta);
  }

  else if (event == LV_EVENT_INSERT)
  {
    const char *str = lv_event_get_data();
    if (str[0] == '\n')
    {
      
    }
  }
}

volatile uint16_t cnt = 0; // contador temporal, usado para ver si el LED se queda fijo ( si lo hace, el sistema se colgó )

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  lv_init();

  lv_disp_buf_init(&buffers_pantalla, buffer_1, NULL, LV_HOR_RES_MAX * 10);

  // init display
  lv_disp_drv_init(&disp_drv);
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.hor_res = LV_HOR_RES_MAX;
  disp_drv.ver_res = LV_VER_RES_MAX;
  disp_drv.buffer = &buffers_pantalla;
  disp_drv.rotated = 0;
  disp_drv.color_chroma_key = LV_COLOR_TRANSP;
  disp_drv.dpi = LV_DPI;
  lv_disp_drv_register(&disp_drv);

  // init touch panel
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SDIO_SD_Init();
  MX_TIM4_Init();
  MX_USART2_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_I2C2_Init();
  MX_FATFS_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  Pantalla_init();
  test_lvgl_boto();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    HAL_Delay(5);
    lv_task_handler();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SDIO | RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48CLKSOURCE_PLLQ;
  PeriphClkInitStruct.SdioClockSelection = RCC_SDIOCLKSOURCE_CLK48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
  if (htim->Instance == TIM2)
  {
    cnt++;
    if (cnt >= 500)
    {
      HAL_GPIO_TogglePin(led_GPIO_Port, led_Pin);
      //HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, 1);
      cnt = 0;
    }
    lv_tick_inc(1);
  }
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
