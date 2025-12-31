/*
   Programmers: AHMAD DZUL ALIF BIN ROSLI
   Purpose: Handles all menu displays and user navigation.
*/

#include <iostream>
#include "menu.h"
#include "student.h"
#include "attendance.h"
using namespace std;

void mainMenu() {
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "   ATTENDANCE MANAGEMENT SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Student Management\n";
        cout << "2. Attendance Management\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: studentMenu(); break;
            case 2: attendanceMenu(); break;
            case 3: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 3);
}

void studentMenu() {
    int choice;

    do {
        cout << "\n------ Student Management ------\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: case 0: return;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}

void attendanceMenu() {
    int choice;

    do {
        cout << "\n------ Attendance Management ------\n";
        cout << "1. Mark Attendance\n";
        cout << "2. View Attendance By Date\n";
        cout << "3. View Student Attendance Summary\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: markAttendance(); break;
            case 2: viewAttendanceByDate(); break;
            case 3: viewStudentAttendanceSummary(); break;
            case 4: case 0: return;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 4);
}
