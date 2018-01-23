/* 
 * File:   debug_port.h
 * Author: achen
 *
 * Created on March 11, 2015, 10:10 AM
 */

#ifndef DEBUG_PORT_H
#define	DEBUG_PORT_H

#include <stdarg.h>
#include "types.h"
#include "ports.h"

#define DEBUG_TX_PIN    BIT_6
#define DEBUG_TX_PORT   IOPORT_B

void DbgLog_Init(void);

#endif	/* DEBUG_PORT_H */

