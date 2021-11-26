#ifndef SECRETARY_HPP
#define SECRETARY_HPP
#include "hourlyPaidEmployee.hpp"
#include<string>

class Secretary : public HourlyPaidEmployee {

public:
    Secretary( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ); 
};

#endif
