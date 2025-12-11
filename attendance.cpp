/*
   Programmers: Group members
   Purpose: Handles attendance functions.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
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

        if (status == "P" || status == "p" ) status = "Present";
        else status = "Absent";

        file << date << "|" << s.id << "|" << s.name << "|" << status << "\n";
    }
    file.close();
    cout << "Attendance recorded!\n";
}

void viewAttendanceByDate() {
    string d, date, line, id, name, status;
    cout << "Enter date to view (YYYY-MM-DD): ";
    cin >> date;

    ifstream file("data/attendance.txt");

    cout << "\nAttendance on " << date << ":\n";

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, d, '|');
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, status, '|');

        if (d == date){
            cout << id << "|" << name << "|" << status << endl;
        }
        
    }

    /* while (file >> d >> id >> name >> status) {
        if (d == date) {
            cout << id << "|" << name << "|" << status << endl;
        }
    } */
}

void viewStudentAttendanceSummary() {
    string targetID;
    cout << "Enter Student ID: ";
    cin >> targetID;

    ifstream file("data/attendance.txt");
    string date, id, name, status, line;

    cout << "\nAttendance summary for " << targetID << ":\n";

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, date, '|');
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, status, '|');

        if (id == targetID){
            cout << date << "|" << name << "|" << status << endl;
        }
        
    }

    /* while (file >> d >> id >> name >> status) {
        if (id == targetID)
            cout << d << " - " << name << " - " << status << endl;
    } */
}