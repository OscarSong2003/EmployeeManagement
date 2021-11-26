#ifndef WEEKLYWORKINFO_HPP
#define WEEKLYWORKINFO_HPP

class WeeklyWorkInfo { 

private:
    static const int numOfHoursInWeek;
    double numOfHoursWorked;
    double weeklyPay; 

public:
    virtual double getNumOfHoursWorked() const; 
    virtual double getWeeklyPay() const;

    WeeklyWorkInfo();
    WeeklyWorkInfo( double hours, double pay );

    virtual bool setNumOfHoursWorked( double );
    virtual bool setWeeklyPay( double );

};
#endif
