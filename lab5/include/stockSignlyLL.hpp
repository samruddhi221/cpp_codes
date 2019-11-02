#ifndef STOCKSINGLYLL_HPP
#define STOCKSINGLYLL_HPP

#include <iostream>
#include <string>
#include "stockNode.hpp"
class StockDBSinglyLL
{
private:
    StockNode* m_head;
    int m_length;
public:
    /**
     * @brief Construct a new Stock D B object
     * 
     */
    StockDBSinglyLL();

    /**
     * @brief Destroy the Stock D B object
     * 
     */
    ~StockDBSinglyLL();

    /**
     * @brief Insert an element to a linked list at a given position
     * 
     * @param element 
     * @param position : START, END or SPECIFIED
     */
    void insertNode(Stock stock, int position);

    /**
     * @brief append a node to an existing linkedlist at the end
     * 
     * @param stock 
     */
    void appendNode(Stock stock);

    /**
     * @brief Delete an element from a Linked List
     * 
     * @param position : START, END, SPECIFIED
     */
    void deleteNode(int position);

    /**
     * @brief display all the elements of a linked list
     * 
     */
    void display();
};

#endif