#include <xc.h>
#include <sys/kmem.h>
#include <string.h>
#include "types.h"
#include "global.h"
#include "sys_devcon.h"
#include "flash_operation.h"

#define PRIVATE static

/* Private variables */
PRIVATE UINT32 __attribute__((coherent)) row_buff[PFM_ROW_WSIZE];

/* Private Functions */
PRIVATE void FlashInitWrite(void);
PRIVATE void FlashErrorClear(void);

PRIVATE void FlashInitWrite(void)
{
    volatile UINT32 int_status;
    volatile UINT32 dma_suspend;

    int_status = __builtin_get_isr_state();
    __builtin_disable_interrupts();

    dma_suspend = DMACONbits.SUSPEND;
    if (dma_suspend == 0)
    {
        DMACONSET = BIT_12;
        while (DMACONbits.DMABUSY == 1);
    }

    NVMKEY = 0;
    NVMKEY = 0xAA996655;
    NVMKEY = 0x556699AA;
    NVMCONSET = BIT_15;

    if (dma_suspend == 0)
    {
        DMACONCLR = BIT_12;
    }

    __builtin_set_isr_state(int_status);
}

void BootFlashWriteEnable(void)
{
    volatile UINT32 int_status;
    volatile UINT32 dma_suspend;

    int_status = __builtin_get_isr_state();
    __builtin_disable_interrupts();

    dma_suspend = DMACONbits.SUSPEND;
    if (dma_suspend == 0)
    {
        DMACONSET = BIT_12;
        while (DMACONbits.DMABUSY == 1);
    }

    NVMBWPSET = BIT_7 | BIT_15;

    NVMKEY = 0;
    NVMKEY = 0xAA996655;
    NVMKEY = 0x556699AA;
    NVMBWPCLR = 0x1F1F;

    if (dma_suspend == 0)
    {
        DMACONCLR = BIT_12;
    }

    __builtin_set_isr_state(int_status);
}

PRIVATE void FlashErrorClear(void)
{
    if (NVMCONbits.WRERR == 1 || NVMCONbits.LVDERR == 1)
    {
        NVMCONbits.NVMOP = 0x00;
        NVMCONSET = BIT_14;

        FlashInitWrite();
        while (NVMCONbits.WR != 0); /* Wait for WR bit to clear */

        NVMCONCLR = BIT_14; /* Disable Flash Write */
    }
}

UINT32 FlashPageErase(void *page_addr)
{
    UINT32 status;

    FlashErrorClear();

    NVMADDR = KVA_TO_PA(page_addr); /* page physical address */

    NVMCONbits.NVMOP = 0x4; /* page erase operation */
    NVMCONSET = BIT_14; /* Enable Flash Write */

    FlashInitWrite();
    while (NVMCONbits.WR != 0); /* Wait for WR bit to clear */

    NVMCONCLR = BIT_14; /* Disable Flash Write */

    status = NVMCON & 0x3000;

    return status;
}

UINT32 FlashRowWrite(void *dest, void *src, UINT32 len)
{
    UINT32 status;

    FlashErrorClear();

    if (len > PFM_ROW_BSIZE)
    {
        len = PFM_ROW_BSIZE;
    }

    memset(row_buff, 0xFF, sizeof row_buff);
    memcpy(row_buff, src, len);

    NVMADDR = KVA_TO_PA(dest);
    NVMSRCADDR = KVA_TO_PA(row_buff);
    NVMCONbits.NVMOP = 0x3;
    NVMCONSET = BIT_14;

    FlashInitWrite();
    while (NVMCONbits.WR != 0); /* Wait for WR bit to clear */

    NVMCONCLR = BIT_14; /* Disable Flash Write */

    status = NVMCON & 0x3000;

    return status;
}

UINT32 FlashQWordWrite(void *dest, UINT32 wd0, UINT32 wd1, UINT32 wd2, UINT32 wd3)
{
    UINT32 status;

    FlashErrorClear();

    NVMADDR = KVA_TO_PA(dest);
    NVMDATA0 = wd0;
    NVMDATA1 = wd1;
    NVMDATA2 = wd2;
    NVMDATA3 = wd3;
    NVMCONbits.NVMOP = 0x2;
    NVMCONSET = BIT_14;

    FlashInitWrite();
    while (NVMCONbits.WR != 0); /* Wait for WR bit to clear */

    NVMCONCLR = BIT_14; /* Disable Flash Write */

    status = NVMCON & 0x3000;

    return status;
}




