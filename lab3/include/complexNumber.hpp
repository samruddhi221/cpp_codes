#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP

#include <string>

/**
 * @brief A Complex number container with complex number arithematic
 * 
 */
template <class T>
class complexNum
{
private:
    T m_real = 0, m_img = 0;  //members of the class

public:
    /**
     * @brief Construct a new complex Num object
     * 
     * @param real 
     * @param img 
     */
    complexNum(); 

    /**
     * @brief Construct a new complex Num object
     * 
     * @param real 
     * @param img 
     */
    complexNum(T real, T img); 
    
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

    int complex_num_absolute_val();

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
     * @brief overloaded operator ==
     * 
     * @param rhs_complex_num 
     * @return true 
     * @return false 
     */
    bool operator==(complexNum& rhs_complex_num);

    /**
     * @brief overloaded operator >
     * 
     * @param rhs_complex_num 
     * @return true 
     * @return false 
     */
    bool operator>(complexNum<T>& rhs_complex_num);

    /** @brief overloaded operator <
     * 
     * @param rhs_complex_num 
     * @return true 
     * @return false 
     */
    bool operator<(complexNum<T>& rhs_complex_num);

    /**
     * @brief returns complex number as string
     * 
     * @return std::string 
     */
    std::string toString();

};

template class complexNum<int>; // forward declaring integer complex number 
template class complexNum<float>; // forward declaring float complex number 
template class complexNum<double>; // forward declaring double complex number 

#endif