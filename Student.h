#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

/*
Programmer: Group 55
Purpose: Define record structure and Student class with history
*/
struct AttendanceRecord {
    string date;
    char status; 
};

class Student {
public:
    string id;
    string name;
    vector<AttendanceRecord> records;

    Student(string i = "", string n = "");
    double calculatePercentage() const;
};

#endif