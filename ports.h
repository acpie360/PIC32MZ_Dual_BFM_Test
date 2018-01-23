/* 
 * File:   ports.h
 * Author: achen
 *
 * Created on November 5, 2015, 3:28 PM
 */

#ifndef PORTS_H
#define	PORTS_H
#include "types.h"

typedef struct
{
	volatile unsigned int	tris;
	volatile unsigned int	trisClr;
	volatile unsigned int	trisSet;
	volatile unsigned int	trisInv;
	volatile unsigned int	port;
	volatile unsigned int	portClr;
	volatile unsigned int	portSet;
	volatile unsigned int	portInv;
	volatile unsigned int	lat;
	volatile unsigned int	latClr;
	volatile unsigned int	latSet;
	volatile unsigned int	latInv;
}PortRegMap;	// port registers layout

typedef enum 
{
    IOPORT_A,
    IOPORT_B,
    IOPORT_C,
    IOPORT_D,
    IOPORT_E,
    IOPORT_F,
    IOPORT_G,
    IOPORT_NUM
} IoPortId;

extern PortRegMap * const PortRegTbl[IOPORT_NUM];

static inline void __attribute__((always_inline)) PORTSetBits(IoPortId id, unsigned int mask)
{
    PortRegTbl[id]->latSet = mask;
}

static inline void __attribute__((always_inline)) PORTClearBits(IoPortId id, unsigned int mask)
{
    PortRegTbl[id]->latClr = mask;
}

static inline void __attribute__((always_inline)) PORTToggleBits(IoPortId id, unsigned int mask)
{
    PortRegTbl[id]->latInv = mask;
}

static inline void __attribute__((always_inline)) PORTSetPinsDigitalIn(IoPortId id, unsigned int mask)
{
    PortRegTbl[id]->trisSet = mask;
}

static inline void __attribute__((always_inline)) PORTSetPinsDigitalOut(IoPortId id, unsigned int mask)
{
    PortRegTbl[id]->trisClr = mask;
}

static inline unsigned int __attribute__((always_inline)) PORTReadBits(IoPortId id, unsigned int mask)
{
    return (PortRegTbl[id]->port & mask);
}

static	inline void	__attribute__((always_inline)) PORTWrite(IoPortId id, unsigned int data)
{
    PortRegTbl[id]->lat = data;
}

static inline unsigned int __attribute__((always_inline)) PORTReadLatch(IoPortId id)
{
    return (PortRegTbl[id]->lat);
}

#endif	/* PORTS_H */

