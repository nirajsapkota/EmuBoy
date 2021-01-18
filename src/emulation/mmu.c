#include "mmu.h"

MMU* mmu_create()
{
  MMU* mmu = malloc(sizeof(struct MMU));
  if (mmu == NULL)
  {
    fprintf(stderr, "[mmu.c] Failed to allocate enough memory for MMU, exiting...");
    exit(ENOMEM);
  }

  return mmu;
}

void mmu_destroy(MMU* mmu)
{
  free(mmu);
  mmu = NULL;
}

uint8_t mmu_read8_from(MMU* mmu, uint16_t addr)
{
  return mmu->addrspace[addr];
}

void mmu_write8_to(MMU* mmu, uint16_t addr, uint8_t data)
{
  mmu->addrspace[addr] = data;
}

uint16_t mmu_read16_from(MMU* mmu, uint16_t addr)
{
  uint8_t lo = mmu->addrspace[addr + 1];
  uint8_t hi = mmu->addrspace[addr];
  
  uint16_t result = hi;
  result <<= 8;
  result |= lo;

  return result;
}

void mmu_write16_to(MMU* mmu, uint16_t addr, uint16_t data)
{
  uint8_t lo = data;
  uint8_t hi = data >> 8;

  mmu->addrspace[addr] = hi;
  mmu->addrspace[addr + 1] = lo;
}