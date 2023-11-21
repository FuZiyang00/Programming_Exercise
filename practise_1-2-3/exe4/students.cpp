#include "students.hpp"
#include <iostream>

void displayStudents(const std::vector<Student>& students) {
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Age: " << student.age << std::endl;
        std::cout << "Grade Average: " << student.gradeAverage << std::endl;
        std::cout << std::endl;
    }
}