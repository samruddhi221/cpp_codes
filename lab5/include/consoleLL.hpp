#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "stockNode.hpp"
#include "stockSignlyLL.hpp"

class Console
{
private: 
    bool m_is_running;
    StockDBSinglyLL* m_stock_db;

    enum class OPTIONS{
            INSERT=1,
            DELETE=2,
            DISPLAY_FORWARD=3,
            FIND_MIDDLE=4,
            EXIT=9
        };

public:
    /**
     * @brief Construct a new Console object for singly linked list
     * 
     * @param stock_db: pointer of singly linked list 
     */
    Console(StockDBSinglyLL * stock_db);

    /**
     * @brief Destroy the Console object
     * 
     */
    ~Console();

    /**
     * @brief print a menu to choose operation to be performed 
     * on stock database
     * 
     */
    void printMenu();

    /**
     * @brief select an option from the menu of operations 
     * 
     * @return Console::OPTIONS 
     */
    Console::OPTIONS selectOption();

    /**
     * @brief read a stock from the cmd/terminal
     * 
     * @param stock
     * @return true 
     * @return false 
     */
    bool readStock(Stock& stock, int& position);

    int readPosition();

    /**
     * @brief perform operations on stock database
     * 
     */
    void process_commands();

    /**
     * @brief 
     * 
     * @param input_string 
     */
    void display(std::string input_string);
};

#endif