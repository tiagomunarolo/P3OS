#pragma once

#define  AUX_IRQ            0x00 // Auxiliary Interrupt status
#define  AUX_ENABLES        0x04 // Auxiliary enables
#define  AUX_MU_IO_REG      0x40 // Mini UART I/O Data
#define  AUX_MU_IER_REG     0x44 // Mini UART Interrupt Enable
#define  AUX_MU_IIR_REG     0x48 // Mini UART Interrupt Identify
#define  AUX_MU_LCR_REG     0x4c// Mini UART Line Control
#define  AUX_MU_MCR_REG     0x50// Mini UART Modem Control
#define  AUX_MU_LSR_REG     0x54 // Mini UART Line Status
#define  AUX_MU_MSR_REG     0x58// Mini UART Modem Status
#define  AUX_MU_SCRATCH     0x5c// Mini UART Scratch
#define  AUX_MU_CNTL_REG    0x60// Mini UART Extra Control
#define  AUX_MU_STAT_REG    0x64// Mini UART Extra Status
#define  AUX_MU_BAUD_REG    0x68// Mini UART Baudrate

void uart_init();
void uart_sendChar(char ch);
void uart_writeText(char *buffer);
