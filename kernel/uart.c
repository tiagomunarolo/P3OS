#include "include/aux.h"
#include "include/peripherals.h"

void mmio_write(u64 reg, u32 val)
{
    *(volatile unsigned int *)reg = val; // write val to reg
}
unsigned int mmio_read(u64 reg)
{
    return *(v32 *)reg; // read val from reg
}
unsigned int uart_isWriteByteReady()
{
    return mmio_read(AUX_MU_LSR_REG) & 0x20; // check if transmiter idle
}

void uart_writeByte(unsigned char ch)
{
    while (!uart_isWriteByteReady()) // wait until tx idle
        ;
    mmio_write(AUX_MU_IO_REG, (unsigned int)ch); // write byte to uart
}

void enable_rx_tx_pins()
{
    // pull down pins 14 and 15
    u32 value = mmio_read(GPIO_PUP_PDN_CNTRL_REG0);
    value &= ~(3 << 28 | 3 << 30);
    value |= (2 << 28 | 2 << 30);
    mmio_write(GPIO_PUP_PDN_CNTRL_REG0, value);
    // set alternate function 5 for uart1: mode 5 => 010 => alt 5
    // GPIO 14 and 15 = UART1_RXD1 and UART1_TXD1
    mmio_write(GPIO_GPFSEL1, (2 << 12 | 2 << 15));
}

void uart_init()
{
    mmio_write(AUX_ENABLES, 1);       // enable UART1
    mmio_write(AUX_MU_IER_REG, 0);    // disable interrupts
    mmio_write(AUX_MU_CNTL_REG, 0);   // disable RX/TX
    mmio_write(AUX_MU_LCR_REG, 3);    // 8 bits
    mmio_write(AUX_MU_MCR_REG, 0);    // diable model signals
    mmio_write(AUX_MU_BAUD_REG, 541); // set baudrate
    enable_rx_tx_pins();
    mmio_write(AUX_MU_CNTL_REG, 3); // enable RX/TX
    uart_writeByte('\r');
    uart_writeByte('\n');
    uart_writeByte('\n');
}

void uart_writeText(char *buffer)
{
    while (*buffer)
    {
        if (*buffer == '\n')
            uart_writeByte('\r');
        uart_writeByte(*buffer++);
    }
}
