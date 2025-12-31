
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
using namespace std;

struct Student {
    string id;
    string name;
    int attendanceCount;
};

// Global vector declaration (extern allows it to be used across files)
extern vector<Student> studentList;

//int main();                                                       // function 1
void loadFromFile();                                                // function 2
void saveToFile();                                                  // function 3
void displayHeader();                                               // function 4
void runSystem();                                                   // function 5
int findStudentIndex(string id);                                    // function 6
void markAttendance();                                              // function 7
void viewReport();                                                  // function 8
void addStudent();                                                  // function 9
void showStatistics();                                              // function 10
void resetAllAttendance();                                          // function 11
void clearScreen();                                                 // function 12
int getValidatedChoice();                                           // function 13
bool inputWithCancel(std::string &input, std::string prompt);       // function 14

#endif