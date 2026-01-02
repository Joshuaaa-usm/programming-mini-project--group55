#include <iostream>
#include <iomanip>
#include "Attendance.h"
using namespace std;

/*
Programmer: Group 55
Function: recordAttendance
Purpose: Adds a specific date record (P/A) to a student's history
*/
/*
Programmer: Group 55
Function: recordAttendance
Purpose: Added validation for P/A status
*/
void recordAttendance(vector<Student>& students) {
    string id, date;
    char status;
    cout << "Enter Student ID: "; cin >> id;

    for (auto& s : students) {
        if (s.id == id) {
            cout << "Enter Date (DD/MM): "; cin >> date;
            
            // Loop until valid P or A is entered
            while (true) {
                cout << "Enter Status (P/A): "; cin >> status;
                status = toupper(status);
                if (status == 'P' || status == 'A') {
                    s.records.push_back({date, status});
                    cout << "Success!\n";
                    return;
                }
                cout << "Invalid status! Use 'P' for Present or 'A' for Absent.\n";
            }
        }
    }
    cout << "ID not found.\n";
}

/*
Programmer: Group 55
Function: viewStudentHistory
Purpose: Shows every date recorded for a single student
*/
void viewStudentHistory(const vector<Student>& students) {
    string id;
    cout << "Enter Student ID: "; cin >> id;
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "\nHistory for: " << s.name << " (" << s.id << ")\n";
            cout << "---------------------------\n";
            for (const auto& r : s.records) {
                cout << "Date: " << r.date << " | Status: " << r.status << endl;
            }
            cout << "Total Attendance: " << fixed << setprecision(2) << s.calculatePercentage() << "%\n";
            return;
        }
    }
    cout << "Student not found.\n";
}