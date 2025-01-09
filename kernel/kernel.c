#include "include/uart.h"

void kernel_init(void) {
    uart_init();    //init uart
    uart_writeText("UART STARTED...\n");
    while (1);
}