#include <fstream>
#include <iostream>
#include <string>
#include "FILES1.hpp"
#include "NewEmployee.hpp"
using namespace std;
//part of Justin's code
void addEmployee (vector<NEW_EMPLOYEE>&);
void printEmployee ( const vector<NEW_EMPLOYEE>&);
void saveEmployee ( const vector<NEW_EMPLOYEE>& addNewEmployee);

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
            case 1://Yan Yan's Code
                PayrollMainMenu();
                break;
                //Myron's Code
            case 2: cout << "Place holder for EDIT EMPOLOYEES " << endl;
                myMenu.set_EDIT_MENU(x);
                break;
            case 3://Justin's code
                vector<NEW_EMPLOYEE> allEmployee;
                fstream newEmployeeFile( "newEmployee.text ", ios::in | ios::out | ios::app );
                addEmployee(allEmployee);
                saveEmployee(allEmployee);
                printEmployee(allEmployee);
                break;
//            default:
//                cout << "Invalid entry please try again " << endl;
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

//***********************Justin's Methods********************************************
void addEmployee (vector<NEW_EMPLOYEE>& addNewEmployee) {
    string fname;
    string lname;
    int new_id;
    int employeeSize,paygrade,loan;
    string employeeaddress,hiredate,designation;
    
    
    cout << " How many employees would you like to add? " << endl;
    cin >> employeeSize;
    
    
    for (int i = 0; i < employeeSize; i++) {
        cout << " Enter new employee ID:\n ";
        cin >> new_id;
        cout << " Enter employee first name:\n ";
        cin >> fname;
        cout << " Enter emplyee last name:\n ";
        cin >> lname;
        cout << " \nEnter employee address in the following order:\n street address, city, state (abbrivation), zipcode\n " << endl;
        cin.ignore();
        getline(cin, employeeaddress);
        cout <<  " Enter employee hire date\n " << endl;
        cin.ignore();
        getline(cin,hiredate);
        cout << " Enter employee paygrade: \n" << endl;
        cin >> paygrade;
        cout << " Enter employee loan amount: \n" << endl;
        cin >> loan;
        cout << " Enter employee designation: \n" << endl;
        cin.ignore();
        getline(cin,designation);
        
        cout << "\n\n";
        
        NEW_EMPLOYEE newEmployee(new_id, fname, lname, employeeaddress, hiredate, paygrade, loan, designation);
        
        
        //        NEW_EMPLOYEE newEmployeeName(fname,lname);
        //        NEW_EMPLOYEE newEmployeeHireDate(hiredate);
        
        addNewEmployee.push_back(newEmployee);
        
        
        //        addNewEmployee.push_back(newEmployeeName);
        //        addNewEmployee.push_back(employeeaddress);
        //        addNewEmployee.push_back(hiredate);
        //
        
        
        
    }
}
void saveEmployee ( const vector<NEW_EMPLOYEE>& addNewEmployee) {
    fstream newEmployeeFile( "newEmployee.text ", ios::in | ios::out | ios::app );
    
    if (newEmployeeFile.is_open()){
        for (int x = 0; x < addNewEmployee.size(); x++){
            newEmployeeFile << " employee id: " << addNewEmployee[x].get_employee_id() << endl;
            newEmployeeFile << " employee name: " << addNewEmployee[x].get_employee_name() << endl;
            newEmployeeFile << " employee address: " << addNewEmployee[x].get_employee_address() << endl;
            newEmployeeFile << " employee hire date: " << addNewEmployee[x].get_employee_hire_date() << endl;
            newEmployeeFile << " employee pay grade: " << addNewEmployee[x].get_employee_PayGrade() << endl;
            newEmployeeFile << " employee loan: " << addNewEmployee[x].get_employee_loan() << endl;
            newEmployeeFile << " employee designation " << addNewEmployee[x].get_employee_designation() << endl;
            newEmployeeFile << "-----------------------------" << endl;
            newEmployeeFile << "\n";
            
            
        }
        newEmployeeFile.close();
    }
}
void printEmployee ( const vector<NEW_EMPLOYEE>& addNewEmployee) {
    
    //    unsigned int size = addNewEmployee.size();
    
    for ( int i = 0 ; i < addNewEmployee.size(); i++) {
        cout << " employee id: " << addNewEmployee[i].get_employee_id() << endl;
        cout << " employee name: " << addNewEmployee[i].get_employee_name() << endl;
        cout << " employee address: " << addNewEmployee[i].get_employee_address() << endl;
        cout << " employee hire date: " << addNewEmployee[i].get_employee_hire_date() << endl;
        cout << " employee pay grade: " << addNewEmployee[i].get_employee_PayGrade() << endl;
        cout << " employee loan: " << addNewEmployee[i].get_employee_loan() << endl;
        cout << " employee designation " << addNewEmployee[i].get_employee_designation() << endl;
        
    }
}
