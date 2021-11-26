#include<iostream>
#include "name.hpp"

std::string Name::getFirst() const { return first; }
std::string Name::getLast() const { return last; }

Name::Name( std::string first, std::string last ) {
    setFirst( first );
    setLast( last );
}

std::string Name::setFirst( std::string first ) {
    this->first = first;
    return first;
}

std::string Name::setLast( std::string last ) {
    this->last = last;
    return last;
}

bool Name::setFull( std::string first, std::string last ) {
    setFirst( first );
    setLast( last );
    return true;
}

void Name::print( bool firstLast ) const {
    if ( firstLast) { 
        std::cout << first << " " << last; 
        // the user wants to print the lastname then first name
    } else {
        std::cout << last << ", " << first;
    }
}

