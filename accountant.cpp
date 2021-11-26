#include <iostream>
#include "accountant.hpp"

Accountant::Accountant( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
int birthDay, int birthYear, double hourlyPayRate ) : 
SalaryBasedEmployee( "Accountant", firstName, lastName, SIN, birthMonth, birthDay, birthYear, 
hourlyPayRate ) { }


