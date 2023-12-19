#ifndef PMM_H
#define PMM_H

#include <stdint.h>

#include "../multiboot.h"

/*
 * 4 GiB / 4KiB = 1 MiB (number of pages)
 * 1 MiB / 8 bytes = 131072 bytes = 0x20000 (sizeof bitmap)
 */
#define MAX_NUM_OF_PAGE_FRAMES 0x100000  /* 1 MiB */
/* NOTE: Switching this to 32 may improve performance */
#define SIZE_OF_BITMAP         MAX_NUM_OF_PAGE_FRAMES / WORD_LENGTH
#define KERNEL_START           0x100000  /* 1 MiB */
#define PAGE_FRAME_SIZE        4096      /* 4 KiB */

#define WORD_OFFSET(b) ((b) / WORD_LENGTH)
#define BIT_OFFSET(b)  ((b) % WORD_LENGTH)

void pmm_init(multiboot_info_t* mbi);
uint32_t pmm_get_used_memory();
uint32_t pmm_get_reserved_memory();
void pmm_decrement_used_memory(uint32_t n);
void pmm_increment_used_memory(uint32_t n);

uint32_t pmm_alloc_frame();
void pmm_set_frame(uint32_t frame);
void pmm_clear_frame(uint32_t frame);
uint8_t pmm_get_frame(uint32_t frame);

#endif /* #ifndef PMM_H */
