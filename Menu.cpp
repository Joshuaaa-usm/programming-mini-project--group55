#include <iostream>
#include "Menu.h"
using namespace std;

/*
Programmer: Group 55
Function: showMenu
Purpose: Dynamically display options based on Admin (1) or Viewer (2)
*/
/*
Programmer: Group 55
Function: showMenu
Purpose: Display menu with input validation to prevent crashes
*/
int showMenu(int role) {
    int choice;
    while (true) {
        cout << "\n--- USM ATTENDANCE SYSTEM V2.0 ---\n";
        if (role == 1) {
            cout << "1. Add New Student\n2. Record Attendance\n";
        }
        cout << "3. View History\n4. All Students\n5. Low Attendance Alert\n0. Save & Exit\n";
        cout << "Enter choice: ";

        if (cin >> choice) {
            return choice; // Input is a valid integer
        } else {
            // --- VALIDATION LOGIC ---
            cout << "[!] Invalid input. Please enter a number.\n";
            cin.clear(); // Clear the fail state
            cin.ignore(1000, '\n'); // Ignore the "bad" characters in the buffer
        }
    }
}