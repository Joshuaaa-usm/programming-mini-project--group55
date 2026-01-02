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
void loadMasterList();                                  // Function 2: Loads students.txt
void generateReport(string subject, string date);       // Function 3: Saves session report
void displayHeader();                                   // Function 4: Welcoming Message
void displayExitGreeting();
void runSystem();                                       // Function 5: Main Menu Loop
int findStudentIndex(string id);                        // Function 6: Search helper
void markAttendance();                                  // Function 7: Session Controller
void viewMasterList();                                  // Function 8: View enrolled students
void resetStatus();                                     // New: Sets everyone to 0
void clearScreen();                                     // Function 12: Visual spacing
int getValidatedChoice();                               // Function 13: Input validation


#endif