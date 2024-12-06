#pragma once

// Base addresses for peripherals MMIO
#define PERIPHERAL_BASE     0x7E000000
// Base addresses for GPIO
#define GPIO_BASE           PERIPHERAL_BASE + 0x00200000
// Base addresses for Auxiliary peripherals (UART, ...)
#define AUX_BASE            PERIPHERAL_BASE + 0x00215000