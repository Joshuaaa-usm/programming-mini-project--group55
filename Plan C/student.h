#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

struct Student {
    string id;
    string name;
    string program;
    string year;
};

void loadStudentsFromFile();
void saveStudentsToFile();

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();

extern vector<Student> students;

#endif
