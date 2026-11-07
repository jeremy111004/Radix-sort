CXX = g++
CXXFLAGS = -O2 -Wall -Wextra 
CXXEXELINE = -o bench benchmark/main.cpp src/radix_sort_seq.cpp src/radix_sort_byte.cpp
bench: ./src/radix_sort_seq.cpp ./src/radix_sort_byte.cpp ./include/radix_sort.hpp ./benchmark/main.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXELINE)

run: bench
	./bench

clean: 
	rm -f bench

.PHONY: run clean
