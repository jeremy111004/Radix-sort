CXX      = g++
CXXFLAGS = -O2 -Wall -Wextra -std=c++17 -fopenmp

SRCS = benchmark/main.cpp src/radix_sort_seq.cpp src/radix_sort_byte.cpp src/radix_sort_byte_parallel.cpp 
HDRS = include/radix_sort.hpp

bench: $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) -o bench $(SRCS)

run: bench
	./bench

clean:
	rm -f bench

.PHONY: run clean
