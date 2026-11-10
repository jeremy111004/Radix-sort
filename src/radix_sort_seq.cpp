#include <algorithm>
#include "../include/radix_sort.hpp"
#include <algorithm>

unsigned int get_digit(int x, int digit) {        
	int key = 0;
    for (int d = 0; d < digit; d++) {
        key = x % 10;
        x /= 10;
    }
    return key;
}
void counting_sort(const std::vector<unsigned int>& vec, int digit,std::vector<unsigned int>& ans,long long vec_size){	
	std::vector<int> cntVec(10,0);

	for(auto i : vec){
		// here i want to select the appropriate digit for the count.		
		int index = get_digit(i,digit);
		cntVec[index]++;
		// now me cntVec is fullfiled with count for only the xth digit.
	}

	for(int i = 1; i<10;i++){
		cntVec[i] += cntVec[i-1];
	}	
	for(int i = vec_size-1;i>=0;i--){
		int cur_d = vec[i];
		int index = get_digit(cur_d,digit);
		int place = cntVec[index];
		cntVec[index]--;
		ans[place-1] = cur_d;
	}
	


}
void radix_sort(std::vector<unsigned int>& vec,long long vec_size){
	if(vec_size==0)return;
	unsigned int max_el = 0;
	for (std::size_t i = 0; i < vec.size(); i++) max_el= std::max(max_el, vec[i]);
	int size = 0;
	while(max_el!=0){
		max_el/=10;
		size++;
	}

	std::vector<unsigned int> ans(vec_size,0);
	for(int i = 1; i<=size;i++){
		// loop for each digit;
		counting_sort(vec, i,ans,vec_size);
		std::swap(vec,ans);
	}
}


