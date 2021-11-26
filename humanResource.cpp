#include<iostream>
#include "humanResource.hpp"
// Make
HumanResource::HumanResource( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ) : 
    HourlyPaidEmployee( "Human Resource", firstName, lastName, SIN, birthMonth, 
    birthDay, birthYear, hourlyPayRate, 2, 44 ) { }
