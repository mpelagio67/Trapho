/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fonts.h"
#include "ssd1306.h"
#include "math.h"
#include "stdlib.h"

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
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */
int cont = 64;
char valor[10];
int teclaAnterior = 255;
int teclaAtual = 0;
int confereTecla = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
int verifica_teclado();
void contagemEspiras();
int le_valor();
int obtem_tecla();

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  SSD1306_Init();

  SSD1306_GotoXY(0,0);
  SSD1306_Puts("PROTOPLACAS",&Font_11x18,1);
  SSD1306_GotoXY(0,30);
  SSD1306_Puts("BOBINADEIRA",&Font_11x18,1);
  SSD1306_UpdateScreen();

  HAL_Delay(3000);

  SSD1306_Clear();
  SSD1306_GotoXY(13,0);
  SSD1306_Puts("ENROLANDO",&Font_11x18,1);
  SSD1306_GotoXY(36,20);
  SSD1306_Puts("ESPIRAS:",&Font_7x10,1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //contagemEspiras(); //Impreime na tela
  while (1)
  {


	  contagemEspiras(); //Imprime na tela
	  cont = le_valor();

/*
			// faz a leitura das teclas
	  	  	teclaAtual = verifica_teclado();
			if(teclaAtual != 255){ //verifica se alguma tecla foi pressionada

				teclaAtual = verifica_teclado();
				if (teclaAtual != teclaAnterior){
					cont = teclaAtual;
				}
			} else {
				cont = 111;
			}
			teclaAnterior = teclaAtual;
*/

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
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

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Coluna1_Pin|Coluna2_Pin|Coluna3_Pin|Coluna4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : sensorContagem_Pin sensor2_Pin sensor3_Pin */
  GPIO_InitStruct.Pin = sensorContagem_Pin|sensor2_Pin|sensor3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Linha1_Pin Linha2_Pin Linha3_Pin Linha4_Pin */
  GPIO_InitStruct.Pin = Linha1_Pin|Linha2_Pin|Linha3_Pin|Linha4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Coluna1_Pin Coluna2_Pin Coluna3_Pin Coluna4_Pin */
  GPIO_InitStruct.Pin = Coluna1_Pin|Coluna2_Pin|Coluna3_Pin|Coluna4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  if (GPIO_Pin == GPIO_PIN_13)
  {
	  cont++;
	  for(int j= 0; j<10000;j++);
  }
}

int le_valor(){
	const int MAXIMO = 5;
	int bufferTeclado[MAXIMO + 1];
	int i = 0;
	int valor = 0;
	int exp = 1;

	int tecla = obtem_tecla();
	bufferTeclado[0] = 255;

	while(tecla != 15){ //coloca valor digitado no buffer
		if ((tecla < 10)&(tecla >=0)&(i<MAXIMO)){
			bufferTeclado[i] = tecla;
			i++;
			bufferTeclado[i] = 255; //byte seguinte tem marcador do fim da string
		}
		else if ((tecla == 14)&(i>0)){ // apaga 1 caracter do buffer ao pressionar '*'
			i--;
			bufferTeclado[i]= 255;
		}
		tecla = obtem_tecla();
	}
	//CONVERTE A STRING NO buffer EM VALOR INTEIRO
	//valor do exp = 1
	for (;i>0;i--){
		i--;
		valor += bufferTeclado[i] * exp;
		exp *= 10;
	}

	return valor;

}

int obtem_tecla(){ //Aguarda até obter o codigo da tecla pressionada

	teclaAnterior = 255;
	while(teclaAnterior == 255){
		// faz a leitura das teclas
		teclaAtual = verifica_teclado();
		if(teclaAtual != 255){ //verifica se alguma tecla foi pressionada

			teclaAtual = verifica_teclado();
			if (teclaAtual != teclaAnterior){
				cont = teclaAtual;
				teclaAnterior = teclaAtual;
			}
		}
	}
	return cont;
}

int verifica_teclado(){

	int selecaoLinha = 255;

	//inicialmente deixa todas as linhas do teclado em nível alto (condição de inicio da varredura)
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,1); //Restaura a LINHA1
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,1); //Restaura a LINHA2
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,1); //Restaura a LINHA3
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,1); //Restaura a LINHA4

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,0); //Aciona a COLUNA4 do Teclado
	selecaoLinha = ~(GPIOB->IDR);
	if (selecaoLinha & 0b0001000000000000) {return 1;}
	if (selecaoLinha & 0b0010000000000000) {return 4;}
	if (selecaoLinha & 0b0100000000000000) {return 7;}
	if (selecaoLinha & 0b1000000000000000) {return 14;}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,1); //Restaura a LINHA1


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,0); //Aciona a COLUNA3 do Teclado
	selecaoLinha = ~(GPIOB->IDR);
	if (selecaoLinha & 0b0001000000000000) return 2;
	if (selecaoLinha & 0b0010000000000000) return 5;
	if (selecaoLinha & 0b0100000000000000) return 8;
	if (selecaoLinha & 0b1000000000000000) return 0;  //retorna o valor 0 como codigo de Teclado
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,1); //Restaura a LINHA2


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,0); //Aciona a COLUNA2 do Teclado
	selecaoLinha = ~(GPIOB->IDR);
	if (selecaoLinha & 0b0001000000000000) return 3;
	if (selecaoLinha & 0b0010000000000000) return 6;
	if (selecaoLinha & 0b0100000000000000) return 9;
	if (selecaoLinha & 0b1000000000000000) return 15;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,1); //Restaura a LINHA3


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,0); //Aciona a COLUNA1 do Teclado
	selecaoLinha = ~(GPIOB->IDR);
	if (selecaoLinha & 0b0001000000000000) return 10;
	if (selecaoLinha & 0b0010000000000000) return 11;
	if (selecaoLinha & 0b0100000000000000) return 12;
	if (selecaoLinha & 0b1000000000000000) return 13;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,1); //Restaura a LINHA4

	return 255; //se nenhuma Tecla é pressionada retorna o valor 255;

}

void contagemEspiras(){


	itoa(cont, valor, 10);
	SSD1306_GotoXY (0, 32);
	SSD1306_Puts ("             ", &Font_16x26, 1);
	SSD1306_UpdateScreen();
	if(cont < 10) {
		SSD1306_GotoXY (53, 32);  // 1 DIGIT
	}
	else if (cont < 100 ) {
		SSD1306_GotoXY (45, 32);  // 2 DIGITS
	}
	else if (cont < 1000 ) {
		SSD1306_GotoXY (37, 32);  // 3 DIGITS
	}
	else {
		SSD1306_GotoXY (30, 32);  // 4 DIGIS
	}
	SSD1306_Puts (valor, &Font_16x26, 1);
	SSD1306_UpdateScreen();
	HAL_Delay (20);

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
