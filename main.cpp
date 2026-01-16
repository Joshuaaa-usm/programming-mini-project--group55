
/* Project: Attendance Management System
   Purpose: To record, manage, and store student attendance data efficiently.
   Programmer: 
   1. MUHAMMAD BIN MD ZANI              24304145
   2. JOSHUA LIM HOCK LIANG             24304192
   3. QAMIL IMRAN BIN MOHAMMAD SAID     24300997
   4. MUHAMMAD HAIKAL BIN AHMAD         162031
   5. AHMAD DZUL ALIF BIN ROSLI         24303428
*/


#include "StudentSystem.hpp"

// Function 12: main
/* Programmer:  | Matric: 
Purpose: Serves as the entry point of the application, initializing the data and starting the menu loop. */
int main() {
    loadMasterList(); // Load fixed student data
    runSystem();      // Start the interactive menu
    return 0;
}