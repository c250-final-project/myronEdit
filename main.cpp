//main
//  Created by Myron P on 4/25/19.
//  Copyright © 2019 myName. All rights reserved.
#include <fstream>
#include <iostream>
#include <string>
#include "FILES.hpp"
using namespace std;
void displayall(MENU categories)
{
    MENU myMenu;
    int choice;
    string x;
    char pick = 'y';
    do{
        cout << "ENTER THE NUMBER FOR A CATEGORY " << endl;
        cout << "********************************\n" << endl;
        cout << "(1) For EMPLOYEES " << endl;
        cout << "(2) Edit EMPLOYEES " << endl;
        cout << "(3) EMPLOYEE info " << endl;
        cin >> choice;
        switch(choice)
        {
            case 1: PayrollMainMenu();
                break;
            case 2: cout << "Place holder for EDIT EMPOLOYEES " << endl;
                myMenu.set_EDIT_MENU(x);
                break;
            case 3: cout << "Place holder for EMPLOYEE INFO " << endl;
                myMenu.set_EMP_INFO(x);
                break;
            default:
                cout << "Invalid entry please try again " << endl;
        }
        cout << "Do you wish to go back to main menu? (y/n)?" << endl;
        cin >> pick;
    }while(pick == 'y');
    
}

int main(int argc, const char * argv[]) {
    //    MENU new_menu = MENU("Employee", "Employee Edit", "Employee Information");
    MENU menu;
    displayall(menu);
    //    displayall(new_menu);
    return 0;
}


