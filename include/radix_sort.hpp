#pragma once
#include <vector>
std::vector<int> radix_sort(std::vector<int>& vec);
constexpr int nbr_bit = 4;
//byte version
std::vector<unsigned int> radix_sort_byte(std::vector<unsigned int>& vec, int vec_s);
std::vector<unsigned int> counting_sort_byte(const std::vector<unsigned int>& vec, int digit,int vec_s);
unsigned int get_byte(unsigned int x, int digit); 
