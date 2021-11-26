#include <iostream>
#include "employee.hpp"

int Employee::numOfEmployee = 0;
const double Employee::maximumWage = 100;

const WeeklyWorkInfo* Employee::getWeeklyWorkInfo() const { return &weeklyInfo; }
const PersonalInfo* Employee::getPersonalInfo() const { return &personalInfo; }
const GeneralWorkInfo* Employee::getGeneralInfo() const { return &generalInfo; }
WeeklyWorkInfo* Employee::getWeeklyInfo() { return &weeklyInfo; }

Employee::Employee( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth,
int birthDay, int birthYear, double hourlyPayRate ) : personalInfo(firstName, lastName, SIN, birthMonth, birthDay, birthYear ),
generalInfo( position, hourlyPayRate ), weeklyInfo() {
    numOfEmployee++;
    setHourlyPayRate(hourlyPayRate);
    setNumOfHoursWorked(0);
}

bool Employee::setNumOfHoursWorked( double hoursWorked ) {
    // call the set hours function inside the weeklyInfo class
    if ( !weeklyInfo.setNumOfHoursWorked( hoursWorked ) ) { // it will set if valid
        std::cout << "\nERROR: The number of hours worked of " << hoursWorked << " Hours for " << std::endl;
        getPersonalInfo()->getName()->print( true );
        std::cout << " with SIN " << getPersonalInfo()->getSIN() << " is invalid. The number of" << std::endl;
        std::cout << "hours worked has been set to 0." << std::endl;
        weeklyInfo.setNumOfHoursWorked( 0 ); // set the number hours worked to 0
        calcWeeklyPay();                   // calculate the weekly pay
        // invalid, so do not set
        return false;
    }
    // calculate the weekly pay if valid and set
    calcWeeklyPay();
    return true;
}

bool Employee::setHourlyPayRate( double payRate ) {
        // first check if its greater than max wage ( if it is then print out error right away )
        // if not then check to see if hourly pay rate can be set ( calling setHourlyPayRate inside generalInfo )
        if ( ( payRate > maximumWage ) || ( !generalInfo.setHourlyPayRate( payRate ) ) ) { 
            // print error statement
            std::cout << "\nERROR: The hourly pay rate of $" << payRate << "/Hr for "; 
            getPersonalInfo()->getName()->print( true ); 
            std::cout << "\nwith SIN " << personalInfo.getSIN() << " is invalid. The hourly pay rate has" << std::endl;
            std::cout << "been set to the minimum wage of $" << GeneralWorkInfo::minimumWage << "/Hr." << std::endl;
            // set hourly pay rate to minimum wage
            generalInfo.setHourlyPayRate( GeneralWorkInfo::minimumWage );
            calcWeeklyPay(); // calculate the weekly pay
            return false;
        } 
        // if valid, then it will be set already above and we will then calculate weekly pay
        calcWeeklyPay(); 
        return true;
    } 

bool Employee::reset() { 
        // set their number of hours worked to 0 
    setNumOfHoursWorked( 0 );
    return true;
}

void Employee::printPayInfo() const { // Report #1 (Parts of it at least)
    std::cout << "Position: " << generalInfo.getPosition() << std::endl; // print position
    std::cout << "Name: "; // print name
    personalInfo.getName()->print( false ); // we want to print last, first 
    std::cout << "\nHourly Pay Rate: $" << generalInfo.getHourlyPayRate() << "/Hr" << std::endl; // print pay rate
    std::cout << "Number of Hours Worked: " << weeklyInfo.getNumOfHoursWorked() << std::endl; // print hours worked
    std::cout << "Weekly Pay: $" << weeklyInfo.getWeeklyPay() << std::endl; // print weekly pay 
}

void Employee::printInfo() const { // Report #2 
    std::cout << "Name: "; // print name
    personalInfo.getName()->print( false );
    std::cout << "\nPosition: " << generalInfo.getPosition() << std::endl; // print position
    std::cout << "Birthday: "; 
    personalInfo.getBirthday()->print(); // print birthday
    std::cout << "\nSIN: " << personalInfo.getSIN() << std::endl; // print SIN
    std::cout << "Hourly Pay Rate: $" << generalInfo.getHourlyPayRate() << "/Hr" << std::endl; // print hourly pay rate
}

void Employee::printCheque() const { // Report #3 Cheque
    if ( weeklyInfo.getWeeklyPay() > 0 ) { // check to make sure weekly pay is greater than 0 
        std::cout << "Payable to ";
        personalInfo.getName()->print( true ); 
        std::cout << " in the amount of $" << weeklyInfo.getWeeklyPay() << "." << std::endl;
        std::cout << "\n";
    }
}

double Employee::calcWeeklyPay() { return 0; } 