#ifndef NAME_HPP
#define NAME_HPP
#include<string>
class Name {

protected: 
    std::string first;
    std::string last;

public:
    virtual std::string getFirst() const; 
    virtual std::string getLast() const;
    // first, last
    Name( std::string, std::string );

private: 
    virtual std::string setFirst( std::string ); 
    virtual std::string setLast( std::string );
    virtual bool setFull( std::string, std::string ); 

public: 
    virtual void print( bool ) const; 
};

#endif