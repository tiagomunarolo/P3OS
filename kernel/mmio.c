#include "include/mmio.h"
#include "include/aux.h"

void mmio_write(v64 reg, u32 val)
{
    *(volatile unsigned int *)reg = val; // write val to reg
}
unsigned int mmio_read(v64 reg)
{
    return *(v32 *)reg; // read val from reg
}