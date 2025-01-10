#include "include/timer.h"

void sleep(u32 time)
{
    for (volatile int i = 0; i < time; i++)
        ;

    return;
}
