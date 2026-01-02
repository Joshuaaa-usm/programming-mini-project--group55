#include <iostream>
#include <vector>
#include "Student.h"
#include "Menu.h"
#include "Attendance.h"
#include "FileManager.h"
#include "Utils.h"
#include "Auth.h"

using namespace std;

/*
Programmer: Group 55
Function: main
Purpose: Restrict features based on user role (Admin vs Viewer)
*/
int main() {
    vector<Student> students;
    loadData(students);

    int role = login(); // 1 for Admin, 2 for Viewer, 0 for Fail

    if (role == 0) return 0; // Exit if login fails

    // ... inside main() after login ...

    int choice;
    do {
        // Pass the role here
        choice = showMenu(role); 

        switch (choice) {
            case 1: 
                if (role == 1) addStudent(students); 
                else cout << "Invalid choice.\n"; // Safety check
                break;
            case 2: 
                if (role == 1) recordAttendance(students); 
                else cout << "Invalid choice.\n";
                break;
            case 3: viewStudentHistory(students); break;
            case 4: displayStudents(students); break;
            case 5: showLowAttendance(students); break;
            case 0: 
                if (role == 1) saveData(students);
                cout << "Exiting system...\n";
                break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}