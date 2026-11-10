#include "../include/radix_sort.hpp"
#include <algorithm>
#include <vector>
#include <omp.h>
unsigned int find_max_element(const std::vector<unsigned int>& vec,int nmr_t,long long vec_s){
	unsigned int c_max = 0;
	#pragma omp parallel num_threads(nmr_t) 
	{
		unsigned int local_m = 0;
		#pragma omp for schedule(static)
		for(long long i=0; i<vec_s;i++){
			local_m = std::max(local_m,vec[i]);
		}

		#pragma omp critical
		c_max=std::max(local_m,c_max);

	}
return c_max;
} 


