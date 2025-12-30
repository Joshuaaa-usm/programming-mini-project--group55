#include <iostream>
#include <iomanip>
#include "Utils.h"
using namespace std;

/*
Programmer: Group 55
Function: addStudent
Purpose: Create a new student profile in the system
*/
void addStudent(vector<Student>& students) {
    string id, name;
    cout << "Enter Student ID (e.g., A201): "; cin >> id;
    cout << "Enter Student Name: "; 
    cin.ignore(); // Clear buffer
    getline(cin, name);

    students.push_back(Student(id, name));
    cout << "Student " << name << " added to system.\n";
}

/*
Programmer: Group 55
Function: displayStudents
Purpose: Show list of all students and their current %
*/
void displayStudents(const vector<Student>& students) {
    cout << "\n--- USM STUDENT LIST ---\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << "Attendance %" << endl;
    cout << "---------------------------------------------\n";
    for (const auto& s : students) {
        cout << left << setw(10) << s.id 
             << setw(20) << s.name 
             << fixed << setprecision(2) << s.calculatePercentage() << "%" << endl;
    }
}

/*
Programmer: Group 55
Function: showLowAttendance
Purpose: Filter students below 80% for exam barring
*/
void showLowAttendance(const vector<Student>& students) {
    cout << "\n!!! LOW ATTENDANCE ALERT (< 80%) !!!\n";
    bool found = false;
    for (const auto& s : students) {
        double percent = s.calculatePercentage();
        if (percent < 80.0 && !s.records.empty()) {
            cout << "Warning: " << s.name << " (" << s.id << ") - " << percent << "%\n";
            found = true;
        }
    }
    if (!found) cout << "All students meet attendance requirements.\n";
}