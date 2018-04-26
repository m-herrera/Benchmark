#include <functional>
#include <thread>
#include "Search Algorithms.h"

std::vector<int>* generateArray(int);
double TimeStamp(std::vector<int>*,int,std::function<int(std::vector<int>*,int)>);
void ResultComparison(int,int);
void BenchMark1();
void BenchMark2();

int main() {
    BenchMark1();
    BenchMark2();
}

double TimeStamp(std::vector<int>* array,int target,std::function<int(std::vector<int>*,int)> function){
    auto start = std::chrono::high_resolution_clock::now();
    function(array,target);
    auto finish = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
}

std::vector<int>* generateArray(int arraySize){
    std::vector<int>* array;
    srand(time(nullptr));
    for (int repetitions = 0; repetitions < 50; repetitions++) {
        int jump = rand() % 20 + 1;
        array = new std::vector<int>();
        for (int index = 0; index < arraySize; index++) {
            array->push_back(index * jump);
        }
    }
    return array;
}

void ResultComparison(int arraySize,int targetPosition){
    std::vector<int>* array = generateArray(arraySize);
    int Target = (*array)[targetPosition];
    std::cout<<std::endl<<"Array Size: "<<array->size()<< " - Target at Position: " <<targetPosition<<std::endl<<std::endl;
    std::cout<<"Linear Search: " << TimeStamp(array,Target,LinearSearch)<<std::endl;
    std::cout<<"Binary Search: " << TimeStamp(array,Target,BinarySearch)<<std::endl;
    std::cout<<"Interpolation Search: " <<TimeStamp(array,Target,InterpolationSearch)<<std::endl;
}


void BenchMark2(){
    //Small Array
    std::cout<<"--SMALL ARRAY--"<<std::endl;
    //Search Element at Beginning
    ResultComparison(100,5);
    //Search Middle Element
    ResultComparison(100,47);
    //Search Element at the End
    ResultComparison(100,93);

    //Medium Size Array
    std::cout<<std::endl<<"--MEDIUM SIZE ARRAY--"<<std::endl;
    //Search Element at Beginning
    ResultComparison(1000,25);
    //Search Middle Element
    ResultComparison(1000,473);
    //Search Element at the End
    ResultComparison(1000,934);

    //Big Array
    std::cout<<std::endl<<"--BIG ARRAY--"<<std::endl;
    //Search Element at Beginning
    ResultComparison(10000,25);
    //Search Middle Element
    ResultComparison(10000,4732);
    //Search Element at the End
    ResultComparison(10000,9347);

    std::cout<<std::endl<<"--CASO BASE--"<<std::endl;
    ResultComparison(1,0);
}

void GenerateValues(std::function<int(std::vector<int>*,int)> function){
    std::string sizes = "";
    std::string times = "";

    for (int repetitions = 0; repetitions <= 50; repetitions++){
        srand(repetitions);
        int arraySize = rand ()%10000 + 100;
        std::vector<int>* array = generateArray(arraySize);
        sizes.append(std::to_string(arraySize) + "\n");
        times.append(std::to_string(TimeStamp(array,arraySize/rand(),function)) + "\n");
    }
    std::cout <<sizes<<std::endl;
    std::cout <<times<<std::endl;
}

void BenchMark1(){

    std::cout<<"Linear Search: " << std::endl;
    GenerateValues(LinearSearch);
    std::cout<<"Binary Search: " << std::endl;
    GenerateValues(BinarySearch);
    std::cout<<"Interpolation Search: " <<std::endl;
    GenerateValues(InterpolationSearch);
}