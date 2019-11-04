#include "stockDLL.hpp"

Stock::Stock()
{
    m_stock_name = " ";
    m_stock_price = 0;
    m_stock_count = 0;
}

Stock::Stock(std::string stock_name, int price, int count)
{
    m_stock_name = stock_name;
    m_stock_price = price;
    m_stock_count = count;
}

Stock::~Stock()
{}

void Stock::setStock(std::string stock_name, int price , int count)
{
    m_stock_name = stock_name;
    m_stock_price = price;
    m_stock_count = count;
}

Stock Stock::getStock()
{

    // Stock s = stock.getStock(); 
    return *this; // r_value reference
    //return Stock(m_stock_name,m_stock_price,m_stock_count); // l_value
}

std::ostream& operator << (std::ostream& os, const Stock& obj)
{
    os << "(";
    os << "stock name: " << obj.m_stock_name << ", ";
    os << "stock price: " << obj.m_stock_price << ", ";
    os << "stock count: " << obj.m_stock_count << " ";
    os << ")";
} 

bool Stock::operator== (const Stock& stock_obj)
{
    if(stock_obj.m_stock_name == m_stock_name &&
       stock_obj.m_stock_price == m_stock_price &&
       stock_obj.m_stock_count == m_stock_count)
    {
        return true;
    }
    else 
    {
        return false;
    }
}