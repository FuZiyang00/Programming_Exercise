#include "statistics.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace mystat {
// Function to calculate the mean of a set of numbers.
double calculate_mean(const std::vector<double> &numbers) { 
    double sum = 0.0 ; 
    double counter = 0.0 ; 
    for (const double &element : numbers) {
        sum+=element;
        counter+=1;
    }
    return sum/counter;
}

double calculate_median(const std::vector<double> &numbers) {
    std::vector<double> sorted_numbers = numbers;  // Make a copy to avoid modifying the original vector
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int size = sorted_numbers.size();

    if (size % 2 == 0) {
        // If the size is even, return the average of the middle two elements
        int middle1 = size / 2 - 1;
        int middle2 = size / 2;
        return (sorted_numbers[middle1] + sorted_numbers[middle2]) / 2.0;
    } else {
        // If the size is odd, return the middle element
        int middle = size / 2;
        return sorted_numbers[middle];
    }
}

double calculate_standard_deviation(const std::vector<double> &numbers) {
    int size = numbers.size();

    if (size < 2) {
        // Standard deviation is undefined for a vector with less than 2 elements.
        // You can choose to handle this case differently if needed.
        std::cout <<"Input vector must have at least 2 elements";
    }

    // Step 1: Calculate the mean (average) of the numbers
    double mean = calculate_mean(numbers);

    // Step 2: Calculate the sum of squared differences from the mean
    double sum_squared_diff = 0.0;
    for (const double &num : numbers) {
        double diff = num - mean;
        sum_squared_diff += diff * diff;
    }

    // Step 3: Calculate the variance (average of squared differences)
    double variance = sum_squared_diff / (size - 1);

    // Step 4: Calculate the standard deviation (square root of variance)
    double std_deviation = std::sqrt(variance);

    return std_deviation;
}
}
