#include "cpu.h"
#include "mmu.h"

int main() 
{
  CPU* cpu = cpu_create();
  MMU* mmu = mmu_create();
  cpu_start(cpu);

  return 0;
}