#include <iostream>
#include <iomanip>
#include <fstream>
#include "employee.hpp"
#include "salaryBasedEmployee.hpp"
#include "hourlyPaidEmployee.hpp" 
#include "salesperson.hpp"
#include "manager.hpp"
#include "accountant.hpp"
#include "secretary.hpp"
#include "humanResource.hpp"
#include "juniorSalesperson.hpp"
#include "seniorSalesperson.hpp"

using namespace std;

// constant variables for company positions 
// Note: I have a preference for upper case so I won't be using these for storing the position
// they will only be used to check input of position from file
const string managerPos = "manager";
const string accountantPos = "accountant";
const string secretaryPos = "secretary";
const string HRPos = "human resource";
const string juniorSalesPos = "junior salesperson";
const string seniorSalesPos = "senior salesperson";
// constants 
const int MAX_MANAGERS = 4;
const int MAX_ACCOUNTANTS = 3;
const int MAX_SECRETARIES = 7;
const int MAX_HR = 2;
const int MAX_SALESPEOPLE = 30;
const int MAX_EMPLOYEES = MAX_MANAGERS + MAX_ACCOUNTANTS + MAX_SECRETARIES + MAX_HR + MAX_SALESPEOPLE;  
const int DEBUG = 0; 

int main() { 
    
    // variables to store temporary info
    string junk; 
    string filename;
    string position;
    string fName;
    string lName;
    string SIN;
    string birthMonth;
    int birthDay;
    int birthYear;
    double payRate;
    double hours;
    int salesMade;
    // array of employees ++++++++++++
    Employee *employees[MAX_EMPLOYEES];
    int numEmployees = 0; // counter that keeps track of employee; also used as an index
    ifstream inputFile; // C++ object that represents a file
    double totalWeeklyPay = 0; 
    int index;

    // set output of doubles to 2 decimal places
    cout << std::setprecision(2) << std::fixed;
    cout << "Welcome to the ultimate employee management program v2!" << endl;
    // get the name of the data file
    cout << "\nPlease enter the name of the data file: ";
    getline( cin, filename );

    // open the file for reading
    inputFile.open( filename );
    getline( inputFile, position );

    // process the data file to read in an employee's information, and create
    // the appropriate employees to store within our array.
    while ( position != "END" ) {  
        // ensure that the number of employees is less than maximum amount 
        if ( numEmployees < MAX_EMPLOYEES ) { 
            getline( inputFile, lName ); // read in last name
            getline( inputFile, fName ); // read in first name
            getline( inputFile, SIN ); // read in SIN
            getline( inputFile, birthMonth ); // read in birth month
            inputFile >> birthDay; // read in birthday
            getline( inputFile, junk );
            inputFile >> birthYear; // read in birth year
            getline( inputFile, junk );
            inputFile >> payRate; // read in pay rate
            getline( inputFile, junk );
            inputFile >> hours; // read in hours worked
            getline( inputFile, junk );
            if ( position == managerPos ) { // position is manager
                // create manager employee
                employees[numEmployees] = new Manager( fName, lName, SIN, birthMonth,
                        birthDay, birthYear, payRate );
            } else if ( position == accountantPos ) { // position is accountant
                // create accountant employee
                employees[numEmployees] = new Accountant( fName, lName, SIN, birthMonth,
                        birthDay, birthYear, payRate );
            } else if ( position == secretaryPos ) { // position is secretary
                // create secretary employee
                employees[numEmployees] = new Secretary( fName, lName, SIN, birthMonth,
                        birthDay, birthYear, payRate );
            } else if ( position == HRPos ) { // position is human resource
                // create human resource employee
                employees[numEmployees] = new HumanResource( fName, lName, SIN, birthMonth,
                        birthDay, birthYear, payRate );
            } else if ( position == juniorSalesPos ) { // position is junior salesperson
                // create junior salesperson employee
                employees[numEmployees] = new JuniorSalesperson( fName, lName, SIN, birthMonth,
                        birthDay, birthYear, payRate );
                // read in sales
                inputFile >> salesMade;
                getline( inputFile, junk );
                // set the sales ( casting so that the employee know that it is a junior salesperson )
                ( (JuniorSalesperson*) employees[numEmployees] )->setSales( salesMade );
            } else if ( position == seniorSalesPos ) { // position is senior salesperson 
                // create senior salesperson employee
                employees[numEmployees] = new SeniorSalesperson( fName, lName, SIN, birthMonth,
                        birthDay, birthYear, payRate );
                // read in sales
                inputFile >> salesMade; 
                getline( inputFile, junk );
                // set the sales ( casting so that the employee know that it is a senior salesperson )
                ( (SeniorSalesperson*) employees[numEmployees] )->setSales( salesMade );
            } else { 
                // print out error if it is none of the above positions
                cout << "(U): Unknown employee position '" << position << "'... aborting." << endl;
                return 99;
            }
            // set number of hours worked ( this will then calculate the weekly pay )
            employees[numEmployees]->setNumOfHoursWorked( hours );
            // calculate the total weekly pay by adding it to running total
            totalWeeklyPay+=employees[numEmployees]->getWeeklyWorkInfo()->getWeeklyPay();
            numEmployees++; // increment employee count
            getline( inputFile, position ); // read in the next position 
        } else { // number of employee is equal to max amount
            // print out error statement and proceed to printing the reports 
            cout << "\nSorry! You have exceeded the maximum amount of employees" << endl;
            cout << "allowed of " << MAX_EMPLOYEES << " for the company. The exceeding data will not" << endl;
            cout << "be stored into the system." << endl; 
            break; 
        }
    }
    // check to make sure there are employees
    if ( numEmployees > 0 ) {
        // print report 1
        cout << "\nReport #1: Pay Information" << endl;
        for (index = 0; index < numEmployees; index++) {
            cout << "\n";
            employees[index]->printPayInfo(); 
            }
        cout << "\n";
        // print report 2
        cout << "Report #2: Employee Information" << endl;
        for (index = 0; index < numEmployees; index++) {
            cout << "\n";
            employees[index]->printInfo();
        }
        cout << "\n";
        // print report 3
        // print cheques if total weekly pay is greater than 0 
        if (totalWeeklyPay > 0) {
            cout << "Report #3: Company Cheques\n"
                 << endl;
            for (index = 0; index < numEmployees; index++) {
                employees[index]->printCheque();
            }
        }
    }

    // print final overview
    cout << "Final Summary: " << endl;
    cout << "\nTotal Number of Employees: " << numEmployees << endl;
    cout << "Total Weekly Pay: $" << totalWeeklyPay << "\n" << endl;
    cout << "Thank you for using this program!" << endl; // closing statement

    // reset 
    for (int i = 0; i < numEmployees; i++) {
        employees[i]->reset();
    }
    // DEBUG to check reset status ( only report 1 is needed ) 
    if ( DEBUG ) { 
        cout << "\nRESETTED EMPLOYEES: " << endl;
        cout << "\nReport #1: Pay Information" << endl;
        for ( index = 0; index < numEmployees; index++ ) {
            cout << "\n"; 
            employees[index]->printPayInfo();
        }
        cout << "\n";
    }
    return 0;
}


