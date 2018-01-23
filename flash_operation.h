#ifndef FLASH_OPERATION_H
#define	FLASH_OPERATION_H

#define PFM_WORD_SIZE   4                                   /* 4B per instruction word */
#define PFM_WD_PER_QW   4                                   /* 4 instruction words per qw */
#define PFM_QW_BSIZE    (PFM_WD_PER_QW * PFM_WORD_SIZE)     /* 16B per qw */
#define PFM_QW_PER_ROW  128                                 /* 128 qw per row */
#define PFM_ROW_BSIZE   (PFM_QW_PER_ROW * PFM_QW_BSIZE)     /* 2048 bytes per row */
#define PFM_ROW_WSIZE   (PFM_QW_PER_ROW * PFM_WD_PER_QW)    /* row size in words */
#define PFM_ROW_PER_PAGE    8                               /* 8 rows per page */
#define PFM_PAGE_BSIZE  (PFM_ROW_PER_PAGE * PFM_ROW_BSIZE)  /* 16KB per page */

void BootFlashWriteEnable(void);
UINT32 FlashPageErase(void *page_addr);
UINT32 FlashRowWrite(void *dest, void *src, UINT32 len);
UINT32 FlashQWordWrite(void *dest, UINT32 wd0, UINT32 wd1, UINT32 wd2, UINT32 wd3);

#endif	/* FLASH_OPERATION_H */

