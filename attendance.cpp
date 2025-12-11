/*
   Programmers: Group members
   Purpose: Handles attendance functions.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "attendance.h"
#include "student.h"
using namespace std;

void markAttendance() {
    loadStudentsFromFile();

    string date;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    ofstream file("data/attendance.txt", ios::app);

    for (auto &s : students) {
        string status;
        cout << "Mark attendance for " << s.name << " (P/A): ";
        cin >> status;

        if (status == "P" || status == "p") status = "Present";
        else status = "Absent";

        file << date << " " << s.id << " " << s.name << " " << status << "\n";
    }
    file.close();
    cout << "Attendance recorded!\n";
}

void viewAttendanceByDate() {
    string date;
    cout << "Enter date to view (YYYY-MM-DD): ";
    cin >> date;

    ifstream file("data/attendance.txt");
    string d, id, name, status;

    cout << "\nAttendance on " << date << ":\n";

    while (file >> d >> id >> name >> status) {
        if (d == date) {
            cout << id << " - " << name << " - " << status << endl;
        }
    }
}

void viewStudentAttendanceSummary() {
    string targetID;
    cout << "Enter Student ID: ";
    cin >> targetID;

    ifstream file("data/attendance.txt");
    string d, id, name, status;

    cout << "\nAttendance summary for " << targetID << ":\n";

    while (file >> d >> id >> name >> status) {
        if (id == targetID)
            cout << d << " - " << name << " - " << status << endl;
    }
}