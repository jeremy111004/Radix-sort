#include "../include/radix_sort.hpp"
#include <algorithm>



static unsigned const int mask = (1u<<nbr_bit)-1;

unsigned int get_byte(unsigned int x, int digit) {   
	unsigned int key = 0;
        x>>=((digit-1)*nbr_bit); // assuming digit 1 means first part of the bit, so if we want digit 1 we actually don't move anything
	key = (x&mask);
    	return key;
}

std::vector<unsigned int> counting_sort_byte(const std::vector<unsigned int>& vec, int digit,int vec_s){
	int nmr_el = vec_s;
	int size_cnt = 1u<<nbr_bit; 
	std::vector<unsigned int> cntVec(size_cnt,0);

	for(auto i : vec){
		// here i want to select the appropriate digit for the count.		
		unsigned int index = get_byte(i,digit);
		cntVec[index]++;
		// now me cntVec is fullfiled with count for only the xth digit.
	}

	for(int i = 1; i<size_cnt;i++){
		cntVec[i] += cntVec[i-1];
	}
	std::vector<unsigned int> ans(nmr_el,0);
	for(int i = nmr_el-1;i>=0;i--){
		unsigned int cur_d = vec[i];
		unsigned int index = get_byte(cur_d,digit);
		unsigned int place = cntVec[index];
		cntVec[index]--;
		ans[place-1] = cur_d;
	}
	return ans;
}
std::vector<unsigned int> radix_sort_byte(std::vector<unsigned int>& vec, int vec_s){
	std::vector<unsigned int> ans = vec;
	auto max_e = *std::max_element(vec.begin(),vec.end());
	int size = 0;
	while(max_e != 0u){
		max_e >>= (nbr_bit);
		size++;
	}

	for(int i = 1;i<=size;i++){
		ans = counting_sort_byte(ans, i, vec_s);
	}
	return ans;
	
}
