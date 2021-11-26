#include <iostream>
#include "manager.hpp"

Manager::Manager( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
int birthDay, int birthYear, double hourlyPayRate ) : 
SalaryBasedEmployee( "Manager", firstName, lastName, SIN, birthMonth, birthDay, birthYear, 
hourlyPayRate ) { }


