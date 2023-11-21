#include <iostream>
#include <cstring>

class DataProcessor {
private:
    double *data;
    unsigned int size;

public:
    // Constructor 
    DataProcessor(const double *input_data, const unsigned int &input_size) 
        : data(new double[input_size]), size(input_size) // copy from input_data to data
    {
        for (unsigned int i = 0; i < input_size; ++i)
        {
            data[i] = input_data[i];
        }
    }

    // Copy contruct 
    DataProcessor(const DataProcessor &other)
    {
        // this->data = other.data; // this makes the copy and the original sharing the same memory address
        this->data = new double[other.size]; // allocating a new block of memory for the copy
        for (unsigned int i = 0; i < other.size; ++i)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;
    }

    ~DataProcessor(){ delete[] data; }

    double compute_mean(){
        double mean = 0.0;
        for (unsigned int i=0; i< size; i++){
            mean += data[i];
        }
        return mean;
    }   

};