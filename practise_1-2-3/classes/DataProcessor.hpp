#ifndef DATA_PROCESSOR_HPP
#define DATA_PROCESSOR_HPP
#include <vector>
#include<iostream>
#include <cassert>

class DataProcessor{
    private:
    double *data;
    unsigned int size;
    static unsigned int n_instances; // Bad practise to use a global variable 
                                     // static because if not it would start at 0 every time we call the class 
                                     // it will be 0

    public:
        DataProcessor(const double *input_data, const unsigned int &input_size);
        DataProcessor(const DataProcessor& other); //Copy constructor
        ~DataProcessor(){delete [] data;--n_instances;}
        static int get_n_instances();
        unsigned int n_elements() const {return size ;}
        void allert();
        double min() const;
        double max() const;
        double mean() const;
        double standardDeviation() const;
        DataProcessor operator+(const DataProcessor &other) const;

        stati unsigned int get_n_instances(){ return n_instances;}
        
        double &operator[](const unsigned int &index) {
            if(index >= 0 && index < size){
                return data[index];
            }
        }

        const double &operator[](const unsigned int &index) const{
            if(index >= 0 && index < size){
                return data[index];
            }
        
        }

        friend std::ostream& operator<<(std::ostream& os, const DataProcessor& dp);
        
};

#endif 