#include "x86.h"

using namespace x86;

void x86::inst::encode(code &c) {
  if (has_rex) {
    c.bytes(rex);
  }
  for (int i = 0; i < opcode_size; i++) {
    c.bytes(opcode[i]);
  }
  if (has_modrm) {
    uint8_t m = 0x00;
    m |= (mod << 6);
    m |= (reg << 3);
    m |= (rm << 0);
    c.bytes(m);
  }
  for (int i = 0; i < disp_size; i++) {
    c.bytes(displacement[i]);
  }
  for (int i = 0; i < imm_size; i++) {
    c.bytes(immediate[i]);
  }
}


void code::prologue() {
  *this << push(ebp);
  *this << mov(ebp, esp);
}


void code::epilogue() {
  *this << x86::pop(x86::ebp);
  *this << ret();
}

