#include "../include/radix_sort.hpp"
#include <algorithm>
#include <cstdio>
#include <omp.h>



void counting_sort_byte_parallel(const std::vector<unsigned int>& vec, int digit,int vec_s,int nmr_threads, std::vector<unsigned int>& ans){
	int nmr_el = vec_s;
	int size_cnt = 1u<<nbr_bit;
	std::vector<std::vector<long>> cntVecSliced(nmr_threads,std::vector<long>(size_cnt,0));


	#pragma omp parallel num_threads(nmr_threads)
	{
		int t = omp_get_thread_num();
		auto& localVec = cntVecSliced[t];
		#pragma omp for schedule(static)
		for(auto i : vec){
			unsigned int index = get_byte(i,digit);
			localVec[index]++;
		}
	}

	// this should definitely not be done in parallel
	long long run_tot = 0;
	for(int i =0; i<size_cnt;i++){
		for(int thread=0; thread<nmr_threads;thread++){
			auto& cur_count_slot = cntVecSliced[thread][i];
			long temp = cur_count_slot;
			cur_count_slot = run_tot;
			run_tot += temp;
		}
	}
	#pragma omp parallel num_threads(nmr_threads)
	{
		#pragma omp for schedule(static)
		for(int i = 0;i<nmr_el;i++){
			int t = omp_get_thread_num();
			unsigned int cur_d = vec[i];
			unsigned int index = get_byte(cur_d,digit);
			unsigned int place = cntVecSliced[t][index];
			ans[place] = cur_d;
			cntVecSliced[t][index]++;
		}
	}


	
	
}
void radix_sort_byte_parallel(std::vector<unsigned int>& vec, int vec_s, int nmr_threads){

	std::vector<unsigned int> ans(vec_s,0);

	auto max_e = find_max_element(vec,nmr_threads,vec_s);

	int size = 0;
	while(max_e != 0u){
		max_e >>= (nbr_bit);
		size++;
	}

	for(int i = 1;i<=size;i++){
		counting_sort_byte_parallel(vec, i, vec_s,nmr_threads,ans);
		std::swap(vec,ans);
	}
	
}

