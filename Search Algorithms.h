//
// Created by marco on 24/04/18.
//

#ifndef BENCHMARK_SEARCH_ALGORITHMS_H
#define BENCHMARK_SEARCH_ALGORITHMS_H

#include <iostream>
#include <vector>
#include <ctime>

int  LinearSearch(std::vector<int>* array,int target);
int  BinarySearch(std::vector<int>* array,int target);
int  InterpolationSearch(std::vector<int>* array,int target);



#endif //BENCHMARK_SEARCH_ALGORITHMS_H
