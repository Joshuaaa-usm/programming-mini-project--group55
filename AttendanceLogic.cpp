
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
#include <iomanip>


// Function 5: markAttendance
/* Programmer:  | Matric: 
Purpose: Initiates the interactive session to input student IDs and update their presence in the system. */
void markAttendance() {
    string subject, date, searchID;
    
    clearScreen();
    resetStatus();
    cout << "Enter Subject Name: ";
    cin.ignore();
    getline(cin, subject);
    cout << "Enter Date (dd.mm.yyyy): ";
    cin >> date;

    cout << "\n--- Attendance Mode Active (Enter 0 to stop) ---\n";
    while (true) {
        cout << "Enter Student ID: ";
        cin >> searchID;
        
        if (searchID == "0") break; // Exit scanning loop

        int index = findStudentIndex(searchID);
        if (index != -1) {
            studentList[index].isPresent = 1; // Mark as present
            cout << ">> " << studentList[index].name << " marked PRESENT.\n";
        } else {
            cout << ">> ID NOT FOUND!\n";
        }
    }

    generateReport(subject, date); // Auto-save when finished
    clearScreen();
}

// Function 6: findStudentIndex
/* Programmer:  | Matric: 
Purpose: Searches the student list for a specific ID and returns its position in the vector for other functions to use. */
int findStudentIndex(string searchID) {
    for (int i = 0; i < (int)studentList.size(); i++) {
        if (studentList[i].id == searchID) return i;
    }
    return -1;
}

// Function 7: viewMasterList
/* Programmer:  | Matric: 
Purpose: Displays the current list of all enrolled students from the database in a table format. */
void viewMasterList() {
    clearScreen();
    cout << "==============================================\n";
    cout << "           CURRENT STUDENT DATABASE           \n";
    cout << "==============================================\n";
    cout << left << setw(15) << "ID" << setw(30) << "Name" << endl;
    cout << "----------------------------------------------\n";

    for (const auto& s : studentList) {
        cout << left << setw(15) << s.id << setw(30) << s.name << endl;
    }
    cout << "----------------------------------------------\n";
    clearScreen();
}

// Function 8: resetStatus
/* Programmer:  | Matric: 
Purpose: Resets the attendance status of every student in the list to 'Absent' (0). */
void resetStatus() {
    for (auto& s : studentList) s.isPresent = 0; // Wipe memory for new class
    cout << "All records reset.\n" ;
}