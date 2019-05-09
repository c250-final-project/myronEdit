#include "FILES1.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void MENU::set_MAIN_MENU(string mainMenu)
{
    MAIN_MENU = mainMenu;
}
string MENU::get_MAIN_MENU()
{
    return MAIN_MENU;
}
void MENU::set_EDIT_MENU(string editMenu)
{
    string name;
    string empID;
    string addy;
    string position;
    bool pick = 1;
    do{
        ofstream myStream ("test.txt");
        if(myStream.is_open())
        {
            cout << "enter full name (first & last) " << endl;
            cin.ignore();
            getline(cin, name);
            myStream << name << "\n";
            cout << "The name recorded on text file is " << name << endl;
            cout << "Enter employee ID\n" << endl;
            cin.ignore(0);
            getline(cin, empID);
            myStream << empID << "\n";
            cout << "The employee ID number recorded on text file is " << empID << endl;
            cout << "Enter full address (i.e. 1234 Skyline Pl, San Bruno, Ca, 94066)\n" << endl;
            cin.ignore(0);
            getline(cin, addy);
            myStream << addy << "\n";
            cout << "The address recorded on text file is " << addy << endl;
            cout << "Enter job title\n" << endl;
            cin.ignore(0);
            getline(cin, position);
            myStream << position << "\n";
            cout << "The job title/position recorded on text file is\n" << position << endl;
            
            myStream.close();
        }
        ifstream myfile ("test.txt");
        if(myfile.is_open())
        {
            getline(myfile, name);
            getline(myfile, empID);
            getline(myfile, addy);
            getline(myfile, position);
            myfile.close();
        }
        else
            cout << "Unable to open the file" << endl;
        cout << "\n\n**ALL INFORMATION STORED INTO TEXT FILE. PLEASE CHECK THERE**\n\n" << endl;
        
        EDIT_MENU = editMenu;
        cout << "Do you wish to enter another employee? Enter (1/0)" << endl;
        cin >> pick;
        if(pick != 1 && pick != 0)
        {
            cout << "invalid choice, try again" << endl;
            cin >> pick;
        }
    }while(pick == 1);
}
string MENU::get_EDIT_MENU()
{
    return EDIT_MENU;
}
void MENU::set_EMP_INFO(string empInfo)
{
    cout << "Enter the employee name " << endl;
    cin >> empInfo;
    EMP_INFO = empInfo;
}
string MENU::get_EMP_INFO()
{
    return EMP_INFO;
}


//****************************YanYan'sCode********************************************
//implement PAYROLL class setters
string PAYROLL::set_EmployeeLastName(){
    return EmployeeLastName;
}
string PAYROLL::set_EmployeeFirstName(){
    return EmployeeFirstName;
}
string PAYROLL::set_EmployeeID(){
    return EmployeeID;
}
string PAYROLL::set_Address1(){
    return Address1;
}
string PAYROLL::set_Address2(){
    return Address2;
}
string PAYROLL::set_Phone(){
    return Phone;
}
float PAYROLL::set_PayRate(){
    return PayRate;
}
string PAYROLL::set_PayStartDate(){
    return PayStartDate;
}
string PAYROLL::set_PayEndDate(){
    return PayEndDate;
}
float PAYROLL::set_HoursWorked(){
    return HoursWorked;
}
float PAYROLL::set_OverTimeHoursWorked(){
    return OverTimeHoursWorked;
}
float PAYROLL::set_VacationHoursUsed(){
    return VacationHoursUsed;
}

//implement PAYROLL class getters
string PAYROLL::get_EmployeeLastName(){
    return EmployeeLastName;
}
string PAYROLL::get_EmployeeFirstName(){
    return EmployeeFirstName;
}
string PAYROLL::get_EmployeeID(){
    return EmployeeID;
}
string PAYROLL::get_Address1(){
    return Address1;
}
string PAYROLL::get_Address2(){
    return Address2;
}
string PAYROLL::get_Phone(){
    return Phone;
}
float PAYROLL::get_PayRate(){
    return PayRate;
}
string PAYROLL::get_PayStartDate(){
    return PayStartDate;
}
string PAYROLL::get_PayEndDate(){
    return PayEndDate;
}
float PAYROLL::get_HoursWorked(){
    return HoursWorked;
}
float PAYROLL::get_OverTimeHoursWorked(){
    return OverTimeHoursWorked;
}
float PAYROLL::get_VacationHoursUsed(){
    return VacationHoursUsed;
}
float PAYROLL::get_GrossPay(){
    GrossPay = GrossPayCalc(PayRate, HoursWorked, VacationHoursUsed, OverTimeHoursWorked);
    return GrossPay;
}
float PAYROLL::get_FederalTax(){
    FederalTax = FederalTaxCalc(PayRate, HoursWorked, VacationHoursUsed, OverTimeHoursWorked);
    return FederalTax;
}
float PAYROLL::get_StateTax(){
    StateTax = StateTaxCalc(PayRate, HoursWorked, VacationHoursUsed, OverTimeHoursWorked);
    return StateTax;
}
float PAYROLL::get_NetPay(){
    NetPay = NetPayCalc(GrossPay, FederalTax, StateTax);
    return NetPay;
}

