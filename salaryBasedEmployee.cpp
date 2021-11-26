#include<iostream>
#include "salaryBasedEmployee.hpp"

const int SalaryBasedEmployee::maxNumOfPaidHours = 40;

SalaryBasedEmployee::SalaryBasedEmployee( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
int birthDay, int birthYear, double hourlyPayRate ) 
: Employee( position, firstName, lastName, SIN, birthMonth, birthDay, birthYear, hourlyPayRate ) { }

double SalaryBasedEmployee::calcWeeklyPay() {  
        // calculate weekly pay 
    double weeklyPay = maxNumOfPaidHours * getGeneralInfo()->getHourlyPayRate();   
        // set weekly pay
    getWeeklyInfo()->setWeeklyPay( weeklyPay );
        // return it 
    return weeklyPay;
}
