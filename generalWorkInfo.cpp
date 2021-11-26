#include<iostream>
#include "generalWorkInfo.hpp"

const double GeneralWorkInfo::minimumWage = 14;

std::string GeneralWorkInfo::getPosition() const { return position; }
double GeneralWorkInfo::getHourlyPayRate() const { return hourlyPayRate; }

GeneralWorkInfo::GeneralWorkInfo( std::string position, double hourlyPayRate ) {
    setPosition( position );
    setHourlyPayRate( hourlyPayRate );
}

bool GeneralWorkInfo::setPosition( std::string position ) {
    this->position = position; 
    return true;
}

bool GeneralWorkInfo::setHourlyPayRate( double payRate ) {
    if ( payRate < minimumWage ) {
            // do NOT set if invalid
        return false;
    }
        // valid, so set
    hourlyPayRate = payRate; 
    return true;
}


