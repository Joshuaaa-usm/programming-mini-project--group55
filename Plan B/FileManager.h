#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Student.h"
using namespace std;

/*
Programmer: Group 55
Purpose: File handling functions
*/
void loadData(vector<Student>& students);
void saveData(const vector<Student>& students);

#endif
