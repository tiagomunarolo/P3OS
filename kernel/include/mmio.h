#pragma once

#include "aux.h"

void mmio_write(u64 reg, u32 val);
unsigned int mmio_read(u64 reg);