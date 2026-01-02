
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
#include <fstream>
#include <iostream>

std::vector<Student> studentList; 

// Function 2: loadFromFile
/* Programmer:  | Matric: 
Purpose: Reads student records (ID, Name, and Attendance Count) from the external file and populates the program's memory. */
void loadFromFile() {
    std::ifstream file("data.txt");
    if (!file) return;
    
    studentList.clear();
    Student s;
    while (file >> s.id >> std::ws && std::getline(file, s.name, '|') && file >> s.attendanceCount) {
        studentList.push_back(s);
    }
    file.close();
}

// Function 3: saveToFile
/* Programmer: AHMAD NAJMI BIN MOHD NAIM | Matric: 24303630
Purpose: Writes all current student data from the system back to 'data.txt' to ensure progress is saved permanently. */
void saveToFile() {
    std::ofstream file("data.txt");
    for (const auto& s : studentList) {
        file << s.id << " " << s.name << " | " << s.attendanceCount << std::endl;
    }
    file.close();
}