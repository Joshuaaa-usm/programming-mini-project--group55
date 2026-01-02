
/* Project: Attendance Management System
   Purpose: 
   Programmer: 
   1. MUHAMMAD BIN MD ZANI
   2. JOSHUA LIM HOCK LIANG
   3. QAMIL IMRAN BIN MOHAMMAD SAID
   4. MUHAMMAD HAIKAL BIN AHMAD 
   5. AHMAD DZUL ALIF BIN ROSLI
*/


#ifndef STUDENTSYSTEM_HPP
#define STUDENTSYSTEM_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Student {
    string id;
    string name;
    int isPresent; // 0 = Absent, 1 = Present
};

// Global vector to hold the Master List
extern vector<Student> studentList;

// Core Functions
void loadMasterList();                                  // Function 1: Loads students.txt 
void runSystem();                                       // Function 2: Main Menu Loop 
void displayHeader();                                   // Function 3: Welcoming Message 
int getValidatedChoice();                               // Function 4: Input validation 
void markAttendance();                                  // Function 5: Session Controller
int findStudentIndex(string id);                        // Function 6: Search helper
void viewMasterList();                                  // Function 7: View enrolled students
void resetStatus();                                     // Function 8: Sets everyone to 0 (Absent)
void generateReport(string subject, string date);       // Function 9: Saves session report 
void clearScreen();                                     // Function 10: Visual spacing 
void displayExitGreeting();                             // Function 11: Final message and delay 

// Standard C++ Functions
int main();                                             // Function 12: Program entry point 

#endif