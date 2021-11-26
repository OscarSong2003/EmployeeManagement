#ifndef ACCOUNTANT_HPP
#define ACCOUNTANT_HPP
#include "salaryBasedEmployee.hpp"
#include <string>
class Accountant : public SalaryBasedEmployee { 

public: 
    Accountant( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate );
    
};
#endif