#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "salaryBasedEmployee.hpp"
#include<string>

class Manager : public SalaryBasedEmployee { 

public:
    Manager( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ); 
};

#endif 

