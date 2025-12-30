#include "Student.h"

/*
Programmer: Group 55
Function: Student constructor
Purpose: Initialize student object with empty records
*/
Student::Student(string i, string n) : id(i), name(n) {}

/*
Programmer: Group 55
Function: calculatePercentage
Purpose: Logic to find attendance % for exam eligibility
*/
double Student::calculatePercentage() const {
    if (records.empty()) return 0.0;
    int present = 0;
    for (const auto& r : records) {
        if (r.status == 'P') present++;
    }
    return (static_cast<double>(present) / records.size()) * 100.0;
}