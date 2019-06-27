/**
  ******************************************************************************
  * @file    main.c
  * @author  Mateusz Figoń
  * @version V1.0
  * @date    27-July-2019
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"

UART_HandleTypeDef huart2;
GPIO_InitTypeDef uartDef2;

uint8_t data[5]={'H','E','L','L','O'};
int main(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	uartDef2.Mode = GPIO_MODE_AF_PP;
	uartDef2.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	uartDef2.Pull = GPIO_PULLUP;
	uartDef2.Alternate= GPIO_AF7_USART2;
	uartDef2.Speed= GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOA,&uartDef2);

	__HAL_RCC_USART2_CLK_ENABLE();
	huart2.Instance= USART2;
	huart2.Init.Mode= USART_MODE_TX_RX;
	huart2.Init.OverSampling = USART_OVERSAMPLING_16;
	huart2.Init.BaudRate= 115200;
	huart2.Init.StopBits= USART_STOPBITS_1;
	huart2.Init.WordLength= UART_WORDLENGTH_8B;
	HAL_UART_Init(&huart2);


	while(1){
		HAL_UART_Transmit(&huart2,&data[0],5,5000);
		for(int i=0; i<300000; i++){

		}
	}

}
