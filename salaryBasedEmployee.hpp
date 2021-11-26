#ifndef SALARYBASEDEMPLOYEE_HPP
#define SALARYBASEDEMPLOYEE_HPP
#include "employee.hpp"
#include<string>

class SalaryBasedEmployee : public Employee{

public:
    // class variable
    static const int maxNumOfPaidHours;
    SalaryBasedEmployee( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ); 

protected:
    virtual double calcWeeklyPay(); 
};
#endif
