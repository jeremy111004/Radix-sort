#include <algorithm>
#include "radix_sort_seq.hpp"

int get_digit(int x, int digit) {        
	int key = 0;
    for (int d = 0; d < digit; d++) {
        key = x % 10;
        x /= 10;
    }
    return key;
}
std::vector<int> counting_sort(const std::vector<int>& vec, int digit){
	int nmr_el = vec.size();	
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
	std::vector<int> ans(nmr_el,0);
	for(int i = nmr_el-1;i>=0;i--){
		int cur_d = vec[i];
		int index = get_digit(cur_d,digit);
		int place = cntVec[index];
		cntVec[index]--;
		ans[place-1] = cur_d;
	}
	return ans;


}
std::vector<int> radix_sort(std::vector<int>& vec){
	int max_el = *std::max_element(vec.begin(),vec.end());	
	int size = 0;
	while(max_el!=0){
		max_el/=10;
		size++;
	}

	std::vector<int> ans;
	ans = vec;
	for(int i = 1; i<=size;i++){
		// loop for each digit;
		ans = counting_sort(ans, i);
	
		
	}
	return ans;
}


