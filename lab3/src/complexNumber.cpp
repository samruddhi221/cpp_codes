#include "complexNumber.hpp"
#include <iostream>
#include <math.h>

template <class T>
complexNum<T>::complexNum():m_real(static_cast<T>(0)),m_img(static_cast<T>(0)) // using copy constructor to initalize variables
{
}


template <class T>
complexNum<T>::complexNum(T re, T i):m_real(re),m_img(i)
{
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
int complexNum<T>::complex_num_absolute_val()
{
    int absolute_val = sqrt(m_real*m_real + m_img*m_img);
    return absolute_val;
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
bool complexNum<T>::operator==(complexNum<T>& rhs_complex_num)
{
    return ((this->m_real == rhs_complex_num.m_real) && (this->m_img == rhs_complex_num.m_img));
}

template <class T>
bool complexNum<T>::operator>(complexNum<T>& rhs_complex_num)
{
    return (this->complex_num_absolute_val() > rhs_complex_num.complex_num_absolute_val());
}

template <class T>
bool complexNum<T>::operator<(complexNum<T>& rhs_complex_num)
{
    return (this->complex_num_absolute_val() < rhs_complex_num.complex_num_absolute_val());
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

