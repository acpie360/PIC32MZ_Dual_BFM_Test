#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "sys_devcon.h"
#include "global.h"
#include "core_timer.h"
#include "flash_operation.h"
#include "debug_port.h"

#define PRIVATE static

#pragma config TSEQ = 0xFFFF
#pragma config CSEQ = 0xFFFF

#define LBA_START_LOC       0x9FC00000
#define LBA_END_LOC         0x9FC14000
#define UBA_OFFSET          0x20000
#define UBA_BFSEQ_QW        0x9FC2FFF0
#define UBA_SEQ_LOC         0x9FC2FFFC

#define LBA_BFSEQ_QW_START  0x9FC0FFF0
#define LBA_BFSEQ_QW_END    0x9FC0FFFC

UINT32 RowBuf[PFM_ROW_WSIZE];
volatile UINT32 bf1seq3;
volatile UINT32 bf2seq3;
UINT32 __attribute__((persistent)) run_count;


/* Private Functions */
PRIVATE void PIC32MZ_CPU_Init(void);
PRIVATE void PIC32MZ_IO_Init(void);

PRIVATE void PIC32MZ_CPU_Init(void)
{
    /* Set system cache policy */
    SYS_DEVCON_CacheCoherencySet(SYS_CACHE_WRITEBACK_WRITEALLOCATE);

    /* Flush both I-Cache and D-Cache */
    SYS_DEVCON_CacheFlush();

    DMACON = 0;

    /* Disable global interrupt */
    __builtin_disable_interrupts();

    /* Disable JTAG port */
    CFGCONbits.JTAGEN = 0;

    /* Enable predictive prefetch for any address
     * 4 Flash Wait State for 200MHz SYSCLK
     */
    PRECONbits.PREFEN = 3;
    PRECONbits.PFMWS = 4;
    
    /* Unlock */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    
    OSCTUN = 0; /* FRC runs at minimal frequency 8MHz */
    
    /* PBCLK8: EBI */
    while (PB8DIVbits.PBDIVRDY == 0);
    PB8DIVbits.PBDIV = PBCLK8_PBDIV;
    PB8DIVbits.ON = 1;

    /* PBCLK7: CPU, Deadman Timer */
    while (PB7DIVbits.PBDIVRDY == 0);
    PB7DIVbits.PBDIV = PBCLK7_PBDIV;
    PB7DIVbits.ON = 1;

    /* PBCLK5: Flash, Crypto, RNG, USB, CAN, Ethernet, SQI */
    while (PB5DIVbits.PBDIVRDY == 0);
    PB5DIVbits.PBDIV = PBCLK5_PBDIV;
    PB5DIVbits.ON = 1;

    /* PBCLK4: Ports */
    while (PB4DIVbits.PBDIVRDY == 0);
    PB4DIVbits.PBDIV = PBCLK4_PBDIV;
    PB4DIVbits.ON = 1;

    /* PBCLK3: ADC, Comparator, Timers, Output Compare, Input Capture */
    while (PB3DIVbits.PBDIVRDY == 0);
    PB3DIVbits.PBDIV = PBCLK3_PBDIV;
    PB3DIVbits.ON = 1;

    /* PBCLK2: PMP, I2C, UART, SPI */
    while (PB2DIVbits.PBDIVRDY == 0);
    PB2DIVbits.PBDIV = PBCLK2_PBDIV;
    PB2DIVbits.ON = 1;

    /* PBCLK1: Always ON */
    while (PB1DIVbits.PBDIVRDY == 0);
    PB1DIVbits.PBDIV = PBCLK1_PBDIV;

    /* Configue Reference Clock Outputs */
    REFO1CON = 0;
    REFO2CON = 0;
    REFO3CON = 0;
    REFO4CON = 0;
    
    /* Lock */
    SYSKEY = 0x33333333;

    /* Configure SRS Priority Selection */
    PRISSbits.SS0 = 0;
    PRISSbits.PRI1SS = 1;
    PRISSbits.PRI2SS = 2;
    PRISSbits.PRI3SS = 3;
    PRISSbits.PRI4SS = 4;
    PRISSbits.PRI5SS = 5;
    PRISSbits.PRI6SS = 6;
    PRISSbits.PRI7SS = 7;

    /* Enable multi vector mode */
    INTCONbits.MVEC = 1;

    /* Enable global interrupt */
    __builtin_enable_interrupts();    
}

PRIVATE void PIC32MZ_IO_Init(void)
{
    UINT32 status;
    
    /* All ports set to digital (100-pin device) */
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    ANSELG = 0;
    
    status = __builtin_get_isr_state();
    __builtin_disable_interrupts();
    
    /* Unlock */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    CFGCONbits.IOLOCK = 0;      /* Unlock IOLOCK */
    
    /* SPI1 for SPI FLASH */
    RPB10Rbits.RPB10R = 0b0101; /* RPB10 -> SDO1 */
    SDI1Rbits.SDI1R = 0b0101;   /* SDI1 -> RPB9 */
    
    /* Debug Port */
    RPB6Rbits.RPB6R = 0b0010;   /* RPB6 -> U2TX */
    U2RXRbits.U2RXR = 0b1101;   /* U2RX -> RPE9 */
    
    /* Lock */
    SYSKEY = 0x33333333;
        
    __builtin_set_isr_state(status);
}

