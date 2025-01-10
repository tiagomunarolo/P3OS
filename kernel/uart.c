#include "include/aux.h"
#include "include/gpio.h"
#include "include/mmio.h"
#include "include/peripherals.h"

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
    set_gpio_pin_pup_pdn(14, GPIO_PDN);
    set_gpio_pin_pup_pdn(15, GPIO_PDN);
    // GPIO 14 and 15 = UART1_RXD1 and UART1_TXD1
    set_gpio_pin_function(14, GPIO_AF5);
    set_gpio_pin_function(15, GPIO_AF5);
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
