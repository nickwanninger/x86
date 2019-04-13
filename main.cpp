// Example file, used while in development for quick testing and debugging

#include <stdio.h>
#include "x86.h"

int main() {


  // create a code object
  x86::code code;

  // fill out the instructions
  code.prologue(); // prologue of the function, setup stack frame
  code << x86::add(x86::edi, x86::esi);
  code << x86::mov(x86::eax, x86::edi);
  code.epilogue(); // pop rbp and return

  // print the x86 mnemonics (using capstone)
  code.dump();


  // finalize the function and call it!
  auto func = code.finalize<long, long, long>();
  long res = func(1, 2);
  assert(res == 3);
  printf("1 + 2 = %ld\n", res);
}
