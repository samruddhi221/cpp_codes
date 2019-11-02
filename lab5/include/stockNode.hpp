#ifndef STOCKNODE_HPP
#define STOCKNODE_HPP

#include "stock.hpp"

class StockNode
{
public:
    Stock m_stock_obj;
    StockNode* m_ptr_next;

    /**
     * @brief Construct a new Stock Node object: Default constructor
     * 
     */
    StockNode();

    /**
     * @brief Destroy the Stock Node object
     * 
     */
    ~StockNode();
   
};

#endif