#ifndef HUMANRESOURCE_HPP
#define HUMANRESOURCE_HPP
#include "hourlyPaidEmployee.hpp"
#include <string> 

class HumanResource : public HourlyPaidEmployee { 

public: 
    HumanResource( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate );
};

#endif
