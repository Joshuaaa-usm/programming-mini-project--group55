#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <vector>
#include "Student.h"

/*
Programmer: Group 55
Purpose: Record management functions
*/
void recordAttendance(vector<Student>& students);
void viewStudentHistory(const vector<Student>& students);
void showLowAttendance(const vector<Student>& students);

#endif