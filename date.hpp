#ifndef DATE_HPP
#define DATE_HPP 
#include<string>
class Date {

private:
    std::string month; 
    int day; 
    int year;
    static const int maxDaysPerMonth;

public:
    virtual std::string getMonth() const; 
    virtual int getDay() const;
    virtual int getYear() const;

    Date( std::string, int, int );

private: 
    virtual bool setMonth( std::string );
    virtual bool setDay( int );
    virtual bool setYear( int );
    virtual bool setFull( std::string, int, int );

public: 
    virtual void print() const; 
};


#endif

