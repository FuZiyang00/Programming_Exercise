#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    double gradeAverage;
};

// Function to display student information
void displayStudents(const std::vector<Student>& students);

#endif // STUDENT_H