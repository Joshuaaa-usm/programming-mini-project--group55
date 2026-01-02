#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "Student.h"

/*
Programmer: Group 55
Purpose: Utility functions for student management
*/
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void showLowAttendance(const vector<Student>& students);

#endif