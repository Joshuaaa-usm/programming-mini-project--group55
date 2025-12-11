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

        if (status == "P" || status == "p") status = "Present";
        else status = "Absent";

        // Save ID + Name + Status
        file << date << "|" << s.id << "|" << s.name << "|" << status << "|" <<  "\n";
    }
    file.close();
    cout << "Attendance recorded!\n";
}

void viewAttendanceByDate() {
    string date;
    cout << "Enter date to view (YYYY-MM-DD): ";
    cin >> date;

    ifstream file("data/attendance.txt");

    string d, id, name, status, line;

    cout << "\nAttendance on " << date << ":\n";

    /* // READ 4 FIELDS: date id name status
    while (file >> d >> id >> name >> status) {
        if (d == date) {
            cout << id << " - " << name << " - " << status << endl;
        }
    } */

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, d, '|');
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, status, '|');

        if (d == date) {
            cout << id << "|" << name << "|" << status << "|" << endl;
        }
    }
    file.close();
}

void viewStudentAttendanceSummary() {
    string targetID;
    cout << "Enter Student ID: ";
    cin >> targetID;

    ifstream file("data/attendance.txt");

    string d, id, name, status, line;

    cout << "\nAttendance summary for " << targetID << ":\n";

    /* // READ 4 FIELDS
    while (file >> d >> id >> name >> status) {
        if (id == targetID)
            cout << d << " - " << name << " - " << status << endl;
    } */

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, d, '|');
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, status, '|');

        if (id == targetID) {
            cout << d << "|" << name << "|" << status << "|" << endl;
        }
    }

    file.close();
}