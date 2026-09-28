#include "app.h"
#include "main.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2;

int _write(int file, char *ptr, int len)
{
	(void)file;
	HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, HAL_MAX_DELAY);
	return len;
}

void app_init(void)
{
	printf("boot\r\n");
}

void app_loop()
{
static uint32_t next = 500;
uint32_t now = HAL_GetTick();
if ((int32_t)(now-next)>=0)
{
	next +=500;
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	printf("alive %lu\r\n", now);
}
}

