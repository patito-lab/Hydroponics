/*
 * level_check.c
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */
#include "level_check.h"
#include "stm32f4xx_hal.h"

#define TANK_HIGH_PORT    GPIOA
#define TANK_HIGH_PIN     GPIO_PIN_15
#define TANK_REFILL_PORT  GPIOB
#define TANK_REFILL_PIN   GPIO_PIN_7
#define TANK_LOW_PORT     GPIOB
#define TANK_LOW_PIN      GPIO_PIN_0


#define BOT1_LEVEL_PORT   GPIOC
#define BOT1_LEVEL_PIN    GPIO_PIN_10

#define BOT2_LEVEL_PORT   GPIOC
#define BOT2_LEVEL_PIN    GPIO_PIN_11

#define BOT3_LEVEL_PORT   GPIOC
#define BOT3_LEVEL_PIN    GPIO_PIN_12

#define BOT4_LEVEL_PORT   GPIOD
#define BOT4_LEVEL_PIN    GPIO_PIN_2


void level_check_init(void)
{
    GPIO_InitTypeDef init = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    init.Mode  = GPIO_MODE_INPUT;
    init.Pull  = GPIO_PULLUP;
    init.Speed = GPIO_SPEED_FREQ_LOW;

    init.Pin   = TANK_HIGH_PIN;
    HAL_GPIO_Init(TANK_HIGH_PORT, &init);

    init.Pin   = TANK_REFILL_PIN | TANK_LOW_PIN;
    HAL_GPIO_Init(TANK_REFILL_PORT, &init);

    init.Pin   = BOT1_LEVEL_PIN | BOT2_LEVEL_PIN | BOT3_LEVEL_PIN;
    HAL_GPIO_Init(BOT1_LEVEL_PORT, &init);

    init.Pin   = BOT4_LEVEL_PIN;
    HAL_GPIO_Init(BOT4_LEVEL_PORT, &init);

}

// bottle switches are wired normally-open with a pull-up: the pin reads SET
// (HIGH) when the float switch is open, i.e. no liquid contact at that
// sensor's height, and RESET (LOW) when liquid is present there.
//
// the tank floats are the opposite polarity (vertical vs. horizontal switch
// bodies - normally-closed instead of normally-open), same pull-up wiring:
// RESET (LOW) when open/no liquid contact, SET (HIGH) when liquid present.

// debounce is sampled once per main-loop pass (50 ms), so this needs no
// timer of its own.
#define DEBOUNCE_SAMPLES 3  // ~150 ms at the 50 ms main loop poll rate

typedef struct {
    bool stable;
    bool candidate;
    uint8_t count;
} debounce_t;

static bool debounce_update(debounce_t *d, bool raw)
{
    if (raw == d->candidate) {
        if (d->count < DEBOUNCE_SAMPLES) {
            d->count++;
        }
    } else {
        d->candidate = raw;
        d->count = 1;
    }

    if (d->count >= DEBOUNCE_SAMPLES) {
        d->stable = d->candidate;
    }

    return d->stable;
}

bool tank_is_low(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(TANK_LOW_PORT, TANK_LOW_PIN) == GPIO_PIN_RESET);
    return debounce_update(&d, raw);
}

bool tank_below_refill(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(TANK_REFILL_PORT, TANK_REFILL_PIN) == GPIO_PIN_RESET);
    return debounce_update(&d, raw);
}

bool tank_is_full(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(TANK_HIGH_PORT, TANK_HIGH_PIN) == GPIO_PIN_SET);
    return debounce_update(&d, raw);
}

bool bot1_is_empty(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(BOT1_LEVEL_PORT, BOT1_LEVEL_PIN) == GPIO_PIN_SET);
    return debounce_update(&d, raw);
}

bool bot2_is_empty(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(BOT2_LEVEL_PORT, BOT2_LEVEL_PIN) == GPIO_PIN_SET);
    return debounce_update(&d, raw);
}

bool bot3_is_empty(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(BOT3_LEVEL_PORT, BOT3_LEVEL_PIN) == GPIO_PIN_SET);
    return debounce_update(&d, raw);
}

bool bot4_is_empty(void)
{
    static debounce_t d = {0};
    bool raw = (HAL_GPIO_ReadPin(BOT4_LEVEL_PORT, BOT4_LEVEL_PIN) == GPIO_PIN_SET);
    return debounce_update(&d, raw);
}
