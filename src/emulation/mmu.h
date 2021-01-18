/**
 * Resources for understanding the memory map layout
 * for the gameboy:
 * 
 *  - https://gbdev.gg8.se/wiki/articles/Memory_Map
 *  - https://www.linkedin.com/pulse/creating-gameboy-emulator-part-1-bruno-croci/
 *  - http://blog.alasdairmorrison.com/gameboy-memory-map/
 */

#ifndef _MMU_H
#define _MMU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#include "defs.h"

struct MMU {

  union {
    uint8_t addrspace[_64KB];

    struct {
      uint8_t rom[2][_16KB];      // Game Cartridge
      uint8_t vram[_8KB];         // Video Memory
      uint8_t xram[_8KB];         // External Memory
      uint8_t wram[_8KB];         // Work Memory
      uint8_t eram[_8KB - _512B]; // Echo Memory
      uint8_t oam[_160B];         // Object Attribute Memory (Sprites)
      uint8_t unused[_96B];       // Unusable Memory
      uint8_t io[_128B];          // Input and Output
      uint8_t hram[_127B];        // Zero Page     
      uint8_t interrupts;         // Interrupt Enable Flag
    };
  };

};

typedef struct MMU MMU;

MMU* mmu_create();
void mmu_destroy(MMU* mmu);

uint8_t  mmu_read8_from(MMU* mmu, uint16_t addr);
uint16_t mmu_read16_from(MMU* mmu, uint16_t addr);

void mmu_write8_to(MMU* mmu, uint16_t addr, uint8_t data);
void mmu_write16_to(MMU* mmu, uint16_t addr, uint16_t data);

#endif