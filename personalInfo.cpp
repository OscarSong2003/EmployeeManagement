#include<iostream>
#include "personalInfo.hpp"

const Name* PersonalInfo::getName() const { return &name; }
const Date* PersonalInfo::getBirthday() const { return &birthday; }
std::string PersonalInfo::getSIN() const { return SIN; }

PersonalInfo::PersonalInfo( std::string firstName, std::string lastName, 
std::string SIN, std::string birthMonth, int birthDay, int birthYear ) : 
name( firstName, lastName ), birthday( birthMonth, birthDay, birthYear ) {
    setSIN( SIN );
}

bool PersonalInfo::setSIN( std::string SIN ) { 
    this->SIN = SIN; 
    return true;
}


