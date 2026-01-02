
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
#include <thread>
#include <chrono>

// Function 2: runSystem
/* Programmer:  | Matric: 
Purpose: Manages the main program flow, calling different features based on user menu selection. */
void runSystem() {
    int choice;
    do {
        displayHeader();
        cout << "1. Mark Attendance\n";
        cout << "2. View Student Database\n";
        cout << "3. Reset Status\n";
        cout << "4. Exit Program\n";
        
        choice = getValidatedChoice();

        switch (choice) {
            case 1: markAttendance(); break;
            case 2: viewMasterList(); break;
            case 3: resetStatus(); break;
        }
        if (choice == 3) clearScreen();
    } while (choice != 4);
    displayExitGreeting();
}

// Function 3: displayHeader
/* Programmer:  | Matric: 
Purpose: Prints the stylized ASCII banner for the Attendance Management System. */
void displayHeader() {
    cout << "====================================================" << endl;
    cout << "|                                                  |" << endl;
    cout << "|    A T T E N D A N C E   M A N A G E M E N T     |" << endl;
    cout << "|                  S Y S T E M                     |" << endl;
    cout << "|                                                  |" << endl;
    cout << "====================================================" << endl;
    cout << "|              Group 55 Mini Project               |" << endl;
    cout << "----------------------------------------------------" << endl;
}

// Function 4: getValidatedChoice
/* Programmer:  | Matric: 
Purpose: Ensures user input for menu selection is an integer within the valid range (1-4). */
int getValidatedChoice() {
    int choice;
    while (true) {
        cout << "Choice: ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= 6) {
                return choice; 
            } else {
                cout << "Invalid range! Please input a number between 1 and 6 only." << endl;
            }
        } else {
            cout << "Invalid type! Please input numbers only." << endl;
            cin.clear(); // Reset the error flag
            cin.ignore(100, '\n'); // Clear the buffer
        }
    }
}

// Function 10: clearScreen
/* Programmer:  | Matric: 
Purpose: Provides visual spacing by printing multiple new lines to clear the console view. */
void clearScreen() {
    for(int i = 0; i < 5; i++) cout << endl; // Your reliable version
}

// Function 11: displayExitGreeting
/* Programmer:  | Matric: 
Purpose: Displays a thank you message and pauses the program for 3 seconds before closing. */
void displayExitGreeting() {
    clearScreen();
    cout << "====================================================" << endl;
    cout << "|                                                  |" << endl;
    cout << "|       T H A N K    Y O U    F O R    U S I N G   |" << endl;
    cout << "|              T H E    S Y S T E M                |" << endl;
    cout << "|                                                  |" << endl;
    cout << "====================================================" << endl;
    cout << "|     Exiting in 3 seconds... Have a nice day!     |" << endl;
    cout << "----------------------------------------------------" << endl;
    this_thread::sleep_for(chrono::seconds(3));
}