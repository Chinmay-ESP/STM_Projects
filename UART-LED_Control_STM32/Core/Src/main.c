#include "main.h"
#include <string.h>

UART_HandleTypeDef huart4;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);

char data[] = "Enter Your Options to Control LED's - \r\n->LED1\r\n->LED2 \r\n->LED3 \r\n ";
uint8_t rx_data;
uint8_t rx_buffer[20];
uint8_t point = NULL;



int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_UART4_Init();

  HAL_UART_Transmit(&huart4, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin, GPIO_PIN_SET);

  while (1)
  {
    HAL_UART_Receive(&huart4, &rx_data, 1, HAL_MAX_DELAY);

    if(rx_data != '\n' && rx_data != '\r'){
      rx_buffer[point++] = rx_data;
    }
    else if(index > 0){
      rx_buffer[point] = '\0';
      point = 0;

      if(strcmp((char*)rx_buffer , "LED1") == 0){

        HAL_GPIO_WritePin(GPIOA, LED1_Pin , GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, LED2_Pin|LED3_Pin, GPIO_PIN_RESET);
        char msg1[] = "LED1 is ON\r\n";
      HAL_UART_Transmit(&huart4, (uint8_t*)msg1, strlen(msg1), HAL_MAX_DELAY);
      }
      else if(strcmp((char*)rx_buffer, "LED2") == 0){
        HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED3_Pin, GPIO_PIN_RESET);
        char msg2[] = "LED2 is ON\r\n";
        HAL_UART_Transmit(&huart4, (uint8_t*)msg2, strlen(msg2), HAL_MAX_DELAY);
      }
      else if(strcmp((char*)rx_buffer, "LED3") == 0){
        HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);
        char msg3[] = "LED3 is ON\r\n";
        HAL_UART_Transmit(&huart4, (uint8_t*)msg3, strlen(msg3), HAL_MAX_DELAY);
      }
      else{
        HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin, GPIO_PIN_RESET);
        char msg4[] = "Invalid Option, All LED's is OFF....\r\n";
        HAL_UART_Transmit(&huart4, (uint8_t*)msg4, strlen(msg4), HAL_MAX_DELAY);
      }
    }
  }
}



void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_UART4_Init(void)
{
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}


void Error_Handler(void)
{

  __disable_irq();
  while (1)
  {
  }

}

