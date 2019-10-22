#include "console.hpp"

Console::Console(ComplexDB* complex_DB) : is_running(true)
{
    m_complex_db = complex_DB;
}

Console::~Console()
{
}

void Console::printMenu()
{
    std::cout << "select an option from the menu" << std::endl;
    std::cout << "1: Insert a complex number" << std::endl;
    std::cout << "2: Delete a complex Number" << std::endl;
    std::cout << "3: Display complex number database" << std::endl;
    std::cout << "4: Save database to a file" << std::endl;
    std::cout << "5: sort the database using bubble sort" << std::endl;
    std::cout << "6: sort the database using insertion sort" << std::endl;
    std::cout << "7: sort the database using selection sort" << std::endl;
    std::cout << "9: Exit" << std::endl;
}

Console::OPTIONS Console::selectOption()
{
    int option;
    std::cin.clear();
    std::cin >> option;
    return static_cast<OPTIONS>(option);
}

bool Console::readComplexNumber(complexNum<int>& complex_number)
{
    this->display("insert a complex number"); 
    int a, b;
    
    std::cin.clear();
    this->display("insert real part");
    std::cin >> a ;
    this->display("insert imaginary part");
    std::cin >> b ;
    complex_number = complexNum<int>(a,b);
    //std::cout << a << " " << b << std::endl;
    this->display(complex_number.toString());
    return true;
}

void Console::complex_db_oprations()
{
    while (is_running)
    {
        std::cin.clear();
        this->printMenu();
        auto option = this->selectOption();
        //std::cout << "[option] " << static_cast<int>(option) << std::endl;
        // choose action acc to option
        if (option == OPTIONS::INSERT)
        {
            complexNum<int> temp_complex_number;
            if(this->readComplexNumber(temp_complex_number))
            {
                m_complex_db->insert(temp_complex_number);
            }
        }

        else if(option == OPTIONS::DELETE)
        {
            complexNum<int> temp_complex_number;
            if(this->readComplexNumber(temp_complex_number))
            {
                m_complex_db->del(temp_complex_number);
            }
        }

        else if (option == OPTIONS::DISPLAY)
        {
            this->display(m_complex_db->toString());
        }

        else if (option == OPTIONS::SAVE)
        {
            m_complex_db->save("../lab3complex.txt");
        }

        else if (option == OPTIONS::SORT_DB_BUBBLE_SORT)
        {
            m_complex_db->bubbleSort();
        }

        else if (option == OPTIONS::SORT_DB_INSERTION_SORT)
        {

        }
        else if (option == OPTIONS::SORT_DB_SELECTION_SORT)
        {

        }

        else if (option == OPTIONS::EXIT)
        {
            is_running = false;
        }
        else
        {
            this->display("Invalid option");
        }
    }
}

void Console::display(std::string input_string)
{
    std::cout << input_string << std::endl;
}