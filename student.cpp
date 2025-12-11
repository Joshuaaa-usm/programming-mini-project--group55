/*
   Programmers: 
   Purpose: Handles all student-related functions.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"
using namespace std;

vector<Student> students;

void loadStudentsFromFile() {
    students.clear();
    ifstream file("data/students.txt");

    Student s;
    while (file >> s.id >> s.name >> s.program >> s.year) {
        students.push_back(s);
    }
    file.close();
}

void saveStudentsToFile() {
    ofstream file("data/students.txt");

    for (auto &s : students) {
        file << s.id << " " << s.name << " " << s.program << " " << s.year << "\n";
    }
    file.close();
}

void addStudent() {
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cout << "Enter Name (one-word): ";
    cin >> s.name;
    cout << "Enter Program: ";
    cin >> s.program;
    cout << "Enter Year: ";
    cin >> s.year;

    students.push_back(s);
    saveStudentsToFile();

    cout << "Student added successfully!\n";
}

void viewStudents() {
    loadStudentsFromFile();

    cout << "\n--- Student List ---\n";
    for (auto &s : students) {
        cout << s.id << "  " << s.name << "  " << s.program << "  Year " << s.year << endl;
    }
}

void searchStudent() {
    loadStudentsFromFile();

    string id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << " (" << s.program << ")\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void updateStudent() {
    loadStudentsFromFile();

    string id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new program: ";
            cin >> s.program;
            cout << "Enter new year: ";
            cin >> s.year;

            saveStudentsToFile();
            cout << "Student updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
