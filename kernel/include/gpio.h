#pragma once

// functions states for gpio
#define GPIO_INPUT 0
#define GPIO_OUTPUT 1
#define GPIO_AF0 4
#define GPIO_AF1 5
#define GPIO_AF2 6
#define GPIO_AF3 7
#define GPIO_AF4 3
#define GPIO_AF5 2

// pull up/down states
#define GPIO_PUP 1
#define GPIO_PDN 2

#define GPIO_LOW 0
#define GPIO_HIGH 1

// number of gpio pins
#define GPIO_PINS 58

void set_gpio_pin_function(short pin, short function);
void set_gpio_pin_pup_pdn(short pin, short pup_pdn);
void set_gpio_pin_level_high(short pin);
void set_gpio_pin_level_low(short pin);