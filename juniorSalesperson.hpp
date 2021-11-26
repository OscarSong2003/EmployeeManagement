#ifndef JUNIORSALESPERSON_HPP
#define JUNIORSALESPERSON_HPP
#include "salesperson.hpp"
#include<string>

class JuniorSalesperson : public Salesperson { 

public:
    JuniorSalesperson( std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate );
};
#endif
