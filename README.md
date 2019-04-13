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
	// typical x86 prologue
	code << x86::push(x86::ebp);
	code << x86::mov(x86::ebp, x86::esp);

	// add the two arguments together a += b
	code << x86::add(x86::edi, x86::esi);
	// move the result into eax (the return register)
	code << x86::mov(x86::eax, x86::edi);

	// typical x86 epilogue
	code << x86::pop(x86::ebp);
	code << x86::ret(); // return

	// create a function that is of the form `long func(long, long);`
	auto func = code.finalize<long, long, long>();

	// call it!
	long res = func(1, 2);
	assert(res == 3);
	printf("1 + 2 = %ld\n", res);
}
```
