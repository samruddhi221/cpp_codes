#ifndef STOCKDBDOUBLYLL_HPP
#define STOCKDBDOUBLYLL_HPP

#include "stockNodeDLL.hpp"

#define DEBUG_LINE std::cout << __LINE__ << std::endl;

class StockDBDoublyLL:public StockNodeDLL
{
public:
/**
 * @brief members 
 * 
 */
    StockNodeDLL* m_head;
    StockNodeDLL* m_tail;
    int m_size;

    enum class DIRECTION
    {
        FORWARD,
        REVERSE
    };

/**
 * @brief Construct a new Stock D B Doubly L L object
 * 
 */
    StockDBDoublyLL();

/**
 * @brief Construct a new StockDB Doubly LL object
 * 
 * @param node 
 */
    StockDBDoublyLL(StockNodeDLL* node);

/**
 * @brief Destroy the Stock DB Doubly LL object
 * 
 */
    ~StockDBDoublyLL();

/**
 * @brief append a node to a linked list
 * 
 * @param node 
 */
    void appendNodeDLL(StockNodeDLL* node);

/**
 * @brief insert a node in a doubly linked list
 * 
 */
    void insertNodeDLL(StockNodeDLL* node, int position);

/**
 * @brief delete a node from a doubly linkedlist
 * 
 */
    void deleteNodeDLL(int position);

/**
 * @brief display linked list in forward or reverse manner
 * 
 * @param orientation 
 */
    void display(StockDBDoublyLL::DIRECTION orientation);

/**
 * @brief find the middle node of a linkedlist
 * 
 * @return StockNodeDLL* 
 */
    StockNodeDLL* findMiddle();

};

#endif