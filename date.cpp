#include<iostream>
#include "date.hpp"

const int Date::maxDaysPerMonth = 31; 

std::string Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

Date::Date( std::string month, int year, int day ) {
    setMonth( month );
    setDay( day );
    setYear( year );
}

bool Date::setMonth( std::string month ) {
    this->month = month;
    return true;
}

bool Date::setDay( int day ) {
    if ( ( day < 1 ) || ( day > maxDaysPerMonth) ) { 
        return false; // do not set and just return false
    } else {
            // day may be set
        this->day = day;
    }
    return true;
}

bool Date::setYear( int year ) {
    // validate the year  
    if ( year < 0 ) {
            // return false since year is invalid
        return false; 
    } else {
            // set year: year is valid
        this->year = year;
    }
    return true;
}

bool Date::setFull( std::string month, int day, int year ) {
    if ( !setMonth( month ) || !setDay( day ) || !setYear( year ) ) {
        return false; // return false if any of them were invalid
    }
    return true; // is valid -> return true
}

void Date::print() const { 
    std::cout << month << " " << day << ", " << year; 
}