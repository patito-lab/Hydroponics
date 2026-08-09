/*
 * status_LEDs.c
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */
#include "status_LEDs.h"
#include "stm32f4xx_hal.h"

#define SYS_GREEN_PORT  GPIOC
#define SYS_GREEN_PIN   GPIO_PIN_6
#define SYS_RED_PORT    GPIOC
#define SYS_RED_PIN     GPIO_PIN_8

void status_leds_init(void)
{
    GPIO_InitTypeDef init = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();

    init.Pin   = SYS_GREEN_PIN | SYS_RED_PIN;
    init.Mode  = GPIO_MODE_OUTPUT_PP;
    init.Pull  = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOC, &init);

    status_leds_set(SYS_OFF);
}

void status_leds_set(sys_state_t state)
{
    /* green is sunk from +5V: LOW = lit */
    HAL_GPIO_WritePin(SYS_GREEN_PORT, SYS_GREEN_PIN,
                      (state == SYS_OK) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    /* red is sourced from the pin: HIGH = lit */
    HAL_GPIO_WritePin(SYS_RED_PORT, SYS_RED_PIN,
                      (state == SYS_FAULT) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
