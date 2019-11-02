#include "console.hpp"

Console::Console(StockDBSinglyLL * stock_db) : m_is_running(true)
{
    m_stock_db = stock_db;
}

Console::~Console()
{
}

void Console::printMenu()
{
    std::cout << "select an option from the menu" << std::endl;
    std::cout << "1: Insert a stock" << std::endl;
    std::cout << "2: Delete a stock" << std::endl;
    std::cout << "3: Display stocks in the database" << std::endl;
    std::cout << "4: find middle stock" << std::endl;
    std::cout << "9: Exit" << std::endl;
}

Console::OPTIONS Console::selectOption()
{
    int option;
    std::cin.clear();
    std::cin >> option;
    return static_cast<OPTIONS>(option);
}

int Console::readPosition()
{
    int position;
    this->display("Specify position:");
    std::cin >> position;
    return position;
}

bool Console::readStock(Stock& stock, int& position)
{
    this->display("insert a stock\n"); 
    std::string stock_name;
    int stock_price, stock_count;
    
    std::cin.clear();
    this->display("insert stock name:");
    std::cin >> stock_name ;
    this->display("insert stock price:");
    std::cin >> stock_price ;
    this->display("insert stock count:");
    std::cin >> stock_count;

    position = this->readPosition();

    stock = Stock(stock_name, stock_price, stock_count);
    std::cout << stock << std::endl;
    std::cout << " position " << position << std::endl;
    return true;
}

void Console::process_commands()
{
    while (m_is_running)
    {
        std::cin.clear();
        this->printMenu();
        auto option = this->selectOption();
        // choose action acc to option
        if (option == OPTIONS::INSERT)
        {
            Stock temp_stock;
            int position;
            if(this->readStock(temp_stock, position))
            {
                m_stock_db->insertNode(temp_stock, position);
            }
        }

        else if(option == OPTIONS::DELETE)
        {
            int position = this->readPosition();
            m_stock_db->deleteNode(position);
            
        }

        else if (option == OPTIONS::DISPLAY)
        {
            m_stock_db->display();
        }

        else if (option == OPTIONS::FIND_MIDDLE)
        {
            StockNode* stock_node = m_stock_db->findMiddle();
            if(stock_node==NULL)
            {
                std::cout << "DB is empty" << std::endl;
            }
            else
            {
                std::cout << stock_node->m_stock_obj << std::endl;
            }
            
        }

        else if (option == OPTIONS::EXIT)
        {
            m_is_running = false;
        }

        else
        {
            this->display("Invalid option");
        }
    }
}

void Console::display(std::string input_string)
{
    std::cout << input_string;
}