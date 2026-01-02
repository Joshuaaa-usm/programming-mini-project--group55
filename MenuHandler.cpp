#include "StudentSystem.hpp"
#include <thread>
#include <chrono>

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

void clearScreen() {
    for(int i = 0; i < 5; i++) cout << endl; // Your reliable version
}

int getValidatedChoice() {
    int choice;
    while (true) {
        cout << "\nChoice: ";
        if (cin >> choice && choice >= 1 && choice <= 4) return choice;
        cout << "Invalid! Please enter 1-4.";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

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