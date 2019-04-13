# x86
## A quick and dirty x86 JIT library built for C++


### API:
Below is a very simple function which adds it's arguments together
```c
int add(int a, int b) {
	return a + b;
}
```

Using the API provided by x86, it can be created at runtime:
```cpp
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
```


The x86::code object uses RAII for the executable pages of memory and when the
object is deleted, the mapped region is also deleted. Therefore it might be
smart to store the code object on the heap if you plan to 'lose track' of it :)

Finalizing a code object will fail if it was already finalized. If this happens,
the finalize function will throw a `std::logic_error` exception.
