#include<iostream>
#include "weeklyWorkInfo.hpp"

const int WeeklyWorkInfo::numOfHoursInWeek = 168;

double WeeklyWorkInfo::getNumOfHoursWorked() const { return numOfHoursWorked; }
double WeeklyWorkInfo::getWeeklyPay() const { return weeklyPay; }

WeeklyWorkInfo::WeeklyWorkInfo() {
	setNumOfHoursWorked( 0 );
	setWeeklyPay( 0 );
}

WeeklyWorkInfo::WeeklyWorkInfo( double hoursWorked, double pay ) {
	setNumOfHoursWorked( hoursWorked );
	setWeeklyPay( pay ); 
}

bool WeeklyWorkInfo::setNumOfHoursWorked( double hours ) {
	if ( ( hours < 0 ) || ( hours > numOfHoursInWeek ) ) {
			// do not set if invalid
		return false;
	}
	numOfHoursWorked = hours;
	return true;
}

bool WeeklyWorkInfo::setWeeklyPay( double weeklyPay ) {
	if ( weeklyPay < 0 ) { 
			// invalid, so do NOT set
		return false;
	}
		// valid, so set 
	this->weeklyPay = weeklyPay; 
	return true;
}