//implement PAYROLL class methods
float PAYROLL::GrossPayCalc(float PayRate, float HoursWorked, float VacationHoursUsed, float OverTimeHoursWorked)
{
    float GrossPayCalc;
    GrossPayCalc = (PayRate*(HoursWorked+VacationHoursUsed)) + (PayRate*1.5*OverTimeHoursWorked);
    return GrossPayCalc;
}
float PAYROLL::FederalTaxCalc(float PayRate, float HoursWorked, float VacationHoursUsed, float OverTimeHoursWorked)
{
    float FederalTaxCalc;
    FederalTaxCalc = ((PayRate*(HoursWorked+VacationHoursUsed)) + (PayRate*1.5*OverTimeHoursWorked))*0.10;
    return FederalTaxCalc;
}
float PAYROLL::StateTaxCalc(float PayRate, float HoursWorked, float VacationHoursUsed, float OverTimeHoursWorked)
{
    float StateTaxCalc;
    StateTaxCalc = ((PayRate*(HoursWorked+VacationHoursUsed)) + (PayRate*1.5*OverTimeHoursWorked))*0.05;
    return StateTaxCalc;
}
float PAYROLL::NetPayCalc(float GrossPay, float FederalTax, float StateTax)
{
    float NetPayCalc;
    NetPayCalc = GrossPay-FederalTax-StateTax;
    return NetPayCalc;
}

//Implement menu, search and display methods
void PayrollMainMenu (){
    cout << "PAYROLL MAIN MENU\n";
    cout << "1: Search by employee name\n";
    cout << "2: Search by employee ID\n";
    cout << "3: Return to Main Menu\n";
    cout << "Please make a selection.\n";
    int MenuSelection;
    cin >> MenuSelection;
    
    switch(MenuSelection){
        case 1: SearchByEmployeeName(); break;
        case 2: SearchByEmployeeID(); break;
        case 3: ReturnToMainMenu(); break;
        default: PayrollMainMenu(); break;
    }
};

void ReturnToMainMenu(){
    
};

void SearchByEmployeeName(){
    ifstream readfile ("EmployeeInfo.txt");
    string LastNameEntry;
    string LastName;
    string FirstName;
    string EmpID;
    string Address1;
    string Address2;
    string Phone;
    string HourRate;
    string PayStart;
    float HourlyRate;
    string PayEnd;
    float RegularHours;
    float Overtime;
    float Vacation;
    
    cout << "Enter employee's last name.\n";
    cin >> LastNameEntry;
    cout << "Enter pay start date.\n";
    cin >> PayStart;
    cout << "Enter pay end date.\n";
    cin >> PayEnd;
    cout << "Enter number of regular hours worked.\n";
    cin >> RegularHours;
    cout << "Enter number of overtime hours worked.\n";
    cin >> Overtime;
    cout << "Enter number of vacation hours used.\n";
    cin >> Vacation;
    
    while (getline(readfile,LastName)){
        if (LastName==LastNameEntry){
            getline(readfile,FirstName);
            getline(readfile,EmpID);
            getline(readfile,Address1);
            getline(readfile,Address2);
            getline(readfile,Phone);
            getline(readfile,HourRate);
            istringstream(HourRate) >> HourlyRate;
            
            cout << "Please make a selection\n";
            cout << "1. Display employee payroll information\n";
            cout << "2. Print employee paystub\n";
            int MenuSelection;
            cin >> MenuSelection;
            switch(MenuSelection){
                case 1: DisplayPayroll(PAYROLL(LastName, FirstName, EmpID, Address1, Address2, Phone, HourlyRate, PayStart, PayEnd, RegularHours, Overtime, Vacation)); break;
                case 2: PrintPaystub(PAYROLL(LastName, FirstName, EmpID, Address1, Address2, Phone, HourlyRate, PayStart, PayEnd, RegularHours, Overtime, Vacation)); break;
                default: cout << "Invalid Selection"; break;
            }
        }
    }
    PayrollMainMenu();
};

