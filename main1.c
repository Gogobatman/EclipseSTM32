/**
  ******************************************************************************
  * @file    main.c
  * @author  Mateusz Figoń
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
			

int main(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();		//led configuration
	GPIO_InitTypeDef gpio1;
	gpio1.Mode=GPIO_MODE_OUTPUT_PP;
	gpio1.Pin=GPIO_PIN_5;
	HAL_GPIO_Init(GPIOA,&gpio1);

	__HAL_RCC_GPIOA_CLK_ENABLE();  //button configuration
	GPIO_InitTypeDef gpio2;
	gpio2.Mode=GPIO_MODE_INPUT;
	gpio2.Pin=GPIO_PIN_13;
	HAL_GPIO_Init(GPIOC,&gpio2);

	while(1){
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)==1){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		}
		else{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		}


	}
}
