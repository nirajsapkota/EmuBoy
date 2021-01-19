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

}

void cpu_fetch_instruction(CPU* cpu)
{  

}

void cpu_decode_instruction(CPU* cpu, uint8_t instr)
{
  uint8_t opcode = instr & 0xFF;
  uint8_t row    = opcode >> 4;
  uint8_t col    = opcode & 0x0F;

  switch (row) {
    case 0x0: cpu_row_zero(cpu, col);  break;
    case 0x1: cpu_row_one(cpu, col);   break;
    case 0x2: cpu_row_two(cpu, col);   break;
    case 0x3: cpu_row_three(cpu, col); break;
    case 0x4: cpu_row_four(cpu, col);  break;
    case 0x5: cpu_row_five(cpu, col);  break;
    case 0x6: cpu_row_six(cpu, col);   break;
    case 0x7: cpu_row_seven(cpu, col); break;
    case 0x8: cpu_row_eight(cpu, col); break;
    case 0x9: cpu_row_nine(cpu, col);  break;
    case 0xA: cpu_row_a(cpu, col);     break;
    case 0xB: cpu_row_b(cpu, col);     break;
    case 0xC: cpu_row_c(cpu, col);     break;
    case 0xD: cpu_row_d(cpu, col);     break;
    case 0xE: cpu_row_e(cpu, col);     break;
    case 0xF: cpu_row_f(cpu, col);     break;
  }
}

