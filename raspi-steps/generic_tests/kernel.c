#include "uart.h"

int kernel_init(){
    uart_init();
    while(1);
    return 1;
}