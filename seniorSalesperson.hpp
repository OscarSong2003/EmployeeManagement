#ifndef SENIORSALESPERSON_HPP
#define SENIORSALESPERSON_HPP
#include "salesperson.hpp"
#include <string>

class SeniorSalesperson : public Salesperson {
    
public: 
    SeniorSalesperson( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate );
}; 
#endif