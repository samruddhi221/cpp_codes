#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "complexDB.hpp"
#include "complexNumber.hpp"

class Console
{
private: 
    bool is_running;
    ComplexDB* m_complex_db;

    enum class OPTIONS{
            INSERT=1,
            DELETE=2,
            DISPLAY=3,
            SAVE=4,
            EXIT=9
        };

public:
    /**
     * @brief Construct a new Console object
     * 
     * @param complex_DB 
     */
    Console(ComplexDB * complex_DB);

    /**
     * @brief Destroy the Console object
     * 
     */
    ~Console();

    /**
     * @brief print a menu to choose operation to be performed 
     * on complex number database
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
     * @brief read a complex number from the cmd/terminal
     * 
     * @param complex_number 
     * @return true 
     * @return false 
     */
    bool readComplexNumber(complexNum<int>& complex_number);

    /**
     * @brief perform operations on complex database
     * 
     */
    void complex_db_oprations();

    /**
     * @brief 
     * 
     * @param input_string 
     */
    void display(std::string input_string);
};

#endif