PRIVATE UINT32 GetCurrentBFMbank(void)
{
    UINT32 cur_bank = 0;

    if (NVMCONbits.BFSWAP == 0)
        cur_bank = 1;
    else
        cur_bank = 2;
    
    return cur_bank;
}

PRIVATE UINT32 GenNewFSEQ(UINT32 seq1, UINT32 seq2)
{
    UINT32_VAL temp1, temp2, new_seq;
    BOOL valid1, valid2;

    temp1.Val = seq1;
    temp2.Val = seq2;

    valid1 = FALSE;
    valid2 = FALSE;

    if ((temp1.word.LW + temp1.word.HW) == 0xFFFF)
    {
        valid1 = TRUE;
    }

    if ((temp2.word.LW + temp2.word.HW) == 0xFFFF)
    {
        valid2 = TRUE;
    }

    if (valid1 == TRUE && valid2 == TRUE)
    {
        if (temp1.word.LW >= temp2.word.LW)
        {
            new_seq.word.LW = temp1.word.LW + 1;
        }
        else
        {
            new_seq.word.LW = temp2.word.LW + 1;
        }
    }
    else if (valid1 == TRUE)
    {
        new_seq.word.LW = temp1.word.LW + 1;
    }
    else if (valid2 == TRUE)
    {
        new_seq.word.LW = temp2.word.LW + 1;
    }
    else
    {
        new_seq.word.LW = 0;
    }

    new_seq.word.HW = 0xFFFF - new_seq.word.LW;

    return new_seq.Val;
}

int main(void)
{
    UINT32 new_bfseq;
    UINT32 status;
    UINT32 *virAddr, *rowStart;
    int i;
   
    PIC32MZ_CPU_Init(); /* Initialize CPU */
    PIC32MZ_IO_Init();  /* Initialize IO ports */
    DbgLog_Init();      /* Initialize UART2 for printf */

    /* Clear count if it is a POR or BOR */
    if ((RCON & (BIT_0 | BIT_1)) != 0)
    {
        run_count = 0;
        RCONCLR = BIT_0 | BIT_1;
    }
    printf("\n\r\n\r");
    printf("Program Run Count = %u\n\r", run_count++);

    /* Read current FBSEQs */
    bf1seq3 = BF1SEQ3;
    bf2seq3 = BF2SEQ3;
    printf("BF1SEQ3 = 0x%08X\n\r", bf1seq3);
    printf("BF2SEQ3 = 0x%08X\n\r", bf2seq3);
    status = GetCurrentBFMbank();
    printf("BF%1u is mapped to Low Boot Alias\n\r", status);

    printf("Replicate current code to Upper Boot Alias...");
    BootFlashWriteEnable();    /* Unprotect all Upper Boot Alias pages */

    virAddr = (UINT32 *)LBA_START_LOC;
    while (virAddr < (UINT32 *)LBA_END_LOC)
    {
        if (((UINT32)virAddr % PFM_PAGE_BSIZE) == 0)
        {
            FlashPageErase((void *)((UINT32)virAddr + UBA_OFFSET));
        }

        for (i = 0, rowStart = virAddr; i < PFM_ROW_WSIZE; i++)
        {
            /* Ignore the 4 QW that contains the BFSEQ number and replace with all FFs */
            if (rowStart >= (UINT32 *)LBA_BFSEQ_QW_START
                    && rowStart <= (UINT32 *)LBA_BFSEQ_QW_END)
            {
                RowBuf[i] = 0xFFFFFFFF;
            }
            else
            {
                RowBuf[i] = *rowStart;
            }

            rowStart++;
        }

        FlashRowWrite((void *)((UINT32)virAddr + UBA_OFFSET), RowBuf, PFM_ROW_BSIZE);

        virAddr += PFM_ROW_WSIZE;
    }
    printf("Done!\n\r");
    
    /* Write the new BF2SEQ0 using the Upper Boot Alias address 0x1FC2FFFC */
    new_bfseq = GenNewFSEQ(bf1seq3, bf2seq3);
    printf("Write new sequence = 0x%08X\n\r", new_bfseq);

    /* This is a mystery. No idea why I need to write the new sequence number
     * to all four quad words starting at 0x9FC2FFF0. Otherwise the BF bank
     * switching won't work.
     */
    status = FlashQWordWrite((void *)UBA_BFSEQ_QW,
                            new_bfseq, new_bfseq, new_bfseq, new_bfseq);

    if (status != 0)
    {
        printf("New BF2SEQ3 Write Failed\n\r");
        printf("\n\r\n\r");
        while (1);
    }

    while (1)
    {
        /* Wait 10 secod and reset */
        CoreTimer_DelayMS(10000);
        SoftReset();
    }
    
    return (0);
}

