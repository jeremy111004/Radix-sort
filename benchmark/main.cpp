#include "../include/radix_sort.hpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <cmath>
int main(void){
	std::vector<long> time_vec {};
	std::vector<long> time_vec2 {};
	std::vector<long> time_vec3 {};
	std::vector<std::vector<long>> time_vec4(5,std::vector<long>(5,0));

	
	for(int i = 0; i<5;i++){
		std::vector<int> test_vec = {};
		for(int z=0;z<10000000;z++){ test_vec.push_back(rand());}
		std::vector<int> test_vec2 = test_vec;
		std::vector<unsigned int> test_vec3(test_vec.begin(), test_vec.end());
		std::vector<unsigned int> test_vec4 = test_vec3;
		// radix 1 
		auto start = std::chrono::high_resolution_clock::now();
		auto res1 = radix_sort(test_vec);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);	
		time_vec.push_back(duration.count());


		//std::sort
		auto start2 = std::chrono::high_resolution_clock::now();
		std::sort(test_vec2.begin(),test_vec2.end());
		auto end2 = std::chrono::high_resolution_clock::now();
		auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2-start2);	
		time_vec2.push_back(duration2.count());

		if(res1!=test_vec2){std::cout << "radix is wrong";}
		
		//radix bytes
		auto start3 = std::chrono::high_resolution_clock::now();
		auto res2 = radix_sort_byte(test_vec3,10000000);
		auto end3 = std::chrono::high_resolution_clock::now();
		auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3-start3);		
		time_vec3.push_back(duration3.count());

		// re cast to check veracity of results
		std::vector<int> res2_int(res2.begin(),res2.end());
		if(res2_int!=test_vec2){std::cout << "radix byte is wrong !!";}

				// radix parallel
		
		std::vector<int> threads = {1,2, 4, 8, 16};
		for (size_t t = 0; t < threads.size(); t++) {
			t_count = t_prefix = t_alloc = t_scatter = 0;
			auto start4 = std::chrono::high_resolution_clock::now();
			auto res3 = radix_sort_byte_parallel(test_vec4, 10000000, threads[t]);
			auto end4 = std::chrono::high_resolution_clock::now();
			auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
			time_vec4[t].push_back(duration4.count());

			// re cast to check veracity of results
			std::vector<int> res3_int(res3.begin(), res3.end());
			if (res3_int != test_vec2) { std::cout << "parallel radix is wrong with " << threads[t] << " threads\n"; }
			std::cout << threads[t] << " threads | count "  << t_count*1e3
          	<< " ms | prefix "  << t_prefix*1e3
          	<< " ms | alloc "   << t_alloc*1e3
          	<< " ms | scatter " << t_scatter*1e3 << " ms\n";
		}
		

	

	}

	double sum1 = 0;
	for(auto t : time_vec){sum1+=t;}
	double sum2 = 0;
	for(auto t : time_vec2){sum2+=t;}
	double sum3 = 0;
	for(auto t : time_vec3){sum3+=t;}
	std::vector<double> vecmean4 = {};
	// for this one i'll compute the mean directly in the for loop for conciseness
	for(auto vec_t : time_vec4){
		vecmean4.push_back((std::accumulate(vec_t.begin(),vec_t.end(),0))/5.0);

				}


	std::cout << "Average basic radix duration : " << sum1/5.0 << " us";

	
	std::cout << "\nAverage std::sort duration : " << sum2/5.0 << " us" ;

	std::cout << "\nAverage bytes radix duration : " << sum3/5.0 << " us" << " and the number of bits used counting sort was " <<  nbr_bit;
	
	for(int i=0;i<=4;i++){
		std::cout << "\nAverage bytes parallel radix duration, using " << pow(2,i) << " threads, was " << vecmean4[i];
	}
	
	}

