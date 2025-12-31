#include <iostream>
#include "Auth.h"
using namespace std;

/*
Programmer: Group 55
Function: login
Purpose: Identify if the user is an Admin or a Viewer
*/
int login() {
    string user, pass;
    cout << "\n--- USM SYSTEM LOGIN ---\n";
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    if (user == "admin" && pass == "usm123") {
        cout << "Logged in as ADMIN.\n";
        return 1; // Admin code
    } 
    else if (user == "viewer" && pass == "usm456") {
        cout << "Logged in as VIEWER (Read-only).\n";
        return 2; // Viewer code
    } 
    else {
        cout << "Invalid credentials!\n";
        return 0; // Failed code
    }
}