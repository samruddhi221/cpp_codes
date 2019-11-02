#ifndef STOCK_HPP
#define STOCK_HPP

#include <iostream>
#include <string>
class Stock
{
private:
/**
 * @brief declaration of member variables
 * 
 */
    std::string m_stock_name = " ";
    int m_stock_price = 0;
    int m_stock_count = 0;

public:
/**
 * @brief Default constructor
 * 
 */
    Stock();

/**
 * @brief Construct a new Stock object
 * 
 * @param stock_name 
 * @param price 
 * @param count 
 */
    Stock(std::string stock_name, int price , int count);

/**
 * @brief Destroy the Stock object
 * 
 */
    ~Stock();

/**
 * @brief cout << operator overloading function declaration
 * 
 * @param os: ostream object
 * @param obj: stock object 
 * @return std::ostream& 
 */
    friend std::ostream& operator << (std::ostream& os, const Stock& obj);

/**
 * @brief overload == operator
 * 
 * @param stock_obj 
 * @return true 
 * @return false 
 */
    bool operator==(const Stock& stock_obj);
};

#endif