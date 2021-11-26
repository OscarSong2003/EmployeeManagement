#ifndef PERSONALINFO_HPP
#define PERSONALINFO_HPP
#include "name.hpp"
#include "date.hpp"
#include<string>

class PersonalInfo {

private: 
    // member variables
    Name name; 
    Date birthday;
    std::string SIN;

public:
    virtual const Name* getName() const; 
    virtual const Date* getBirthday() const;
    virtual std::string getSIN() const; 

    PersonalInfo( std::string first, std::string last, std::string SIN, std::string month, int day, int year ); 

private:
    virtual bool setSIN( std::string );
};

#endif

