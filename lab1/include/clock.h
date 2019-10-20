//
//  clock.h
//  ASSIGNMENT1
//
//  Created by admin on 9/9/19.
//  Copyright © 2019 admin. All rights reserved.
//

#ifndef clock_h
#define clock_h

#include <iostream>

class clockType{
    
private:
    int m_hr = 0, m_min = 0, m_sec = 0;   //members of the class
    
public:
    //parametrized constructor for c1
    clockType(int hr, int min, int sec);
    
    //constructor for c2
    clockType(int hr, int min);
    
    //destructor
    ~clockType();
    
    //overloaded operator function for '+'
    clockType operator+ (const clockType& ck_obj2);
    
    //friend is to allow the access of class variables in the function
    friend std::ostream& operator << (std::ostream& os, const clockType& obj);
};
#endif /* clock_h */