void cpu_row_zero(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: cpu_instr_inc16(cpu, 2); break; // inc bc
    case 0x4: cpu_instr_inc8(cpu, 2); break; // inc b
    case 0x5: cpu_instr_dec8(cpu, 2); break; // dec b
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: cpu_instr_dec16(cpu, 2); break; // dec bc
    case 0xC: cpu_instr_inc8(cpu, 3); break; // inc c
    case 0xD: cpu_instr_dec8(cpu, 3); break; // dec
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_one(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: cpu_instr_inc16(cpu, 4); break; // inc de
    case 0x4: cpu_instr_inc8(cpu, 4); break; // inc d
    case 0x5: cpu_instr_dec8(cpu, 4); break; // dec d
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: cpu_instr_dec16(cpu, 4); break; // dec de
    case 0xC: cpu_instr_inc8(cpu, 5); break; // inc e
    case 0xD: cpu_instr_dec8(cpu, 5); break; // dec e
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_two(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: cpu_instr_inc16(cpu, 6); break; // inc hl
    case 0x4: cpu_instr_inc8(cpu, 6); break; // inc h
    case 0x5: cpu_instr_dec8(cpu, 6); break; // dec h
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: cpu_instr_dec16(cpu, 6); break; // dec hl
    case 0xC: cpu_instr_inc8(cpu, 7); break; // inc l
    case 0xD: cpu_instr_dec8(cpu, 7); break; // dec l
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_three(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: break;
    case 0x4: break;
    case 0x5: break;
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_four(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_load(cpu, 2, 2); break; // ld b,b
    case 0x1: cpu_instr_load(cpu, 2, 3); break; // ld b,c
    case 0x2: cpu_instr_load(cpu, 2, 4); break; // ld b,d
    case 0x3: cpu_instr_load(cpu, 2, 5); break; // ld b,e
    case 0x4: cpu_instr_load(cpu, 2, 6); break; // ld b,h
    case 0x5: cpu_instr_load(cpu, 2, 7); break; // ld b,l
    case 0x6: break;
    case 0x7: cpu_instr_load(cpu, 2, 0); break; // ld b,a
    case 0x8: cpu_instr_load(cpu, 3, 2); break; // ld c,b
    case 0x9: cpu_instr_load(cpu, 3, 3); break; // ld c,c
    case 0xA: cpu_instr_load(cpu, 3, 4); break; // ld c,d
    case 0xB: cpu_instr_load(cpu, 3, 5); break; // ld c,e
    case 0xC: cpu_instr_load(cpu, 3, 6); break; // ld c,h
    case 0xD: cpu_instr_load(cpu, 3, 7); break; // ld c,l
    case 0xE: break;
    case 0xF: cpu_instr_load(cpu, 3, 0); break; // ld c,a
  }
}

void cpu_row_five(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_load(cpu, 4, 2); break; // ld d,b
    case 0x1: cpu_instr_load(cpu, 4, 3); break; // ld d,c
    case 0x2: cpu_instr_load(cpu, 4, 4); break; // ld d,d
    case 0x3: cpu_instr_load(cpu, 4, 5); break; // ld d,e
    case 0x4: cpu_instr_load(cpu, 4, 6); break; // ld d,h
    case 0x5: cpu_instr_load(cpu, 4, 7); break; // ld d,l
    case 0x6: break;
    case 0x7: cpu_instr_load(cpu, 4, 0); break; // ld d,a
    case 0x8: cpu_instr_load(cpu, 5, 2); break; // ld e,b
    case 0x9: cpu_instr_load(cpu, 5, 3); break; // ld e,c
    case 0xA: cpu_instr_load(cpu, 5, 4); break; // ld e,d
    case 0xB: cpu_instr_load(cpu, 5, 5); break; // ld e,e
    case 0xC: cpu_instr_load(cpu, 5, 6); break; // ld e,h
    case 0xD: cpu_instr_load(cpu, 5, 7); break; // ld e,l
    case 0xE: break;
    case 0xF: cpu_instr_load(cpu, 5, 0); break; // ld e,a
  }
}

void cpu_row_six(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_load(cpu, 6, 2); break; // ld h,b
    case 0x1: cpu_instr_load(cpu, 6, 3); break; // ld h,c
    case 0x2: cpu_instr_load(cpu, 6, 4); break; // ld h,d
    case 0x3: cpu_instr_load(cpu, 6, 5); break; // ld h,e
    case 0x4: cpu_instr_load(cpu, 6, 6); break; // ld h,h
    case 0x5: cpu_instr_load(cpu, 6, 7); break; // ld h,l
    case 0x6: break;
    case 0x7: cpu_instr_load(cpu, 6, 0); break; // ld h,a
    case 0x8: cpu_instr_load(cpu, 7, 2); break; // ld l,b
    case 0x9: cpu_instr_load(cpu, 7, 3); break; // ld l,c
    case 0xA: cpu_instr_load(cpu, 7, 4); break; // ld l,d
    case 0xB: cpu_instr_load(cpu, 7, 5); break; // ld l,e
    case 0xC: cpu_instr_load(cpu, 7, 6); break; // ld l,h
    case 0xD: cpu_instr_load(cpu, 7, 7); break; // ld l,l
    case 0xE: break;
    case 0xF: cpu_instr_load(cpu, 7, 0); break; // ld l,a
  }
}

void cpu_row_seven(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: break;
    case 0x4: break;
    case 0x5: break;
    case 0x6: break;
    case 0x7: break;
    case 0x8: cpu_instr_load(cpu, 0, 2); break; // ld a,b
    case 0x9: cpu_instr_load(cpu, 0, 3); break; // ld a,c
    case 0xA: cpu_instr_load(cpu, 0, 4); break; // ld a,d
    case 0xB: cpu_instr_load(cpu, 0, 5); break; // ld a,e
    case 0xC: cpu_instr_load(cpu, 0, 6); break; // ld a,h
    case 0xD: cpu_instr_load(cpu, 0, 7); break; // ld a,l
    case 0xE: break;
    case 0xF: cpu_instr_load(cpu, 0, 0); break; // ld a,a
  }
}

