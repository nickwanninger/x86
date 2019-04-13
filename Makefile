default: x86.o
	clang++ -O3 -std=c++17 -o jit main.cpp x86.o -lcapstone


x86.o: x86.cpp x86.h
	clang++ -O3 -c -std=c++17 -o x86.o x86.cpp

clean:
	rm x86.o
	rm jit
