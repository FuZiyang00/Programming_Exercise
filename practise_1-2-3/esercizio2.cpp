// Create a C++ program that dynamically allocates memory for an array of integers 
// Write a function to find and display the maximum and minimum values in the array. 
// Hint: the maximum and minimum value are stored in two variables passed as references to this

#include <cstdlib>
#include <iostream>

void find_max_min(const int* a, const int size, int &max_val, int &min_val){
    int min, max;
    min = a[0];
    max = a[0];

    for (int i =1; i<size; i++){
        if (a[i]>max){
            max=a[i];
        }
        if (a[i]<min){
        min = a[i];
    }
    }
    min_val = min;
    max_val = max;
    std::cout <<"Yor array has max: "<< max << " and min: "<<min; 

}

int main() {
    int size, min, max; 
    std::cout << "Provide array size: "; 
    std::cin >> size; 

    int* pointer = new int[size];
    
    for (int i = 0; i<size; i++){
        pointer[i]=rand(); 
    }
    find_max_min(pointer, size, max, min);
    delete[] pointer; 
    return 0;
}
