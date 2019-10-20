#include "complexNumber.hpp"
#include <iostream>

template <class T>
complexNum<T>::complexNum(T re, T i)
{
    m_real = re;
    m_img = i;  
}

template <class T>
complexNum<T>::~complexNum()
{

}

template <class T>
void complexNum<T>::printNum()
{
    std::cout << this->toString() << std::endl;
}

template <class T>
complexNum<T> complexNum<T>::operator+(complexNum<T>& rhs_complex_num)
{
    int re, img;
    re = m_real + rhs_complex_num.m_real;
    img = m_img + rhs_complex_num.m_img;

    return complexNum(re,img);
}

template <class T>
complexNum<T>& complexNum<T>::operator+=(complexNum<T>& rhs_complex_num)
{
    this->m_real += rhs_complex_num.m_real;
    this->m_img += rhs_complex_num.m_img;
    return *this;
}

template <class T>
complexNum<T> complexNum<T>::operator-(complexNum<T>& rhs_complex_num)
{
    int re, img;
    re = m_real - rhs_complex_num.m_real;
    img = m_img - rhs_complex_num.m_img;

    return complexNum(re,img);
}

template <class T>
complexNum<T>& complexNum<T>::operator-=(complexNum<T>& rhs_complex_num)
{
    this->m_real -= rhs_complex_num.m_real;
    this->m_img -= rhs_complex_num.m_img;
    return *this;
}

template <class T>
std::string complexNum<T>::toString()
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

