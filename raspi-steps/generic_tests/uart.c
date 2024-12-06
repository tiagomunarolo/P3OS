#include "include/uart.h"
#include "include/common.h"
#include "include/peripherals.h"


void uart_init() { // initialize uart
    volatile u64 aux_base = AUX_BASE;
    // Mini UART interrupt status enable
    *(volatile unsigned int *)(aux_base + AUX_IRQ) = 0x1;
    // enable uart1
    *(volatile unsigned int *)(aux_base + AUX_ENABLES) = 0x1;
}

void uart_sendChar(char ch) {

}

void uart_writeText(char *buffer) {

}