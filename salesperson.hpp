#ifndef SALESPERSON_HPP
#define SALESPERSON_HPP
#include "employee.hpp"
#include <string>
class Salesperson : public Employee {

private: 
    // member variables
    double sales; 
    double normalPay;  
    const double commissionFactor; // multiplier that is applied to commission 
    double commission;

public: 
    static const int maxNumOfPaidHours;
    virtual double getSales() const;
    virtual double getCommission() const;
    virtual double getNormalPay() const;

    Salesperson( std::string position, std::string firstName, std::string lastName, std::string SIN, std::string birthMonth, 
    int birthDay, int birthYear, double hourlyPayRate, double rate ); 

    virtual bool reset();
    virtual bool setSales( double sales ); 

protected:
    virtual double calcWeeklyPay();

private: 
    virtual double calcNormalPay(); 
    virtual double calcCommission();
    virtual void printPayBreakdown() const;

public:
    virtual void printPayInfo() const;
};

#endif
