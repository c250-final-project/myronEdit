#ifndef FILES1_hpp
#define FILES1_hpp
#endif /* FILES1_hpp */
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
using namespace std;
//Myron's code
class MENU
{
public:
    MENU(string mainMenu, string editMenu, string empInfo)
    {
        //full fledged constructor
        MAIN_MENU = mainMenu;
        EDIT_MENU = editMenu;
        EMP_INFO = empInfo;
        
    }
    MENU(string mainMenu, string editMenu)
    {
        //two args constructor
        MENU(mainMenu, editMenu, "Default name");
        
    }
    MENU(string mainMenu)
    {
        //one arg constructor
        MENU(mainMenu, "Default name");
        
    }
    MENU()
    {
        //no args constructor
    }
    
    void set_MAIN_MENU(string mainMenu);
    void set_EDIT_MENU(string editMenu);
    void set_EMP_INFO(string empInfo);
    string get_MAIN_MENU();
    string get_EDIT_MENU();
    string get_EMP_INFO();
private:
    string MAIN_MENU;
    string EDIT_MENU;
    string EMP_INFO;
};



//***********************YanYan's NEW CLASS PAYROLL************************
class PAYROLL{
private:
    string EmployeeLastName;
    string EmployeeFirstName;
    string EmployeeID;
    string Address1;
    string Address2;
    string Phone;
    float PayRate;
    string PayStartDate;
    string PayEndDate;
    float HoursWorked;
    float OverTimeHoursWorked;
    float VacationHoursUsed;
    float GrossPay;
    float FederalTax;
    float StateTax;
    float NetPay;
    
public:
    PAYROLL();
    PAYROLL(string a, string b, string c, string d, string e, string f, float g, string h, string i, float j, float k, float l){
        
        EmployeeLastName = a;
        EmployeeFirstName = b;
        EmployeeID = c;
        Address1 = d;
        Address2 = e;
        Phone = f;
        PayRate = g;
        PayStartDate = h;
        PayEndDate = i;
        HoursWorked = j;
        OverTimeHoursWorked = k;
        VacationHoursUsed = l;
    }
    //PAYROLL class setters
    string set_EmployeeLastName();
    string set_EmployeeFirstName();
    string set_EmployeeID();
    string set_Address1();
    string set_Address2();
    string set_Phone();
    float set_PayRate();
    string set_PayStartDate();
    string set_PayEndDate();
    float set_HoursWorked();
    float set_OverTimeHoursWorked();
    float set_VacationHoursUsed();
    
    //PAYROLL class getters
    string get_EmployeeLastName();
    string get_EmployeeFirstName();
    string get_EmployeeID();
    string get_Address1();
    string get_Address2();
    string get_Phone();
    float get_PayRate();
    string get_PayStartDate();
    string get_PayEndDate();
    float get_HoursWorked();
    float get_OverTimeHoursWorked();
    float get_VacationHoursUsed();
    float get_GrossPay();
    float get_FederalTax();
    float get_StateTax();
    float get_NetPay();
    
    //PAYROLL methods
    float GrossPayCalc(float PayRate, float HoursWorked, float VacationHoursUsed, float OverTimeHoursWorked);
    float FederalTaxCalc(float PayRate, float HoursWorked, float VacationHoursUsed, float OverTimeHoursWorked);
    float StateTaxCalc(float PayRate, float HoursWorked, float VacationHoursUsed, float OverTimeHoursWorked);
    float NetPayCalc(float GrossPay, float FederalTax, float StateTax);
};

//Menu, search and display methods
void PayrollMainMenu ();
void SearchByEmployeeName();
void SearchByEmployeeID();
void ReturnToMainMenu();
void DisplayPayroll(PAYROLL a);
void PrintPaystub(PAYROLL a);
