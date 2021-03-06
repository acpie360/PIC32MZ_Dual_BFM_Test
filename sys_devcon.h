#ifndef _SYS_DEVCON_H
#define _SYS_DEVCON_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// *****************************************************************************

/* SYS_CACHE_COHERENCY enumeration

   Summary:
    System L1 cache coherency settings.

   Description:
    This enumeration defines the supported system L1 cache coherency settings.

   Remarks:
    Used to read or write cache coherency policy for kseg0.
 */

typedef enum
{
    SYS_CACHE_WRITETHROUGH_NO_WRITEALLOCATE = 0,

    SYS_CACHE_WRITETHROUGH_WRITEALLOCATE = 1,

    SYS_CACHE_DISABLE = 2,

    SYS_CACHE_WRITEBACK_WRITEALLOCATE = 3

} SYS_CACHE_COHERENCY;

void SYS_DEVCON_CacheInit(SYS_CACHE_COHERENCY cacheCoherency);
void SYS_DEVCON_CacheFlush(void);
void SYS_DEVCON_DataCacheFlush(void);
void SYS_DEVCON_InstructionCacheFlush(void);
void SYS_DEVCON_CacheClean(uint32_t addr, size_t len);
void SYS_DEVCON_DataCacheClean(uint32_t addr, size_t len);
void SYS_DEVCON_DataCacheInvalidate(uint32_t addr, size_t len);
void SYS_DEVCON_InstructionCacheInvalidate(uint32_t addr, size_t len);
void SYS_DEVCON_InstructionCacheLock(uint32_t addr, size_t len);
void SYS_DEVCON_DataCacheLock(uint32_t addr, size_t len);
void SYS_DEVCON_CacheSync(uint32_t addr, size_t len);
void SYS_DEVCON_CacheCoherencySet(SYS_CACHE_COHERENCY cacheCoherency);
SYS_CACHE_COHERENCY SYS_DEVCON_CacheCoherencyGet(void);
size_t SYS_DEVCON_DataCacheAssociativityGet(void);
size_t SYS_DEVCON_InstructionCacheAssociativityGet(void);
size_t SYS_DEVCON_DataCacheLineSizeGet(void);
size_t SYS_DEVCON_InstructionCacheLineSizeGet(void);
size_t SYS_DEVCON_DataCacheLinesPerWayGet(void);
size_t SYS_DEVCON_InstructionCacheLinesPerWayGet(void);
size_t SYS_DEVCON_DataCacheSizeGet(void);
size_t SYS_DEVCON_InstructionCacheSizeGet(void);
void __attribute__((noreturn)) SoftReset(void);



void __attribute__((far)) _pic32_init_cache(SYS_CACHE_COHERENCY cacheCoherency);
void __attribute__((far)) _pic32_size_cache(void);

void __attribute__((far)) _pic32_flush_cache(void);
void __attribute__((far)) _pic32_flush_dcache(void);
void __attribute__((far)) _pic32_flush_icache(void);

void __attribute__((far)) _pic32_sync_icache(uint32_t, size_t);

void __attribute__((far)) _pic32_clean_cache(uint32_t, size_t);
void __attribute__((far)) _pic32_clean_dcache(uint32_t, size_t);
void __attribute__((far)) _pic32_clean_dcache_nowrite(uint32_t, size_t);
void __attribute__((far)) _pic32_clean_icache(uint32_t, size_t);

void __attribute__((far)) _pic32_lock_dcache(uint32_t, size_t);
void __attribute__((far)) _pic32_lock_icache(uint32_t, size_t);

size_t __attribute__((far)) _pic32_get_dcache_associativity(void);
size_t __attribute__((far)) _pic32_get_icache_associativity(void);
size_t __attribute__((far)) _pic32_get_dcache_linesize(void);
size_t __attribute__((far)) _pic32_get_icache_linesize(void);
size_t __attribute__((far)) _pic32_get_dcache_lines_per_way(void);
size_t __attribute__((far)) _pic32_get_icache_lines_per_way(void);
size_t __attribute__((far)) _pic32_get_dcache_size(void);
size_t __attribute__((far)) _pic32_get_icache_size(void);

void __attribute__((noreturn)) SoftReset(void);

#define EnableWDT() (WDTCONSET = _WDTCON_ON_MASK)
#define DisableWDT() (WDTCONCLR = _WDTCON_ON_MASK)
#define ClearWDT()  (WDTCONbits.WDTCLRKEY = 0x5743)

#endif
