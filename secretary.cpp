#include <iostream>
#include "secretary.hpp"

Secretary::Secretary( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ) : 
    HourlyPaidEmployee( "Secretary", firstName, lastName, SIN, birthMonth, birthDay, 
    birthYear, hourlyPayRate, 1.5, 40 ) { } 

