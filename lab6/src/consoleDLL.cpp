#include "consoleDLL.hpp"

ConsoleDLL::ConsoleDLL() : m_is_running(true)
{
}

ConsoleDLL::~ConsoleDLL()
{
}

void ConsoleDLL::printMenu()
{
    std::cout << "select an option from the menu" << std::endl;
    std::cout << "1: Insert a stock" << std::endl;
    std::cout << "2: Delete a stock" << std::endl;
    std::cout << "3: Display stocks in the database in forward direction" << std::endl;
    std::cout << "4: Display stocks in the database in reverse direction" << std::endl;
    std::cout << "5: find middle stock" << std::endl;
    std::cout << "9: Exit" << std::endl;
}

ConsoleDLL::OPTIONS ConsoleDLL::selectOption()
{
    int option;
    std::cin.clear();
    std::cin >> option;
    return static_cast<OPTIONS>(option);
}

int ConsoleDLL::readPosition()
{
    int position;
    std::cout << "Specify position:" << std::endl;
    std::cin >> position;
    return position;
}

bool ConsoleDLL::readStock(StockNodeDLL *node, int& position)
{
    std::cout << "insert a stock\n" << std::endl; 
    std::string stock_name;
    int stock_price, stock_count;
    std::cin.clear();
    std::cout << "insert stock name:";
    std::cin >> stock_name ;
    std::cout << "insert stock price:";
    std::cin >> stock_price ;
    std::cout << "insert stock count:";
    std::cin >> stock_count;

    position = this->readPosition();

    node->setStock(stock_name, stock_price, stock_count);
    // std::cout << stock << std::endl;
    std::cout << " position " << position << std::endl;
    return true;
}

void ConsoleDLL::process_commands()
{
    while (m_is_running)
    {
        std::cin.clear();
        this->printMenu();
        auto option = this->selectOption();
        StockDBDoublyLL stockDB;
        // choose action acc to option
        if (option == OPTIONS::INSERT)
        {
            StockNodeDLL temp_node;
            int position;
            if(this->readStock(&temp_node, position))
            {
                stockDB.insertNodeDLL(&temp_node, position);
            }
        }

        else if(option == OPTIONS::DELETE)
        {
            int position = this->readPosition();
            stockDB.deleteNodeDLL(position);
            
        }

        else if (option == OPTIONS::DISPLAY_FORWARD)
        {
            stockDB.display(StockDBDoublyLL::DIRECTION::FORWARD);
        }

        else if (option == OPTIONS::DISPLAY_REVERSE)
        {
            stockDB.display(StockDBDoublyLL::DIRECTION::REVERSE);
        }

        else if (option == OPTIONS::FIND_MIDDLE)
        {
            StockNodeDLL* stock_node = findMiddle();
            if(stock_node==NULL)
            {
                std::cout << "DB is empty" << std::endl;
            }
            else
            {
                std::cout << stock_node->getStock() << std::endl;
            }
            
        }

        else if (option == OPTIONS::EXIT)
        {
            m_is_running = false;
        }

        else
        {
            std::cout << "Invalid option" << std::endl;
        }
    }
}

