#pragma once
#include <vector>
unsigned int find_max_element(const std::vector<unsigned int>& vec,int nmr_t,long long vec_s);
void radix_sort(std::vector<unsigned int>& vec, long long vec_size);
//byte version
void radix_sort_byte(std::vector<unsigned int>& vec, long long vec_size);
void counting_sort_byte(const std::vector<unsigned int>& vec, int digit,long long vec_size,std::vector<unsigned int>& ans);

//parallel 
void radix_sort_byte_parallel(std::vector<unsigned int>& vec, int vec_s,int nmr_threads);
void counting_sort_byte_parallel(const std::vector<unsigned int>& vec, int digit,int vec_s,int nmr_threads);


inline constexpr int nbr_bit = 8;
inline constexpr unsigned mask = (1u << nbr_bit) - 1;


inline unsigned int get_byte(unsigned int x, int digit) {   
	unsigned int key = 0;
        x>>=((digit-1)*nbr_bit);
	key = (x&mask);
    	return key;
}


