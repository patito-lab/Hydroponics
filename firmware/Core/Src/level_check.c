/*
 * level_check.c
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */
#include "level_check.h"
#include "stm32f4xx_hal.h"

#define LEVEL_PORT  GPIOC
#define LEVEL_PIN   GPIO_PIN_0

void level_check_init(void)
{
    GPIO_InitTypeDef init = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();

    init.Pin   = LEVEL_PIN;
    init.Mode  = GPIO_MODE_INPUT;
    init.Pull  = GPIO_PULLUP;
    init.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(LEVEL_PORT, &init);
}

bool level_check_is_full(void)
{
    return (HAL_GPIO_ReadPin(LEVEL_PORT, LEVEL_PIN) == GPIO_PIN_SET);
}
