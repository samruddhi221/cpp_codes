//
//  clock.cpp
//  ASSIGNMENT1
//
//  Created by admin on 9/9/19.
//  Copyright © 2019 admin. All rights reserved.
//

#include "clock.h"
#include <iostream>

clockType::clockType(int hr, int min, int sec)
{
    m_hr = hr;
    m_min = min;
    m_sec = sec;
};

//constructor for c2
clockType::clockType(int hr, int min)
{
    m_hr = hr;
    m_min = min;
};

//destructor
clockType::~clockType(){};

clockType clockType::operator+ (const clockType& ck_obj2)
{
    int clk_ovf = 0;  //clock_overflow
    
    int sec = ck_obj2.m_sec + this->m_sec;
    clk_ovf = sec/60;
    sec = sec%60;
    
    int min = ck_obj2.m_min + this->m_min + clk_ovf;
    clk_ovf = 0;
    clk_ovf = min/60;
    min = min%60;
    
    int hr = ck_obj2.m_hr + this->m_hr + clk_ovf;
    
    return clockType(hr,min,sec);
}

std::ostream& operator << (std::ostream& os, clockType const & obj)
{
    os << obj.m_hr << ":" << obj.m_min << ":" << obj.m_sec;
    return os;
}