#include <stdio.h>
#include "x86.h"

int main() {
  x86::code code;
  code << x86::push(x86::ebp);
  code << x86::mov(x86::ebp, x86::esp);
  code << x86::add(x86::edi, x86::esi);
  code << x86::mov(x86::eax, x86::edi);
  code << x86::pop(x86::ebp);
  code << x86::ret();

  auto func = code.finalize<long, long, long>();
  long res = func(1, 2);
  assert(res == 3);
  printf("1 + 2 = %ld\n", res);
}
