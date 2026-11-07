#include "../include/radix_sort.hpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
int main(void){
	std::vector<long> time_vec {};
	std::vector<long> time_vec2 {};
	std::vector<long> time_vec3 {};

	for(int i = 0; i<5;i++){
		std::vector<int> test_vec = {};
		for(int z=0;z<100000;z++){ test_vec.push_back(rand());}
		std::vector<int> test_vec2 = test_vec;
		std::vector<unsigned int> test_vec3(test_vec.begin(), test_vec.end());
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
		if(res1!=test_vec2){std::cout << "radix is wrong";}
		
		//radix bytes
		auto start3 = std::chrono::high_resolution_clock::now();
		auto res2 = radix_sort_byte(test_vec3,100000);
		auto end3 = std::chrono::high_resolution_clock::now();
		auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3-start3);		
		time_vec3.push_back(duration3.count());

		// re cast to check veracity of results
		std::vector<int> res2_int(res2.begin(),res2.end());
		if(res2_int!=test_vec2){std::cout << "radix byte is wrong !!";}

	

	}

	double sum1 = 0;
	for(auto t : time_vec){sum1+=t;}
	double sum2 = 0;
	for(auto t : time_vec2){sum2+=t;}
	double sum3 = 0;
	for(auto t : time_vec3){sum3+=t;}

	std::cout << "Average basic radix duration : " << sum1/5 << " us";


	
	std::cout << "\nAverage std::sort duration : " << sum2/5 << " us" ;

	std::cout << "\nAverage bytes radix duration : " << sum3/5 << " us" << " and the number of bits used counting sort was " <<  nbr_bit;
	
	}