void cpu_row_eight(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_add(cpu, 0, 2); break; // add a,b
    case 0x1: cpu_instr_add(cpu, 0, 3); break; // add a,c
    case 0x2: cpu_instr_add(cpu, 0, 4); break; // add a,d
    case 0x3: cpu_instr_add(cpu, 0, 5); break; // add a,e
    case 0x4: cpu_instr_add(cpu, 0, 6); break; // add a,h
    case 0x5: cpu_instr_add(cpu, 0, 7); break; // add a,l
    case 0x6: break;
    case 0x7: cpu_instr_add(cpu, 0, 0); break; // add a,a
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_nine(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_sub(cpu, 2); break; // sub b
    case 0x1: cpu_instr_sub(cpu, 3); break; // sub c
    case 0x2: cpu_instr_sub(cpu, 4); break; // sub d
    case 0x3: cpu_instr_sub(cpu, 5); break; // sub e
    case 0x4: cpu_instr_sub(cpu, 6); break; // sub h
    case 0x5: cpu_instr_sub(cpu, 7); break; // sub l
    case 0x6: break;
    case 0x7: cpu_instr_sub(cpu, 0); break; // sub a
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_a(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_and(cpu, 2); break; // and b
    case 0x1: cpu_instr_and(cpu, 3); break; // and c
    case 0x2: cpu_instr_and(cpu, 4); break; // and d
    case 0x3: cpu_instr_and(cpu, 5); break; // and e
    case 0x4: cpu_instr_and(cpu, 6); break; // and h
    case 0x5: cpu_instr_and(cpu, 7); break; // and l
    case 0x6: break;
    case 0x7: cpu_instr_and(cpu, 0); break; // and a
    case 0x8: cpu_instr_xor(cpu, 2); break; // xor b
    case 0x9: cpu_instr_xor(cpu, 3); break; // xor c
    case 0xA: cpu_instr_xor(cpu, 4); break; // xor d
    case 0xB: cpu_instr_xor(cpu, 5); break; // xor e
    case 0xC: cpu_instr_xor(cpu, 6); break; // xor h
    case 0xD: cpu_instr_xor(cpu, 7); break; // xor l
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_b(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: cpu_instr_or(cpu, 2); break; // or b
    case 0x1: cpu_instr_or(cpu, 3); break; // or c
    case 0x2: cpu_instr_or(cpu, 4); break; // or d
    case 0x3: cpu_instr_or(cpu, 5); break; // or e
    case 0x4: cpu_instr_or(cpu, 6); break; // or h
    case 0x5: cpu_instr_or(cpu, 7); break; // or l
    case 0x6: break;
    case 0x7: cpu_instr_or(cpu, 0); break; // or a
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_c(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: break;
    case 0x4: break;
    case 0x5: break;
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_d(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: break;
    case 0x4: break;
    case 0x5: break;
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_e(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: break;
    case 0x4: break;
    case 0x5: break;
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_row_f(CPU* cpu, uint8_t col)
{
  switch (col) 
  {
    case 0x0: break;
    case 0x1: break;
    case 0x2: break;
    case 0x3: break;
    case 0x4: break;
    case 0x5: break;
    case 0x6: break;
    case 0x7: break;
    case 0x8: break;
    case 0x9: break;
    case 0xA: break;
    case 0xB: break;
    case 0xC: break;
    case 0xD: break;
    case 0xE: break;
    case 0xF: break;
  }
}

void cpu_instr_load(CPU* cpu, uint8_t reg1, uint8_t reg2)
{
  cpu->reg[reg1] = cpu->reg[reg2];
}

void cpu_instr_add(CPU* cpu, uint8_t reg1, uint8_t reg2)
{
  cpu->reg[reg1] += cpu->reg[reg2];
}

void cpu_instr_sub(CPU* cpu, uint8_t reg)
{
  cpu->reg[0] -= cpu->reg[reg];
}

void cpu_instr_and(CPU* cpu, uint8_t reg)
{
  cpu->reg[0] &= cpu->reg[reg];
}

void cpu_instr_or(CPU* cpu, uint8_t reg)
{
  cpu->reg[0] |= cpu->reg[reg];
}

void cpu_instr_xor(CPU* cpu, uint8_t reg)
{
  cpu->reg[0] ^= cpu->reg[reg];
}

void cpu_instr_inc16(CPU* cpu, uint8_t reg)
{
  uint8_t retrieved_hi = cpu->reg[reg];
  uint8_t retrieved_lo = cpu->reg[reg + 1];

  uint16_t incremented = ((retrieved_hi << 8) | retrieved_lo) + 1;
  uint8_t new_hi = incremented >> 8;
  uint8_t new_lo = incremented;

  cpu->reg[reg] = new_hi;
  cpu->reg[reg + 1] = new_lo;
}

void cpu_instr_dec16(CPU* cpu, uint8_t reg)
{
  uint8_t retrieved_hi = cpu->reg[reg];
  uint8_t retrieved_lo = cpu->reg[reg + 1];

  uint16_t decremented = ((retrieved_hi << 8) | retrieved_lo) - 1;

  uint8_t new_hi = decremented >> 8;
  uint8_t new_lo = decremented;

  cpu->reg[reg] = new_hi;
  cpu->reg[reg + 1] = new_lo;
}

void cpu_instr_inc8(CPU* cpu, uint8_t reg)
{
  cpu->reg[reg]++;
}

void cpu_instr_dec8(CPU* cpu, uint8_t reg)
{
  cpu->reg[reg]--;
}