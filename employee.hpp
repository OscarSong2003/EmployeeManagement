#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "personalInfo.hpp"
#include "generalWorkInfo.hpp" 
#include "weeklyWorkInfo.hpp"
#include <string>

class Employee {

private:
    PersonalInfo personalInfo; // name, birthday, SIN
    GeneralWorkInfo generalInfo; // position, hourly pay rate
    WeeklyWorkInfo weeklyInfo;
    static int numOfEmployee;

public:
    virtual const WeeklyWorkInfo *getWeeklyWorkInfo() const;

protected:
    virtual const PersonalInfo *getPersonalInfo() const;
    virtual const GeneralWorkInfo *getGeneralInfo() const;
    virtual WeeklyWorkInfo *getWeeklyInfo();

public: 
    static const double maximumWage;

    Employee( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate ); 

    virtual bool setNumOfHoursWorked( double );
    virtual bool setHourlyPayRate( double );
    virtual bool reset(); 
    virtual void printPayInfo() const;
    virtual void printInfo() const;
    virtual void printCheque() const;
    virtual double calcWeeklyPay(); 
};
#endif
