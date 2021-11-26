#include<iostream>
#include "juniorSalesperson.hpp"

JuniorSalesperson::JuniorSalesperson( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ) : 
    Salesperson( "Junior Salesperson", firstName, lastName, SIN, birthMonth, birthDay, birthYear, 
    hourlyPayRate, 0.02 ) { }

