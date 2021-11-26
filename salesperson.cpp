#include<iostream>
#include "salesperson.hpp"

const int Salesperson::maxNumOfPaidHours = 40;

double Salesperson::getSales() const { return sales; } 
double Salesperson::getCommission() const { return commission; }
double Salesperson::getNormalPay() const { return normalPay; }

Salesperson::Salesperson( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate, double rate ) 
    : Employee( position, firstName, lastName, SIN, birthMonth, birthDay, birthYear, hourlyPayRate ), commissionFactor( rate ) { 
        setSales( 0 ); // initialize sales
    }

bool Salesperson::reset() { 
        // first set sales to 0
        setSales( 0 );
        // call employee reset to hours to 0, which will change weekly pay as wel
        Employee::reset();
        return true;
    }

bool Salesperson::setSales( double sales ) { 
        // validate sales
        if ( sales < 0 ) { 
            std::cout << "\nERROR: The sales made of $" << sales << " for ";
            getPersonalInfo()->getName()->print( true );
            std::cout << " with\nSIN " << getPersonalInfo()->getSIN() << " is invalid. The sales amount has been" << std::endl;
            std::cout << "set to 0." << std::endl;
            this->sales = 0; 
            calcWeeklyPay();
            // invalid, so do not set 
            return false;
        }
        // valid, so set
        this->sales = sales;
        calcWeeklyPay(); // re-calculate weekly pay
        return true;
    }

double Salesperson::calcWeeklyPay() { 
        // calculate normal pay
        calcNormalPay();
        // calculate commission
        calcCommission();
        // find weekly pay by adding the two
        double weeklyPay = normalPay + commission; 
        // set the weekly pay 
        getWeeklyInfo()->setWeeklyPay( weeklyPay ); 
        return weeklyPay; // return it 
    }

double Salesperson::calcNormalPay() { 
        // check whether they worked less than the maximum amount of hours paid
        if ( getWeeklyInfo()->getNumOfHoursWorked() < maxNumOfPaidHours ) { // they worked < max time 
            // find normal pay by taking hours worked and rate
            normalPay = getWeeklyInfo()->getNumOfHoursWorked() * getGeneralInfo()->getHourlyPayRate(); 
        } else { // they worked over or equal to the max amount of time 
            // normal pay would only use the maximum amount of hours they can get paid and the rate
            normalPay = maxNumOfPaidHours * getGeneralInfo()->getHourlyPayRate(); 
        }
        return normalPay; // return it 
    }

double Salesperson::calcCommission() { 
        if ( sales > 0 ) { // sales is greater than 0 ( they will earn commission ) 
            commission = sales * commissionFactor; // find commission 
        } else { // sales is not greater than 0 ( they do NOT earn commission )
            commission = 0; // set commission to 0 
        }
        return commission; // return it 
    }

void Salesperson::printPayBreakdown() const {
        // print out the pay breakdown 
        std::cout << " - Normal Pay: $" << normalPay << std::endl;
        std::cout << " - Commission: $" << commission << std::endl;
    }

void Salesperson::printPayInfo() const { 
        // call the employee pay info to print out the main components 
        Employee::printPayInfo();
        // if they earned commission, print out the breakdown 
        if ( commission > 0 ) { 
            printPayBreakdown();
        }
    }
