#include "uart.h"
#include <stdint.h>

volatile uint8_t *uart = (uint8_t *) 0x09000000;

void printchar(char c) {
    *uart = c;
}

void print(const char *s) {
    while(*s != '\0') {
        printchar(*s);
        s++;
    }
}
