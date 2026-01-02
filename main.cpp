
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

// Function 12: main
/* Programmer:  | Matric: 
Purpose: Serves as the entry point of the application, initializing the data and starting the menu loop. */
int main() {
    loadMasterList(); // Load fixed student data
    runSystem();      // Start the interactive menu
    return 0;
}