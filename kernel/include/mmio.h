#pragma once

#include "aux.h"

void mmio_write(v64 reg, u32 val);
unsigned int mmio_read(v64 reg);