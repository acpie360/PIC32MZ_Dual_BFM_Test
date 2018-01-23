/* 
 * File:   core_timer.h
 * Author: achen
 *
 * Created on March 9, 2015, 3:29 PM
 */
#ifndef CORE_TIMER_H
#define CORE_TIMER_H

UINT32 __attribute__((nomips16)) ReadCoreTimer(void);
void CoreTimer_DelayMS(UINT32 delay_ms);
void CoreTimer_DelayUS(UINT32 delay_us);

#endif	/* CORE_TIMER_H */

