#include "include/mmio.h"
#include "include/aux.h"

void mmio_write(u64 reg, u32 val)
{
    *(volatile unsigned int *)reg = val; // write val to reg
}
unsigned int mmio_read(u64 reg)
{
    return *(v32 *)reg; // read val from reg
}