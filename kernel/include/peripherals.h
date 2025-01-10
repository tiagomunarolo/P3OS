#pragma once

#define PERIPHERAL_BASE     0xFE000000                  //Base address for mmio peripherals

// Auxiliaries
#define AUX_BASE            PERIPHERAL_BASE + 0x215000  //Base address for AUX
#define AUX_IRQ             AUX_BASE + 0x00             //AUX IRQ register
#define AUX_ENABLES         AUX_BASE + 0x04             //AUX Enable register
#define AUX_MU_IO_REG       AUX_BASE + 0x40             //Mini UART I/O Register
#define AUX_MU_IER_REG      AUX_BASE + 0x44             //Mini UART Interrupt Enable
#define AUX_MU_IIR_REG      AUX_BASE + 0x48             //Mini UART Interrupt Identify
#define AUX_MU_LCR_REG      AUX_BASE + 0x4c             //Mini UART Line Control
#define AUX_MU_MCR_REG      AUX_BASE + 0x50             //Mini UART Modem Control
#define AUX_MU_LSR_REG      AUX_BASE + 0x54             //Mini UART Line Status
#define AUX_MU_MSR_REG      AUX_BASE + 0x58             //Mini UART Modem Status
#define AUX_MU_SCRATCH      AUX_BASE + 0x5c             //Mini UART Scratch
#define AUX_MU_CNTL_REG     AUX_BASE + 0x60             //Mini UART Extra Control
#define AUX_MU_STAT_REG     AUX_BASE + 0x64             //Mini UART Extra Status
#define AUX_MU_BAUD_REG     AUX_BASE + 0x68             //Mini UART Baudrate

// GPIO
#define GPIO_BASE           PERIPHERAL_BASE + 0x200000   //Base address for GPIO
#define GPIO_GPFSEL0        GPIO_BASE + 0x00             //GPIO Function Select 0
#define GPIO_GPFSEL1        GPIO_BASE + 0x04             //GPIO Function Select 1
#define GPIO_GPFSEL2        GPIO_BASE + 0x08             //GPIO Function Select 2
#define GPIO_GPFSEL3        GPIO_BASE + 0x0c             //GPIO Function Select 3
#define GPIO_GPFSEL4        GPIO_BASE + 0x10             //GPIO Function Select 4
#define GPIO_GPFSEL5        GPIO_BASE + 0x14             //GPIO Function Select 5
#define GPIO_GPSET0         GPIO_BASE + 0x1c             //GPIO Pin Output Set 0
#define GPIO_GPSET1         GPIO_BASE + 0x20             //GPIO Pin Output Set 1 
#define GPIO_GPCLR0         GPIO_BASE + 0x28             //GPIO Pin Output Clear 0
#define GPIO_GPCLR1         GPIO_BASE + 0x2c             //GPIO Pin Output Clear 1
#define GPIO_PUP_PDN_CNTRL_REG0 GPIO_BASE + 0xe4         //GPIO Pullup/Pulldown Control
#define GPIO_PUP_PDN_CNTRL_REG1 GPIO_BASE + 0xe8         //GPIO Pullup/Pulldown Control
#define GPIO_PUP_PDN_CNTRL_REG2 GPIO_BASE + 0xec         //GPIO Pullup/Pulldown Control
#define GPIO_PUP_PDN_CNTRL_REG3 GPIO_BASE + 0xf0         //GPIO Pullup/Pulldown Control
