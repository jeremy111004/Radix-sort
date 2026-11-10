#include "../include/radix_sort.hpp"
#include <chrono>
#include <functional>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <functional>


int main(int argc, char* argv[]){
	std::string algo = "decimal";
    	int nmr_threads = 16; // if nothing is specified then we use 16
   	long vec_size = 10000000; // arbitrary value that works well for demonstration purposes.

    	if(argc>1){algo= std::string(argv[1]);}
    	if(argc>2){vec_size =std::stoi(argv[2]);}
    	if(argc>3){nmr_threads= std::stoi(argv[3]);}

    	if(nmr_threads<1){std::cout << "Wrong number of threads used !\n"; return 1;}
    	if( algo!="parallel" && algo!="std" && algo!="sequential" && algo!="decimal"){std::cout  << "Wrong algorithm specified !\n"; return 1;}	

	std::function<void(std::vector<unsigned int>&)> sort_fn;
    	
	if(algo == "parallel"){
		sort_fn = [&](std::vector<unsigned int>& vec){radix_sort_byte_parallel(vec, vec_size, nmr_threads);}
		;}
	else if(algo == "sequential"){sort_fn = [&](std::vector<unsigned int>& vec){radix_sort_byte(vec, vec_size);};}

	else if(algo == "std"){sort_fn = [](std::vector<unsigned int>& vec){std::sort(vec.begin(),vec.end());};}
	else if(algo == "decimal"){sort_fn = [&](std::vector<unsigned int>& vec){radix_sort(vec, vec_size);};}			

	std::vector<int> time_vec;	

	for(int i = 0; i<5;i++){

		std::vector<unsigned int> test_vec = {};
		for(unsigned int z=0;z<vec_size;z++){ 
			test_vec.push_back(rand());}
		auto start = std::chrono::high_resolution_clock::now();
		sort_fn(test_vec);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);	
		time_vec.push_back(duration.count());
		if(!std::is_sorted(test_vec.begin(),test_vec.end())){std::cout << "Sorting failed !\n"; return 1;}

	}

	
	double sum1 = 0;
	for(auto t : time_vec){sum1+=t;}	
	if(algo == "decimal" || algo  == "sequential" || algo == "std"){
		std::cout << "\nMean duration of " << algo << " to sort a vector that was "<< vec_size*sizeof(unsigned int) << " bytes over 5 runs was " << sum1/5.0 << "us using one thread.\n";

	}
	else{
		std::cout << "\nMean duration of " << algo << " to sort a vector that was "<< vec_size*sizeof(unsigned int) << " bytes over 5 runs was " << sum1/5.0 << "us using " << nmr_threads << " threads.\n" ;
	}

	
}

