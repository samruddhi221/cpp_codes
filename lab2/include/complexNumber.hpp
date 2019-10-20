#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP

#include <string>

/**
 * @brief A Complex number container with complex number arithematic
 * 
 */
class complexNum
{
private:
    int m_real = 0, m_img = 0;  //members of the class

public:
    /**
     * @brief Construct a new complex Num object
     * 
     * @param real 
     * @param img 
     */
    complexNum(int real, int img); 
    
    /**
     * @brief Destroy the complex Num object
     * 
     */
    ~complexNum();

    /**
     * @brief print complex number on stdout
     * 
     */
    void printNum();

    /**
     * @brief overloaded operator + 
     * 
     * @param rhs_complex_num 
     * @return complexNum 
     */
    complexNum operator+(complexNum& rhs_complex_num);

    /**
     * @brief overloaded operator +=
     * 
     * @param rhs_complex_num 
     * @return complexNum& 
     */
    complexNum& operator+=(complexNum& rhs_complex_num);

    /**
     * @brief overloaded operator - 
     * 
     * @param rhs_complex_num 
     * @return complexNum 
     */
    complexNum operator-(complexNum& rhs_complex_num);

    /**
     * @brief overloaded operator -=
     * 
     * @param rhs_complex_num 
     * @return complexNum& 
     */
    complexNum& operator-=(complexNum& rhs_complex_num);

    /**
     * @brief returns complex number as string
     * 
     * @return std::string 
     */
    std::string toString();
};
#endif