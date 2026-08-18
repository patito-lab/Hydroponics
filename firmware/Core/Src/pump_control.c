/*
 * pump_control.c
 *
 *  Created on: Aug 16, 2026
 *      Author: graytongiesman
 */
#include "pump_control.h"
#include "stm32f4xx_hal.h"

// all 4 dosing pumps are low-side AO3400A drives on GPIOA (see decision
// 004-pump-wiring.md): GPIO HIGH turns the MOSFET on. Pins double as
// TIM1_CH1-4 in the pinout doc for possible future PWM speed control,
// but for now they're driven as plain on/off outputs.
#define PUMP1_PORT GPIOA
#define PUMP1_PIN  GPIO_PIN_8
#define PUMP2_PORT GPIOA
#define PUMP2_PIN  GPIO_PIN_9
#define PUMP3_PORT GPIOA
#define PUMP3_PIN  GPIO_PIN_10
#define PUMP4_PORT GPIOA
#define PUMP4_PIN  GPIO_PIN_11

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} pump_gpio_t;

static const pump_gpio_t pumps[DOSE_CONTENT_COUNT] = {
    [DOSE_CAL_NITRATE] = { PUMP1_PORT, PUMP1_PIN },
    [DOSE_NUTRIENT]    = { PUMP2_PORT, PUMP2_PIN },
    [DOSE_PH_DOWN]     = { PUMP3_PORT, PUMP3_PIN },
    [DOSE_PH_UP]       = { PUMP4_PORT, PUMP4_PIN },
};

typedef struct {
    bool running;
    uint32_t start_tick;
    uint32_t duration_ms;
} dose_state_t;

static dose_state_t states[DOSE_CONTENT_COUNT];

void pump_control_init(void)
{
    GPIO_InitTypeDef init = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    init.Mode  = GPIO_MODE_OUTPUT_PP;
    init.Pull  = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_FREQ_LOW;
    init.Pin   = PUMP1_PIN | PUMP2_PIN | PUMP3_PIN | PUMP4_PIN;
    HAL_GPIO_Init(GPIOA, &init);

    for (int i = 0; i < DOSE_CONTENT_COUNT; i++) {
        HAL_GPIO_WritePin(pumps[i].port, pumps[i].pin, GPIO_PIN_RESET);
        states[i] = (dose_state_t){0};
    }
}

bool pump_dose_start(dose_content_t content, uint32_t duration_ms)
{
    if (states[content].running || duration_ms == 0) {
        return false;
    }

    states[content].running = true;
    states[content].start_tick = HAL_GetTick();
    states[content].duration_ms = duration_ms;
    HAL_GPIO_WritePin(pumps[content].port, pumps[content].pin, GPIO_PIN_SET);
    return true;
}

void pump_stop(dose_content_t content)
{
    HAL_GPIO_WritePin(pumps[content].port, pumps[content].pin, GPIO_PIN_RESET);
    states[content].running = false;
}

bool pump_is_busy(dose_content_t content)
{
    return states[content].running;
}

void pump_control_update(void)
{
    for (int i = 0; i < DOSE_CONTENT_COUNT; i++) {
        if (states[i].running &&
            (HAL_GetTick() - states[i].start_tick) >= states[i].duration_ms) {
            HAL_GPIO_WritePin(pumps[i].port, pumps[i].pin, GPIO_PIN_RESET);
            states[i].running = false;
        }
    }
}
