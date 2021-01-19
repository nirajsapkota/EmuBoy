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
    uint8_t reg[8];
    
    struct {
      uint8_t A; // 0
      uint8_t F; // 1
      uint8_t B; // 2
      uint8_t C; // 3
      uint8_t D; // 4
      uint8_t E; // 5
      uint8_t H; // 6
      uint8_t L; // 7
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
void cpu_decode_instruction(CPU* cpu, uint8_t instr);

void cpu_row_zero(CPU* cpu, uint8_t col);
void cpu_row_one(CPU* cpu, uint8_t col);
void cpu_row_two(CPU* cpu, uint8_t col);
void cpu_row_three(CPU* cpu, uint8_t col);
void cpu_row_four(CPU* cpu, uint8_t col);
void cpu_row_five(CPU* cpu, uint8_t col);
void cpu_row_six(CPU* cpu, uint8_t col);
void cpu_row_seven(CPU* cpu, uint8_t col);
void cpu_row_eight(CPU* cpu, uint8_t col);
void cpu_row_nine(CPU* cpu, uint8_t col);
void cpu_row_a(CPU* cpu, uint8_t col);
void cpu_row_b(CPU* cpu, uint8_t col);
void cpu_row_c(CPU* cpu, uint8_t col);
void cpu_row_d(CPU* cpu, uint8_t col);
void cpu_row_e(CPU* cpu, uint8_t col);
void cpu_row_f(CPU* cpu, uint8_t col);

void cpu_instr_load(CPU* cpu, uint8_t reg1, uint8_t reg2);
void cpu_instr_add(CPU* cpu, uint8_t reg1, uint8_t reg2);
void cpu_instr_sub(CPU* cpu, uint8_t reg);
void cpu_instr_and(CPU* cpu, uint8_t reg);
void cpu_instr_or(CPU* cpu, uint8_t reg);
void cpu_instr_xor(CPU* cpu, uint8_t reg);
void cpu_instr_inc16(CPU* cpu, uint8_t reg);
void cpu_instr_dec16(CPU* cpu, uint8_t reg);
void cpu_instr_inc8(CPU* cpu, uint8_t reg);
void cpu_instr_dec8(CPU* cpu, uint8_t reg);

#endif