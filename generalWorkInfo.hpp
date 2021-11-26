#ifndef GENERALWORKINFO_HPP
#define GENERALWORKINFO_HPP
#include<string>

class GeneralWorkInfo { 

private: 
    // member variables
    std::string position; 
    double hourlyPayRate;

public:
    static const double minimumWage; 
    
    virtual std::string getPosition() const; 
    virtual double getHourlyPayRate() const; 

    GeneralWorkInfo( std::string, double ); 

private: 
    virtual bool setPosition( std::string );

public: 
    virtual bool setHourlyPayRate( double ); 
}; 

#endif

