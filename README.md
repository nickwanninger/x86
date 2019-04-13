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
```
