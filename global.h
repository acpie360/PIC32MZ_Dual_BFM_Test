/* 
 * File:   global.h
 * Author: achen
 *
 * Created on March 9, 2015, 2:37 PM
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

/******************************************************************************
 * SYSCLK, PBCLKx and CORE TIMER
 ******************************************************************************/
#define SYSCLK_FREQUENCY            (200000000UL)           /* 200MHz */
#define PBCLK1_FREQUENCY            (20000000UL)            /* 20MHz */
#define PBCLK2_FREQUENCY            (100000000UL)           /* 100MHz */
#define PBCLK3_FREQUENCY            (40000000UL)            /* 40MHz */
#define PBCLK4_FREQUENCY            (20000000UL)            /* 20MHz */
#define PBCLK5_FREQUENCY            (100000000UL)           /* 100MHz */
#define PBCLK7_FREQUENCY            (200000000UL)           /* 200MHz */
#define PBCLK8_FREQUENCY            (100000000UL)           /* 100MHz */

#define CORE_TIMER_FREQUENCY        (PBCLK7_FREQUENCY / 2)
#define CORE_TIMER_MILLISECONDS     (CORE_TIMER_FREQUENCY / 1000)
#define CORE_TIMER_MICROSECONDS     (CORE_TIMER_FREQUENCY / 1000000)

#define PBCLK1_PBDIV                ((SYSCLK_FREQUENCY / PBCLK1_FREQUENCY) - 1)
#define PBCLK2_PBDIV                ((SYSCLK_FREQUENCY / PBCLK2_FREQUENCY) - 1)
#define PBCLK3_PBDIV                ((SYSCLK_FREQUENCY / PBCLK3_FREQUENCY) - 1)
#define PBCLK4_PBDIV                ((SYSCLK_FREQUENCY / PBCLK4_FREQUENCY) - 1)
#define PBCLK5_PBDIV                ((SYSCLK_FREQUENCY / PBCLK5_FREQUENCY) - 1)
#define PBCLK7_PBDIV                ((SYSCLK_FREQUENCY / PBCLK7_FREQUENCY) - 1)
#define PBCLK8_PBDIV                ((SYSCLK_FREQUENCY / PBCLK8_FREQUENCY) - 1)

#endif	/* GLOBAL_H */

