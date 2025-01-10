#include "include/peripherals.h"
#include "include/mmio.h"
#include "include/gpio.h"
#include "include/timer.h"
#include "include/uart.h"

void kernel_init(void)
{
    uart_init(); // init uart
    uart_writeText("UART STARTED...\n");
  
    set_gpio_pin_pup_pdn(17, GPIO_PDN);
    set_gpio_pin_function(17, GPIO_OUTPUT);
    while (1)
    {

        uart_writeText("GPIO HIGH...\n");
        set_gpio_pin_level_high(17);
        sleep(10000000);
        
        uart_writeText("GPIO LOW...\n");
        set_gpio_pin_level_low(17);
        sleep(10000000);
    }

    while (1)
        ;
}