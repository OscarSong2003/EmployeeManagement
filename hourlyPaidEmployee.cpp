#include<iostream>
#include "hourlyPaidEmployee.hpp"

const int HourlyPaidEmployee::maxNumOfWorkHours = 60;

double HourlyPaidEmployee::getNormalPay() const { return normalPay; }
double HourlyPaidEmployee::getOvertimePay() const { return overtimePay; }

HourlyPaidEmployee::HourlyPaidEmployee( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
int birthDay, int birthYear, double hourlyPayRate, double factor, double maxBaseHours ) 
: Employee( position, firstName, lastName, SIN, birthMonth, birthDay, birthYear, hourlyPayRate ), 
overtimePayFactor( factor ), maxBasePayWorkHours( maxBaseHours ) { }

bool HourlyPaidEmployee::setNumOfHoursWorked( double hoursWorked ) { 
        // validate number of hours worked 
        // first check if hours worked is greater than max hours ( if it is then print out error right away )
        // then if less than or equal to max then call the set hours function from employee and see if it is 
        // invalid ( if invalid then also print error ). If valid, it will be set. 
    if ( ( hoursWorked > maxNumOfWorkHours ) || ( !Employee::setNumOfHoursWorked( hoursWorked ) ) ) {
            // print error statement
        std::cout << "\nERROR: The number of hours worked of " << hoursWorked << " Hours for " << std::endl;
        getPersonalInfo()->getName()->print( true );
        std::cout << " with SIN " << getPersonalInfo()->getSIN() << " is invalid. The number of" << std::endl;
        std::cout << "hours worked has been set to 0." << std::endl;
        Employee::setNumOfHoursWorked( 0 ); // set the number hours worked to 0
        return false; 
    } 
    return true;
}

double HourlyPaidEmployee::calcNormalPay() { 
        // check whether number of hours is greater than the max hours paid at base rate
    if ( getWeeklyInfo()->getNumOfHoursWorked() > maxBasePayWorkHours ) { // number of hours worked is greater than max base pay hours 
            // only use the max amount of hours paid at base rate to calculate normal pay
        normalPay = maxBasePayWorkHours * getGeneralInfo()->getHourlyPayRate();
            
    } else { // it is less than or equal to max base pay
            // calculate by just taking number hours multiplying it by the hourly pay rate
        normalPay = getGeneralInfo()->getHourlyPayRate() * getWeeklyInfo()->getNumOfHoursWorked();
    }
    return normalPay; // return it
} 

double HourlyPaidEmployee::calcOvertimePay() { 
        // check if hours worked is greater than max pay hours ( to qualify for overtime pay )
        if ( getWeeklyInfo()->getNumOfHoursWorked() > maxBasePayWorkHours ) { // it qualifies
            // find overtime pay by using overtime, pay factor, and pay rate
            overtimePay = ( getWeeklyInfo()->getNumOfHoursWorked() - maxBasePayWorkHours ) * 
            ( overtimePayFactor ) * ( getGeneralInfo()->getHourlyPayRate() ); 
        } else { // did not work overtime 
            overtimePay = 0; // set overtime to 0 
        }
        return overtimePay; // return it
    }

double HourlyPaidEmployee::calcWeeklyPay() { 
        // calculate normal pay
        calcNormalPay();
        // calculate overtime pay
        calcOvertimePay();
        // calculate weekly pay by adding the two
        double weeklyPay = normalPay + overtimePay;
        // set the weekly pay 
        getWeeklyInfo()->setWeeklyPay( weeklyPay );
        return weeklyPay; // return it
    }

void HourlyPaidEmployee::printPayBreakdown() const {
        std::cout << " - Normal Pay: $" << normalPay << std::endl; // print normal pay
        std::cout << " - Overtime Pay: $" << overtimePay << std::endl; // print overtime pay
    }

void HourlyPaidEmployee::printPayInfo() const { 
        // call the employee print pay info to print the info 
        Employee::printPayInfo(); 
        // print out the additional pay breakdown if overtime pay is greater than 0 
        if ( overtimePay > 0 ) { 
            printPayBreakdown();
        }
    }


