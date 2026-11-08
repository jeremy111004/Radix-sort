#pragma once
#include <vector>

std::vector<int> radix_sort(std::vector<int>& vec);
//byte version
std::vector<unsigned int> radix_sort_byte(std::vector<unsigned int>& vec, int vec_s);
std::vector<unsigned int> counting_sort_byte(const std::vector<unsigned int>& vec, int digit,int vec_s);

//parallel 
std::vector<unsigned int> radix_sort_byte_parallel(std::vector<unsigned int>& vec, int vec_s,int nmr_threads);
std::vector<unsigned int> counting_sort_byte_parallel(const std::vector<unsigned int>& vec, int digit,int vec_s,int nmr_threads);


inline constexpr int nbr_bit = 8;
inline constexpr unsigned mask = (1u << nbr_bit) - 1;


inline unsigned int get_byte(unsigned int x, int digit) {   
	unsigned int key = 0;
        x>>=((digit-1)*nbr_bit);
	key = (x&mask);
    	return key;
}
