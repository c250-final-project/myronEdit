# myronEdit
working on main and experimenting with other aspects of payroll TBA

//
//  Created by Myron P on 4/25/19.
//  Copyright © 2019 myName. All rights reserved.
//

#include <iostream>
using namespace std;

//void DisplayMain()
//{
//
//}

int main(int argc, const char * argv[])
{
//    DisplayMain();
    int choice;
    char pick = 'n';
    do
    {
        cout << "** PAYROLL EMPLOYEE MENU **" << endl;
        cout << "===========================" << endl;
        cout << "Enter the category number:\n " << endl;
        cout << "(1) For employee records" << endl;
        cout << "(2) For employee status" << endl;
        cout << "(3) For employee hours" << endl;
        cout << "(4) For employee overtime" << endl;
        cout << "(5) For employee history" << endl;
        cout << "Please enter below:" << endl;
        cin >> choice;
    switch(choice)
    {
        case 1: cout << "Case employee records (PLACE HOLDER FOR ACTUAL CATEGORY) " << endl;
//            theirclass thisobject;
//            thisobject.theirfunc();
            break;
        case 2: cout << "Case employee status (PLACE HOLDER FOR ACTUAL CATEGORY) " << endl;
            break;
        case 3: cout << "Case employee hours (PLACE HOLDER FOR ACTUAL CATEGORY) " << endl;
            break;
        case 4: cout << "Case employee overtime (PLACE HOLDER FOR ACTUAL CATEGORY) " << endl;
            break;
        case 5: cout << "Case employee hisotry (PLACE HOLDER FOR ACTUAL CATEGORY) " << endl;
        default:
            cout << "Invalid entry, try again" << endl;
    }
        cout << "Do you wish to pick another category? (y/n)?" << endl;
        cin >> pick;
    }while(pick != 'n');
    return 0;
}
