#include <functional>
#include "Search Algorithms.h"

std::vector<int>* generateArray(int);
double TimeStamp(std::vector<int>*,int,std::function<int(std::vector<int>*,int)>);
void ResultComparison(int,int);

int main() {

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
    ResultComparison(1000,5);
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

}

double TimeStamp(std::vector<int>* array,int target,std::function<int(std::vector<int>*,int)> function){

    clock_t begin = clock();
    function(array,target);
    clock_t end = clock();

    return double(end - begin) / CLOCKS_PER_SEC;
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