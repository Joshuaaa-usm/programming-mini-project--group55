
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
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <chrono>

vector<Student> studentList;

// Function 1: loadMasterList
/* Programmer:  | Matric: 
Purpose: Opens the 'students.txt' file, reads student IDs and Names, and populates the global studentList vector. */
void loadMasterList() {
    ifstream file("students.txt"); // Master file containing ID and Name
    if (!file.is_open()) {
        cout << "Error: 'students.txt' not found.\n";
        cout << "The program will now close.\n";
        this_thread::sleep_for(chrono::seconds(3));
        exit(1);
    }
    studentList.clear();
    Student s;
    // Format: ID Name
    while (file >> s.id >> ws && getline(file, s.name)) {
        s.isPresent = 0; // Everyone is absent until marked
        studentList.push_back(s);
    }
    file.close();
}

// Function 9: generateReport
/* Programmer:  | Matric: 
Purpose: Creates a text file named 'report.txt' summarizing the attendance results, including the percentage rate. */
void generateReport(string subject, string date) {
    ofstream file("report.txt");
    
    int presentCount = 0;
    int totalStudents = (int)studentList.size();
    
    file << "============================================================\n";
    file << "ATTENDANCE REPORT: " << subject << "\n";
    file << "DATE: " << date << "\n";
    file << "============================================================\n";
    file << "------------------------------------------------------------\n";
    file << left << setw(15) << "ID" << setw(30) << "Name" << "Status\n";
    file << "------------------------------------------------------------\n";


    for (const auto& s : studentList) {
        file << left << setw(15) << s.id << setw(30) << s.name;
        if (s.isPresent == 1) {
            file << "PRESENT   O\n";
            presentCount++;
        } else {
            file << "ABSENT       X\n";
        }
    }

    file << "------------------------------------------------------------\n";
    file << "Total Enrolled: " << totalStudents << "\n";
    file << "Total Present:  " << presentCount << "\n";

    double rate = 0;
    if (totalStudents > 0) {
        rate = (presentCount * 100) / (double)totalStudents;
    }
    file << "Attendance Rate: " << fixed << setprecision(2) << rate << " %\n";
    file << "------------------------------------------------------------\n";


    file.close();
    cout << "\nreport.txt generated!" << endl; // Success message
}




