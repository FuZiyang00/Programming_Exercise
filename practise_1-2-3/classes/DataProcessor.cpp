#include "DataProcessor.hpp"
#include <cstring>
#include<cmath>
#include<iostream>
#include <cassert>

static unsigned int DataProcessor::n_instances = 0;
DataProcessor::DataProcessor(const double *input_data, const unsigned int &input_size)
    : data(new double [input_size]), size(input_size)
    {
        for (unsigned int i=0; i < size; ++i){
            data[i] = input_data[i];
        }
    ++n_instances;
    }

DataProcessor::DataProcessor(const DataProcessor& other){
    this->data = new double[other.size];
    this->size = other.size;
    {
        for (unsigned int i=0; i<other.size; ++i){
            this->data[i] = other.data[i];
        }
    ++n_instances;
    }

} //Copy constructor

void DataProcessor::allert(){
    if (size == 0) {
        throw std::runtime_error("Data array is empty.");
    }
}

double DataProcessor::min() const{
    double minimum = data[0];
    for (unsigned int i=1; i<size; ++i){
        if (data[i]<minimum){
            minimum=data[i];
        }
    }
    return minimum;
}

double DataProcessor::max() const{
    void allert();
    double maximum = data[0];
    for (unsigned int i=1; i<size; ++i){
        if (data[i]>maximum){
            maximum=data[i];
        }
    }
    return maximum;

}

double DataProcessor::mean() const{
    void allert();
    double media = 0.0;
    for (unsigned int i=0; i< size; i++){
        media += data[i];
    }
    return media/size;

}

double DataProcessor::standardDeviation() const{
    void allert();
    double m = mean();
    double sum = 0;
    for (unsigned  i = 0; i < size; i++) {
        sum += (data[i] - m) * (data[i] - m);
    }
    return sqrt(sum / size);
}

DataProcessor DataProcessor::operator+(const DataProcessor &other) const{
    assert(size == other.size);
    DataProcessor result(data, size); // Copy the current object.
    for (unsigned int i = 0; i < size; ++i) {
        result[i] += other[i];
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const DataProcessor &dp) {
  for (unsigned int i = 0; i < dp.size; ++i) {
    os << dp[i];
    if (i < dp.size - 1) {
      os << ", ";
    }
  }
  return os;
}




