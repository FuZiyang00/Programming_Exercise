#include <iostream>
#include "DataProcessor.hpp"

int main() {
    const double input1[] = {2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75};
    const double input2[] = {0.73, -0.45, 0.12, 0.88, -0.67, 0.34, -0.92};

    // Create an instance of DataProcessor
    const DataProcessor dp1(input1, 7);
    const DataProcessor dp2(input2, 7);

    // Test the new functionalities
    std::cout << "dp1: " << dp1 << std::endl;
    std::cout << "dp2: " << dp2 << std::endl;

    std::cout << "Number of elements: "<< dp1.n_elements() <<std::endl;
    std::cout << "Minimum value: " << dp1.min() << std::endl;
    std::cout << "Maximum value: " << dp1.max() << std::endl;
    std::cout << "Mean: " << dp1.mean() << std::endl;
    std::cout << "Standard Deviation: " << dp1.standardDeviation() << std::endl;

    DataProcessor dp5 = dp1 + dp2;
    dp5[0] = 1.1;
    const double index = dp5[0];
    std::cout << "dp5: " << dp5 << std::endl;
    std::cout << "dp5 index 0 " << index << std::endl;
    
    return 0;
}