
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

using namespace std;



// Function 6: findStudentIndex
/* Programmer:  | Matric: 
Purpose: Searches the student list for a specific ID and returns its position in the vector for other functions to use. */
int findStudentIndex(string searchID) {
    for (size_t i = 0; i < studentList.size(); i++) {
        if (studentList[i].id == searchID) return (int)i; // The (int) cast fixes the warning
    }
    return -1;
}

// Function 7: markAttendance
/* Programmer:  | Matric: 
Purpose: Prompts the user for a Student ID and increments the attendance count if a matching record is found. */
void markAttendance() {
    string searchID;
    
    // Call the helper function. If it returns false, we exit immediately.
    if (inputWithCancel(searchID, "Enter Student ID")) return;

    int index = findStudentIndex(searchID);
    if (index != -1) {
        studentList[index].attendanceCount++;
        cout << "Success! " << studentList[index].name << " marked.\n";
    } else {
        cout << "ID Not Found!\n";
    }
}

// Function 8: viewReport
/* Programmer:  | Matric: 
Purpose: Generates and displays a formatted table showing the ID, Name, and Attendance Count of every student. */
void viewReport() {
    cout << "\n-------------------------------------------------------------------\n";
    cout << left << setw(15) << "ID" << setw(45) << "Name" << "Count\n";
    cout << "-------------------------------------------------------------------\n";
    for (const auto& s : studentList) {
        cout << left << setw(15) << s.id << setw(45) << s.name << s.attendanceCount << endl;
    }
}

// Function 9: addStudent
/* Programmer:  | Matric: 
Purpose: Collects details for a new student from the user and appends them to the system's database. */
void addStudent() {
    string tempID;
    if (inputWithCancel(tempID, "Enter New ID")) return;

    Student s;
    s.id = tempID;

    cin.ignore(100, '\n');

    cout << "Enter Name: "; 
    getline(cin, s.name);
    s.attendanceCount = 0;
    
    studentList.push_back(s);
    cout << "Student added successfully!\n";
}

// Function 10: showStatistics
/* Programmer:  | Matric: 
Purpose: Calculates and displays the total number of students registered and the grand total of all attendance marks. */
void showStatistics() {
    int total = 0;
    for (const auto& s : studentList) total += s.attendanceCount;
    cout << "\nTotal Students: " << studentList.size() << "\nTotal Attendance: " << total << endl;
}

// Function 11: resetAllAttendance
/* Programmer:  | Matric: 
Purpose: Resets the attendance count for every student in the list back to zero for a fresh start. */
void resetAllAttendance() {
    for (auto& s : studentList) s.attendanceCount = 0;
    cout << "All records reset.\n";
}

