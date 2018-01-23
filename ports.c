#include <xc.h>
#include "types.h"
#include "ports.h"

PortRegMap * const PortRegTbl[IOPORT_NUM] =
{
    (PortRegMap *)&TRISA,
    (PortRegMap *)&TRISB,
    (PortRegMap *)&TRISC,
    (PortRegMap *)&TRISD,
    (PortRegMap *)&TRISE,
    (PortRegMap *)&TRISF,
    (PortRegMap *)&TRISG
};
