
/* Project: Attendance Management System
   Purpose: 
   Programmer: 
   1. MUHAMMAD BIN MD ZANI
   2. JOSHUA LIM HOCK LIANG
   3. QAMIL IMRAN BIN MOHAMMAD SAID
   4. MUHAMMAD HAIKAL BIN AHMAD 
   5. AHMAD DZUL ALIF BIN ROSLI
*/


#include "StudentSystem.hpp"
#include <iostream>

// Function 4: displayHeader
/* Programmer:  | Matric: 
Purpose: Displays the visual banner and title of the Student Attendance System at the top of the interface. */
void displayHeader() {
    cout << "\n========================================" << endl;
    cout << "     STUDENT ATTENDANCE SYSTEM          " << endl;
    cout << "========================================" << endl;
}

// Function 5: runSystem
/* Programmer:  | Matric: 
Purpose: Orchestrates the main program loop, displays the menu, and routes user choices to the appropriate functions. */
void runSystem() {
    int choice;
    do {
        displayHeader();
        cout << "1. Mark Attendance\n2. View Report\n3. Add Student\n4. Statistics\n5. Reset Attendance\n6. Save & Exit\n";
        
        choice = getValidatedChoice();

        switch (choice) {
            case 1: markAttendance(); break;
            case 2: viewReport(); break;
            case 3: addStudent(); break;
            case 4: showStatistics(); break;
            case 5: resetAllAttendance(); break;
            case 6: saveToFile(); break;
        }
    } while (choice != 6);
}


// Function 12: clearScreen
/* Programmer:  | Matric: 
Purpose: Provides visual spacing or clears the console output to maintain a tidy and professional user interface. */
void clearScreen() {
    for(int i = 0; i < 5; i++) cout << endl;
}

// Function 13: getValidatedChoice
/* Programmer:  | Matric: 
Purpose: Validates user input to ensure it is an integer and within the valid range. */
int getValidatedChoice() {
    int choice;
    while (true) {
        cout << "Choice: ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= 6) {
                return choice; 
            } else {
                cout << "Invalid range! Please input a number between 1 and 6 only." << endl;
            }
        } else {
            cout << "Invalid type! Please input numbers only." << endl;
            cin.clear(); // Reset the error flag
            cin.ignore(100, '\n'); // Clear the "trash" in the buffer
        }
    }
}


// Function 14: inputWithCancel
/* Programmer:  | Matric: 
Purpose: Standardizes data entry across the system, allowing the user to type '0' to abort any process and return to the main menu. */
bool inputWithCancel(string &input, string prompt) {
    cout << prompt << " (0 to cancel): ";
    cin >> input;
    
    if (input == "0") {
        cout << "Action cancelled. Returning to menu...\n";
        return true; 
    }
    return false; 
}
