#include <iostream>
#include <string>
#include <vector>
#include <numeric>

template<unsigned int N>
class Factorial {
    public:
        static constexpr int value = N * Factorial<N-1>::value;
        // value computed at compile time using recursion: 
        // multiplies N by the value of Factorial <N-1>
};

template<> // empty brackets for specialization 
class Factorial<0>{ // specialization with N=0
    public:
        static constexpr int value = 1;
        // constexpr is used to declare a variable or function 
        // as a compile-time constant 
        // requires the value to be computable at compile time
};

int main() {
    // Instantiate the template for the integers 5, 7, and 10
    constexpr int factorial_5 = Factorial<5>::value;
    constexpr int factorial_7 = Factorial<7>::value;
    constexpr int factorial_10 = Factorial<10>::value;

    // Use static_assert to ensure that values are computed at compile time
    static_assert(factorial_5 == 120, "Factorial of 5 is incorrect");
    static_assert(factorial_7 == 5040, "Factorial of 7 is incorrect");
    static_assert(factorial_10 == 3628800, "Factorial of 10 is incorrect");

    // Print the results of the factorials
    std::cout << "Factorial of 5: " << factorial_5 << std::endl;
    std::cout << "Factorial of 7: " << factorial_7 << std::endl;
    std::cout << "Factorial of 10: " << factorial_10 << std::endl;

    return 0;
}