#include<iostream>
#include "seniorSalesperson.hpp"

SeniorSalesperson::SeniorSalesperson( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ) 
    : Salesperson( "Senior Salesperson", firstName, lastName, SIN, birthMonth, birthDay, 
    birthYear, hourlyPayRate, 0.03 ) { }




