#include "../include/radix_sort_seq.hpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
int main(void){
	std::vector<long> time_vec {};
	std::vector<long> time_vec2 {};

	for(int i = 0; i<5;i++){
		std::vector<int> test_vec = {};
		for(int z=0;z<100000;z++){ test_vec.push_back(rand());}
		std::vector<int> test_vec2 = test_vec;
		auto start = std::chrono::high_resolution_clock::now();
		auto res1 = radix_sort(test_vec);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);		

		time_vec.push_back(duration.count());

		auto start2 = std::chrono::high_resolution_clock::now();
		std::sort(test_vec2.begin(),test_vec2.end());
		auto end2 = std::chrono::high_resolution_clock::now();
		auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2-start2);		
		
		time_vec2.push_back(duration2.count());
		if(res1!=test_vec2){std::cout << "radix is wrong";

	

	}}
	std::cout << "\nbasic radix duration :\n";
	for(auto t : time_vec){std::cout << t << " " ;}
	std::cout << "\nstd::sort duration :\n";
	for(auto t : time_vec2){std::cout << t << " " ;}

	

}
