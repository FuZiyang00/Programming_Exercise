#include "students.hpp"
#include <iostream>
#include <vector>

int main () {
    std::vector<Student> students = {
        {"Alice", 18, 95.5},
        {"Bob", 19, 89.0},
        {"Charlie", 20, 75.5},
        {"David", 18, 91.2},
        {"Eve", 19, 88.8}
    };

    displayStudents(students);
    return 0;
}