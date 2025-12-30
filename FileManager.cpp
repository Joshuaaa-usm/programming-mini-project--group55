#include <fstream>
#include <sstream>
#include "FileManager.h"

/*
Programmer: Group 55
Function: saveData
Purpose: Save complex nested data using commas and pipes
*/
void saveData(const vector<Student>& students) {
    ofstream file("data.txt");
    for (const auto& s : students) {
        file << s.id << "," << s.name;
        for (const auto& r : s.records) {
            file << "," << r.date << "|" << r.status;
        }
        file << endl;
    }
    file.close();
}

/*
Programmer: Group 55
Function: loadData
Purpose: Parse lines to reconstruct students and their history
*/
void loadData(vector<Student>& students) {
    ifstream file("data.txt");
    string line;
    if (!file) return;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, part;
        getline(ss, id, ',');
        getline(ss, name, ',');

        Student s(id, name);
        while (getline(ss, part, ',')) {
            size_t pos = part.find('|');
            if (pos != string::npos) {
                s.records.push_back({part.substr(0, pos), part[pos+1]});
            }
        }
        students.push_back(s);
    }
    file.close();
}