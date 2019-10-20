#include "complexNumber.hpp"
#include <iostream>

complexNum::complexNum(int re, int i)
{
    m_real = re;
    m_img = i;  
}

complexNum::~complexNum()
{

}

void complexNum::printNum()
{
    std::cout << this->toString() << std::endl;
}


complexNum complexNum::operator+(complexNum& rhs_complex_num)
{
    int re, img;
    re = m_real + rhs_complex_num.m_real;
    img = m_img + rhs_complex_num.m_img;

    return complexNum(re,img);
}

complexNum& complexNum::operator+=(complexNum& rhs_complex_num)
{
    this->m_real += rhs_complex_num.m_real;
    this->m_img += rhs_complex_num.m_img;
    return *this;
}

complexNum complexNum::operator-(complexNum& rhs_complex_num)
{
    int re, img;
    re = m_real - rhs_complex_num.m_real;
    img = m_img - rhs_complex_num.m_img;

    return complexNum(re,img);
}

complexNum& complexNum::operator-=(complexNum& rhs_complex_num)
{
    this->m_real -= rhs_complex_num.m_real;
    this->m_img -= rhs_complex_num.m_img;
    return *this;
}

std::string complexNum::toString()
{
    std::string complex_string = "";
    if(m_img >= 0)
    {
        complex_string = std::to_string(m_real) + " + " + std::to_string(m_img) + "i";
    }
    else
    {
        complex_string = std::to_string(m_real) + std::to_string(m_img) + "i";
    }
    return complex_string;
}