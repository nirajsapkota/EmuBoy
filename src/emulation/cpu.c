#include "cpu.h"

CPU* cpu_create()
{
  CPU* cpu = malloc(sizeof(struct CPU));
  
  if (cpu == NULL)
  {
    fprintf(stderr, "[cpu.c] Failed to allocate enough memory for CPU, exiting...");
    exit(ENOMEM);
  }

  return cpu;
}

void cpu_destroy(CPU* cpu)
{
  free(cpu);
  cpu = NULL;
}

void cpu_attach_mmu(CPU* cpu, MMU* mmu)
{
  cpu->mmu = mmu;
}

void cpu_start(CPU* cpu)
{
  cpu_execute_load_immediate(cpu, 1, 4);
  cpu_execute_add(cpu, 1);
  printf("%u", cpu->reg[0]);
}

void cpu_fetch_instruction(CPU* cpu)
{  
  uint16_t opcode = mmu_read16_from(cpu->mmu, cpu->PC);
  cpu_decode_instruction(opcode);
  cpu->PC += 2;
}

void cpu_decode_instruction(uint16_t opcode)
{
  uint8_t prefix = opcode >> 8;
  uint8_t suffix = opcode;

  uint8_t suffix_hi = opcode >> 4;
  uint8_t suffix_lo = opcode & 0x00FF;

  switch (opcode & 0xFF)
  {
    case opcode & 0xFF:
      break;

    default:
      cpu_execute_nop();
      break;
  }

}

void cpu_execute_load8_immediate(CPU* cpu, uint8_t reg, uint8_t which, uint8_t immediate)
{
  cpu->reg[reg] = immedate;
}

void cpu_execute_load16_immediate(CPU* cpu, uint8_t reg, uint16_t immediate)
{
  cpu->reg[reg] = immediate;
}

void cpu_execute_add(CPU* cpu, uint8_t reg)
{
  cpu->reg[0] += cpu->reg[reg];
  // TODO: fix flags
}
