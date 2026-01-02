#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
using namespace std;

struct AttendanceRecord {
    string date;
    string studentID;
    string status; // Present / Absent
};

void markAttendance();
void viewAttendanceByDate();
void viewStudentAttendanceSummary();

#endif
