#ifndef CONSOLEDLL_HPP
#define CONSOLEDLL_HPP

#include "stockDBDoublyLL.hpp"

class ConsoleDLL:public StockDBDoublyLL
{
    private:
    bool m_is_running;

    enum class OPTIONS{
            INSERT=1,
            DELETE=2,
            DISPLAY_FORWARD=3,
            DISPLAY_REVERSE=4,
            FIND_MIDDLE=5,
            EXIT=9
        };

    public:
    /**
     * @brief Construct a new Console DLL object
     * 
     * @param stockDB 
     */
    ConsoleDLL();

    /**
     * @brief Destroy the Console DLL object
     * 
     */
    ~ConsoleDLL();

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
    ConsoleDLL::OPTIONS selectOption();

    /**
     * @brief read a stock from the cmd/terminal
     * 
     * @param stock
     * @return true 
     * @return false 
     */
    bool readStock(StockNodeDLL * node, int& position);

    int readPosition();

    /**
     * @brief perform operations on stock database
     * 
     */
    void process_commands();
    

};

#endif

