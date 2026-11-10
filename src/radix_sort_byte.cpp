#include "../include/radix_sort.hpp"
#include <algorithm>


void counting_sort_byte(const std::vector<unsigned int>& vec, int digit,long long vec_size,std::vector<unsigned int>& ans){
	int nmr_el = vec_size;
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

	for(int i = nmr_el-1;i>=0;i--){
		unsigned int cur_d = vec[i];
		unsigned int index = get_byte(cur_d,digit);
		unsigned int place = cntVec[index];
		cntVec[index]--;
		ans[place-1] = cur_d;
	}	
}
void radix_sort_byte(std::vector<unsigned int>& vec, long long vec_size){	
	unsigned int max_e = 0;
	for (std::size_t i = 0; i < vec.size(); i++) max_e = std::max(max_e, vec[i]);
	int size = 0;
	while(max_e != 0u){
		max_e >>= (nbr_bit);
		size++;
	}
	std::vector<unsigned int> ans(vec_size,0);

	for(int i = 1;i<=size;i++){
		counting_sort_byte(vec, i, vec_size,ans);
		std::swap(vec,ans);
	}
	
}
