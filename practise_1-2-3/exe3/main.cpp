#include "statistics.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

// Function to perform statistics calculation
void perform_statistics() {
    std::cout << "Enter a set of numbers separated by spaces: ";
    std::string input;
    std::getline(std::cin, input);

    // Split the input string into a vector of numbers.
    std::vector<double> numbers;
    std::istringstream iss(input);
    double num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "Invalid input. Please enter numbers." << std::endl;
        return;
    }

    // Calculate and display statistics.
    const double mean = mystat::calculate_mean(numbers);
    const double median = mystat::calculate_median(numbers);
    const double stddev = mystat::calculate_standard_deviation(numbers);

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Standard Deviation: " << stddev << std::endl;
}

int main() {
    std::cout << "Statistics calculator" << std::endl;

    char choice;
    do {
        perform_statistics();

        // Ask the user if they want to continue.
        std::cout << "Do you want to calculate statistics for another set of numbers? (Y/N): ";
        std::cin >> choice;

        // Clear the input buffer.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice == 'Y');

    return 0;
}