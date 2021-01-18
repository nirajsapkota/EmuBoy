#ifndef _CPU_H
#define _CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#include "mmu.h"

#define ZERO_FLAG 0b10000000;
#define SUBTRACT_FLAG 0b0100000;
#define HALF_CARRY_FLAG 0b00100000;
#define CARRY_FLAG 0b00010000;

struct CPU {

  union {
    uint8_t reg[4];
    
    struct {
      uint8_t AF[2];
      uint8_t BC[2];
      uint8_t DE[2];
      uint8_t HL[2];
    };
  };

  uint16_t PC;
  uint16_t SP;

  uint8_t flags;
  MMU* mmu;

};

typedef struct CPU CPU;

CPU* cpu_create();
void cpu_destroy(CPU* cpu);

void cpu_attach_mmu(CPU* cpu, MMU* mmu);
void cpu_start(CPU* cpu);

void cpu_fetch_instruction(CPU* cpu);
void cpu_decode_instruction(uint16_t opcode);

void cpu_execute_load8_immediate(CPU* cpu, uint8_t reg, uint8_t which, uint8_t immediate);
void cpu_execute_load16_immediate(CPU* cpu, uint8_t reg, uint16_t immediate);
void cpu_execute_add(CPU* cpu, uint8_t reg);

#endif