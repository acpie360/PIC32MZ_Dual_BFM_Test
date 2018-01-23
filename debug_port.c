#include <xc.h>
#include <sys/kmem.h>
#include <string.h>
#include <stdio.h>
#include "types.h"
#include "global.h"
#include "sys_devcon.h"
#include "core_timer.h"
#include "debug_port.h"

#define PRIVATE static

#define BAUDRATE                (115200UL)
#define DBGLOG_BUFFER_SIZE      80

PRIVATE void DbgLog_InitUart(void)
{
    /* Reset UART2 */
    U2MODE = 0;
    U2STA = 0;
        
    /* Initialize UART2 */
    U2BRG = ((PBCLK2_FREQUENCY / BAUDRATE) / 4) - 1;
    U2MODESET = _U2MODE_ON_MASK | _U2MODE_RTSMD_MASK | _U2MODE_BRGH_MASK;
    U2STASET = _U2STA_UTXEN_MASK;
    
    setbuf(stdout, NULL);
}

void _mon_putc(char c)
{
   while (U2STAbits.UTXBF);
   U2TXREG = c;
}

void DbgLog_Init(void)
{
    PORTSetBits(DEBUG_TX_PORT, DEBUG_TX_PIN);
    PORTSetPinsDigitalOut(DEBUG_TX_PORT, DEBUG_TX_PIN);
    
    DbgLog_InitUart();
}

void DbgLog_WaitLastTxComplete(void)
{
    CoreTimer_DelayMS(2);
}