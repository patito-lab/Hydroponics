/*
 * status_LEDs.c
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */
#include "status_LEDs.h"
#include "stm32f4xx_hal.h"

#define LED_PORT  GPIOA
#define LED_PIN   GPIO_PIN_5

void status_leds_init(void)
{
    GPIO_InitTypeDef init = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    init.Pin   = LED_PIN;
    init.Mode  = GPIO_MODE_OUTPUT_PP;
    init.Pull  = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(LED_PORT, &init);
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
}

void status_leds_set(bool on)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, on ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

