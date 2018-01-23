#include <xc.h>
#include <sys/kmem.h>
#include "types.h"
#include "global.h"
#include "sys_devcon.h"

#define PRIVATE static

UINT32 __attribute__((nomips16)) ReadCoreTimer(void)
{
    UINT32 timer;

    timer = __builtin_mfc0(9, 0);

    return timer;
}

void CoreTimer_DelayMS(UINT32 delay_ms)
{
    UINT32 delay_start;

    delay_start = ReadCoreTimer();

    while ((ReadCoreTimer() - delay_start) < (delay_ms * CORE_TIMER_MILLISECONDS));
}

void CoreTimer_DelayUS(UINT32 delay_us)
{
    UINT32 delay_start;

    delay_start = ReadCoreTimer();
    while ((ReadCoreTimer() - delay_start) < (delay_us * CORE_TIMER_MICROSECONDS));
}





