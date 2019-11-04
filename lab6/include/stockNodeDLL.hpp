#ifndef STOCKNODEDLL_HPP
#define STOCKNODEDLL_HPP

#include "stockDLL.hpp"

class StockNodeDLL:public Stock{
    public:
    StockNodeDLL* m_ptr_nxt;
    StockNodeDLL* m_ptr_prev;

/**
 * @brief Construct a new Stock Node Doubly Linked List object
 * 
 */
    StockNodeDLL();

/**
 * @brief Destroy the Stock Node Doubly Linked List object
 * 
 */
    ~StockNodeDLL();

};

#endif