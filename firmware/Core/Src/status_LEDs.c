/*
 * status_LEDs.c
 *
 *  Created on: Aug 8, 2026
 *      Author: graytongiesman
 */
#include "status_LEDs.h"
#include "stm32f4xx_hal.h"

//system indicator define
#define SYS_GREEN_PORT    GPIOB
#define SYS_GREEN_PIN     GPIO_PIN_10
#define SYS_RED_PORT      GPIOB
#define SYS_RED_PIN       GPIO_PIN_6

//tank level define
#define TANK_GREEN_PORT   GPIOC
#define TANK_GREEN_PIN    GPIO_PIN_7
#define TANK_YELLOW_PORT  GPIOC
#define TANK_YELLOW_PIN   GPIO_PIN_6
#define TANK_RED_PORT     GPIOC
#define TANK_RED_PIN      GPIO_PIN_8

//bottle 1 indicator define
#define BOT1_GREEN_PORT   GPIOB
#define BOT1_GREEN_PIN    GPIO_PIN_13
#define BOT1_RED_PORT     GPIOB
#define BOT1_RED_PIN      GPIO_PIN_12

//bottle 2 indicator define
#define BOT2_GREEN_PORT   GPIOB
#define BOT2_GREEN_PIN    GPIO_PIN_15
#define BOT2_RED_PORT     GPIOB
#define BOT2_RED_PIN      GPIO_PIN_14

//bottle 3 indicator define
#define BOT3_GREEN_PORT   GPIOB
#define BOT3_GREEN_PIN    GPIO_PIN_2
#define BOT3_RED_PORT     GPIOB
#define BOT3_RED_PIN      GPIO_PIN_1

//bottle 4 indicator define
#define BOT4_GREEN_PORT   GPIOB
#define BOT4_GREEN_PIN    GPIO_PIN_5
#define BOT4_RED_PORT     GPIOB
#define BOT4_RED_PIN      GPIO_PIN_4

//initialize status LED's
void status_leds_init(void)
{
    GPIO_InitTypeDef init = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();


    init.Mode  = GPIO_MODE_OUTPUT_PP;
    init.Pull  = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_FREQ_LOW;

    init.Pin   = SYS_GREEN_PIN | SYS_RED_PIN |
				 BOT1_GREEN_PIN | BOT1_RED_PIN |
				 BOT2_GREEN_PIN | BOT2_RED_PIN |
				 BOT3_GREEN_PIN | BOT3_RED_PIN |
				 BOT4_GREEN_PIN | BOT4_RED_PIN;
    HAL_GPIO_Init(GPIOB, &init);

    init.Pin  = TANK_GREEN_PIN | TANK_YELLOW_PIN | TANK_RED_PIN;
    HAL_GPIO_Init(GPIOC, &init);

    status_leds_set(SYS_OFF);
}

//set status LED
void status_leds_set(sys_state_t state)
{
    // turn green on, green is sunk from +5V: LOW = lit
    HAL_GPIO_WritePin(SYS_GREEN_PORT, SYS_GREEN_PIN,
                      (state == SYS_OK) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    //turn red on, red is sourced from the pin: HIGH = lit
    HAL_GPIO_WritePin(SYS_RED_PORT, SYS_RED_PIN,
                      (state == SYS_FAULT) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

//set tank LED -> MISSING

//set tank LEDS
void tank_leds_set(tank_state_t state)
{
    // turn green on, green is sunk from +5V: LOW = lit
    HAL_GPIO_WritePin(TANK_GREEN_PORT, TANK_GREEN_PIN,
                      (state == TANK_FULL) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    //turn red on, red is sourced from the pin: HIGH = lit
    HAL_GPIO_WritePin(TANK_RED_PORT, TANK_RED_PIN,
                      (state == TANK_LOW) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    //turn yellow on, same logic as red
    HAL_GPIO_WritePin(TANK_YELLOW_PORT, TANK_YELLOW_PIN,
                      (state == TANK_REFILL) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}


//set bottle 1 LED
void bot1_leds_set(bot1_state_t state)
{
    // turn green on, green is sunk from +5V: LOW = lit
    HAL_GPIO_WritePin(BOT1_GREEN_PORT, BOT1_GREEN_PIN,
                      (state == BOT1_FULL) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    //turn red on, red is sourced from the pin: HIGH = lit
    HAL_GPIO_WritePin(BOT1_RED_PORT, BOT1_RED_PIN,
                      (state == BOT1_LOW) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

//set bottle 2 LED
void bot2_leds_set(bot2_state_t state)
{
    // turn green on, green is sunk from +5V: LOW = lit
    HAL_GPIO_WritePin(BOT2_GREEN_PORT, BOT2_GREEN_PIN,
                      (state == BOT2_FULL) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    //turn red on, red is sourced from the pin: HIGH = lit
    HAL_GPIO_WritePin(BOT2_RED_PORT, BOT2_RED_PIN,
                      (state == BOT2_LOW) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

//set bottle 3 LED
void bot3_leds_set(bot3_state_t state)
{
    // turn green on, green is sunk from +5V: LOW = lit
    HAL_GPIO_WritePin(BOT3_GREEN_PORT, BOT3_GREEN_PIN,
                      (state == BOT3_FULL) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    //turn red on, red is sourced from the pin: HIGH = lit
    HAL_GPIO_WritePin(BOT3_RED_PORT, BOT3_RED_PIN,
                      (state == BOT3_LOW) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

//set bottle 4 LED
void bot1_leds_set(bot4_state_t state)
{
    // turn green on, green is sunk from +5V: LOW = lit
    HAL_GPIO_WritePin(BOT4_GREEN_PORT, BOT4_GREEN_PIN,
                      (state == BOT4_FULL) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    //turn red on, red is sourced from the pin: HIGH = lit
    HAL_GPIO_WritePin(BOT4RED_PORT, BOT4_RED_PIN,
                      (state == BOT4_LOW) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
