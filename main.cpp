#include <sys/mman.h>
#include <string>
#include <vector>

#include "x86.h"

typedef long(func)(long);

int main() {
  x86::code code;
  code << x86::push(x86::ebp);
  code << x86::mov(x86::ebp, x86::esp);
  code << x86::add(x86::edi, 2);
  code << x86::mov(x86::eax, x86::edi);
  code << x86::pop(x86::ebp);
  code << x86::ret();

  auto func = code.finalize<long, long>();
  long res = func(20);
  printf("20 + 2 = %ld\n", res);
}
