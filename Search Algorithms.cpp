//
// Created by marco on 24/04/18.
//
#include "Search Algorithms.h"

int LinearSearch(std::vector<int>* array,int target){
    int size = array->size();
    for(int currentIndex = 0; currentIndex < size; currentIndex++){
        if ((*array)[currentIndex] == target){
            return currentIndex;
        }
    }
    return -1;
}

int  BinarySearch(std::vector<int>* array,int target){
    int low = 0;
    int high = array->size()-1;
    int middle;

    while(low <= high){
        middle = (low + high)/2;
        if (target > (*array)[middle]){
            low = middle+1;
            continue;
        }else if(target < (*array)[middle]){
            high = middle-1;
            continue;
        }else{
            return middle;
        }
    }
    return -1;
}

int  InterpolationSearch(std::vector<int>* array,int target){
    int low = 0;
    int high = array->size()-1;
    int middle;
    int lowElement = (*array)[low];
    int highElement = (*array)[high];
    while((low <= high && target >= lowElement && target <= highElement)){
        if (highElement == lowElement){
            middle = 0;
        }else{
            middle =  low + ((target-lowElement)*(high-low)/(highElement-lowElement));
        }
        if (target > (*array)[middle]){
            low = middle+1;
            lowElement = (*array)[low];
            continue;
        }else if(target < (*array)[middle]){
            high = middle-1;
            highElement = (*array)[high];
            continue;
        }else{
            return middle;
        }
    }
    return -1;

}