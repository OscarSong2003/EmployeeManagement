#ifndef HOURLYPAIDEMPLOYEE_HPP
#define HOURLYPAIDEMPLOYEE_HPP
#include "employee.hpp" 
#include <string> 

class HourlyPaidEmployee : public Employee {

public:
    static const int maxNumOfWorkHours; 

private:
    const double overtimePayFactor; // rate that they are paid overtime 
    const double maxBasePayWorkHours; // maximum number of hours they are paid at the non-overtime rate
    double normalPay;
    double overtimePay;

public: 
    virtual double getNormalPay() const; 
    virtual double getOvertimePay() const;

    HourlyPaidEmployee( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate, double factor, double maxBaseHours );
    
    virtual bool setNumOfHoursWorked( double );  

private:
    virtual double calcNormalPay();
    virtual double calcOvertimePay();
    virtual double calcWeeklyPay();
    virtual void printPayBreakdown() const;

public:
    virtual void printPayInfo() const;
};
#endif