void SearchByEmployeeID(){
    ifstream readfile ("EmployeeInfo.txt");
    string IDEntry;
    string LastName;
    string FirstName;
    string EmpID;
    string Address1;
    string Address2;
    string Phone;
    string HourRate;
    string PayStart;
    string PayEnd;
    float HourlyRate;
    float RegularHours;
    float Overtime;
    float Vacation;
    int LineCounter1=0;
    int LineCounter2;
    
    cout << "Enter employee's ID.\n";
    cin >> IDEntry;
    cout << "Enter pay start date.\n";
    cin >> PayStart;
    cout << "Enter pay end date.\n";
    cin >> PayEnd;
    cout << "Enter number of regular hours worked.\n";
    cin >> RegularHours;
    cout << "Enter number of overtime hours worked.\n";
    cin >> Overtime;
    cout << "Enter number of vacation hours used.\n";
    cin >> Vacation;
    
    while (getline(readfile,EmpID)){
        if (EmpID!=IDEntry){
            LineCounter1++;
        }
        else {
            {
                if (EmpID==IDEntry)
                    getline(readfile,Address1);
                getline(readfile,Address2);
                getline(readfile,Phone);
                getline(readfile,HourRate);
                istringstream(HourRate) >> HourlyRate;
                readfile.close();
            }
        }
    }
    readfile.open ("EmployeeInfo.txt");
    for (LineCounter2=1; LineCounter2<=(LineCounter1-1);LineCounter2++){
        getline(readfile,LastName);
    }
    getline(readfile,FirstName);
    
    cout << "Please make a selection\n";
    cout << "1. Display employee payroll information\n";
    cout << "2. Print employee paystub\n";
    int MenuSelection;
    cin >> MenuSelection;
    switch(MenuSelection){
        case 1: DisplayPayroll(PAYROLL(LastName, FirstName, EmpID, Address1, Address2, Phone, HourlyRate, PayStart, PayEnd, RegularHours, Overtime, Vacation)); break;
        case 2: PrintPaystub(PAYROLL(LastName, FirstName, EmpID, Address1, Address2, Phone, HourlyRate, PayStart, PayEnd, RegularHours, Overtime, Vacation)); break;
        default: cout << "Invalid Selection"; break;
    }
    PayrollMainMenu();
};

void DisplayPayroll(PAYROLL a){
    cout << "======================================\n";
    cout << "EMPLOYEE PAYROLL INFORMATION\n";
    cout << "======================================\n";
    cout << "Employee Name: " <<a.get_EmployeeLastName() << ", " << a.get_EmployeeFirstName() << endl;
    cout << "Employee ID: " << a.get_EmployeeID() << endl;
    cout << "======================================\n";
    cout << "Pay Period: " << a.get_PayStartDate() << " to " << a.get_PayEndDate() << endl;
    cout << "======================================\n";
    cout << setprecision(2) << fixed;
    cout << "Pay Rate: $" << a.get_PayRate() << "/hour" << endl;
    cout << "Regular Hours Worked: " << a.get_HoursWorked() << endl;
    cout << "Overtime Hours Worked: " << a.get_OverTimeHoursWorked() << endl;
    cout << "Vacation Hours Used: " << a.get_VacationHoursUsed() << endl;
    cout << "======================================\n";
    cout << "Federal Tax Paid: $" << a.get_FederalTax() << endl;
    cout << "State Tax Paid : $" << a.get_StateTax() << endl;
    cout << "======================================\n";
    cout << "Gross Pay: $" << a.get_GrossPay() << endl;
    cout << "Net Pay: $" << a.get_NetPay() << endl;
    cout << "======================================\n" << endl;
}

void PrintPaystub(PAYROLL a){
    cout << "======================================\n";
    cout << "EMPLOYEE PAYSTUB\n";
    cout << "======================================\n";
    cout << "Name: " << a.get_EmployeeFirstName() << " " << a.get_EmployeeLastName() << endl;
    cout << "======================================\n";
    cout << "Address: " << a.get_Address1() << endl;
    cout << "         " << a.get_Address2() << endl;
    cout << "Phone Number: " << a.get_Phone() << endl;
    cout << "======================================\n";
    cout << "Employee ID: " << a.get_EmployeeID() << endl;
    cout << "======================================\n";
    cout << "Pay Period: " << a.get_PayStartDate() << " to " << a.get_PayEndDate() << endl;
    cout << "======================================\n";
    cout << setprecision(2) << fixed;
    cout << "Pay Rate: " << a.get_PayRate() << "/hour" << endl;
    cout << "Regular Hours Worked: " << a.get_HoursWorked() << endl;
    cout << "Overtime Hours Worked: " << a.get_OverTimeHoursWorked() << endl;
    cout << "Vacation Hours Used: " << a.get_VacationHoursUsed() << endl;
    cout << "======================================\n";
    cout << "Federal Tax Paid: " << a.get_FederalTax() << endl;
    cout << "State Tax Paid : " << a.get_StateTax() << endl;
    cout << "======================================\n";
    cout << "Gross Pay: " << a.get_GrossPay() << endl;
    cout << "Net Pay: " << a.get_NetPay() << endl;
    cout << "======================================\n" << endl;
}
