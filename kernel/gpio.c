#include "include/gpio.h"
#include "include/mmio.h"
#include "include/peripherals.h"

void set_gpio_pin_function(short pin, short function)
{
    // gpio 0-9   -> GPFSEL0 Register
    // gpio 10-19 -> GPFSEL1 Register
    // gpio 20-29 -> GPFSEL2 Register
    // gpio 30-39 -> GPFSEL3 Register
    // gpio 40-49 -> GPFSEL4 Register
    // gpio 50-57 -> GPFSEL5 Register
    if (pin + 1 >= GPIO_PINS || function > 7)
        return;

    short offset = (pin % 10) * 3;

    if (pin < 10)
        mmio_write(GPIO_GPFSEL0, (mmio_read(GPIO_GPFSEL0) & ~(0b111 << offset)) | (function << offset));
    else if (pin < 20)
        mmio_write(GPIO_GPFSEL1, (mmio_read(GPIO_GPFSEL1) & ~(0b111 << offset)) | (function << offset));
    else if (pin < 30)
        mmio_write(GPIO_GPFSEL2, (mmio_read(GPIO_GPFSEL2) & ~(0b111 << offset)) | (function << offset));
    else if (pin < 40)
        mmio_write(GPIO_GPFSEL3, (mmio_read(GPIO_GPFSEL3) & ~(0b111 << offset)) | (function << offset));
    else if (pin < 50)
        mmio_write(GPIO_GPFSEL4, (mmio_read(GPIO_GPFSEL4) & ~(0b111 << offset)) | (function << offset));
    else if (pin < 58)
        mmio_write(GPIO_GPFSEL5, (mmio_read(GPIO_GPFSEL5) & ~(0b111 << offset)) | (function << offset));
};

void set_gpio_pin_pup_pdn(short pin, short function)
{
    // gpio 0-15  -> GPIO_PUP_PDN_CNTRL_REG0 Register
    // gpio 16-31 -> GPIO_PUP_PDN_CNTRL_REG1 Register
    // gpio 32-47 -> GPIO_PUP_PDN_CNTRL_REG2 Register
    // gpio 48-57 -> GPIO_PUP_PDN_CNTRL_REG3 Register
    if (pin + 1 >= GPIO_PINS || function > 3)
        return;

    short offset = (pin % 16) * 2;

    if (pin < 16)
        mmio_write(GPIO_PUP_PDN_CNTRL_REG0, (mmio_read(GPIO_PUP_PDN_CNTRL_REG0) & ~(0b11 << offset)) | (function << offset));
    else if (pin < 32)
        mmio_write(GPIO_PUP_PDN_CNTRL_REG1, (mmio_read(GPIO_PUP_PDN_CNTRL_REG1) & ~(0b11 << offset)) | (function << offset));
    else if (pin < 48)
        mmio_write(GPIO_PUP_PDN_CNTRL_REG2, (mmio_read(GPIO_PUP_PDN_CNTRL_REG2) & ~(0b11 << offset)) | (function << offset));
    else if (pin < 58)
        mmio_write(GPIO_PUP_PDN_CNTRL_REG3, (mmio_read(GPIO_PUP_PDN_CNTRL_REG3) & ~(0b11 << offset)) | (function << offset));
}

void set_gpio_pin_level_high(short pin){
    
    if (pin + 1 >= GPIO_PINS)
        return;
    if (pin < 32)
        mmio_write(GPIO_GPSET0, (mmio_read(GPIO_GPSET0) & ~(0b1 << pin)) | (GPIO_HIGH << pin));
    else if (pin < 58)
        mmio_write(GPIO_GPSET1, (mmio_read(GPIO_GPSET1) & ~(0b1 << pin)) | (GPIO_HIGH << pin));

}

void set_gpio_pin_level_low(short pin){
    
    if (pin + 1 >= GPIO_PINS)
        return;
    if (pin < 32)
        mmio_write(GPIO_GPCLR0, (mmio_read(GPIO_GPCLR0) & ~(0b1 << pin)) | (1 << pin));
    else if (pin < 58)
        mmio_write(GPIO_GPCLR1, (mmio_read(GPIO_GPCLR1) & ~(0b1 << pin)) | (1 << pin));

}
