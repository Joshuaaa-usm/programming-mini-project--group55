#include "StudentSystem.hpp"
#include <iostream>
#include <iomanip>

void resetStatus() {
    for (auto& s : studentList) s.isPresent = 0; // Wipe memory for new class
    cout << "All records reset.\n" ;
}

int findStudentIndex(string searchID) {
    for (int i = 0; i < (int)studentList.size(); i++) {
        if (studentList[i].id == searchID) return i;
    }
    return -1;
}

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