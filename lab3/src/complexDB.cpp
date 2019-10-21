#include "complexDB.hpp"
#include <iostream>
#include <fstream>

ComplexDB::ComplexDB():m_max_length(5),m_end_idx(0),m_length(0)
{
    //int *array = new int[length]();
    m_array = new complexNum<int>[m_max_length](); 
}

ComplexDB::~ComplexDB()
{
    delete[] m_array;
}

void ComplexDB::insert(complexNum<int> complex_number)
{
    // if the array has enough space, add complex number
    if (m_length < m_max_length)
    {
        m_array[m_end_idx] = complex_number;
        m_length++;
        m_end_idx++;
    }
    // create space and add number
    else 
    {
        //create a temp array of same size 
        complexNum<int> *temp_array = new complexNum<int>[m_max_length]();    
        //deep copy m_array to a temp array
        for(int i = 0; i < m_max_length; i++)
        {
            temp_array[i] = m_array[i]; 
        }

        delete[] m_array;

        m_max_length *= 2; // double the length of array
        m_array = new complexNum<int>[m_max_length](); 
        //deep copy temp_array to a m_array
        for(int i = 0; i < m_max_length/2; i++)
        {
            m_array[i] = temp_array[i]; 
        }
        m_array[m_end_idx] = complex_number;
        m_length++;
        m_end_idx++;
    }
    
}

void ComplexDB::del(complexNum<int> complex_number)
{
    bool is_present = false;
    int index = 0;
    //compare the input complex number with the elements in m_array
    for(int i = 0; i < m_length ; i++)
    {
        if(complex_number == m_array[i])
        {
            is_present = true;
            index = i;
            break;
        }
    }
    //if present -> overwrite move elements up
    if(is_present)
    {
        for(int i = index; i < m_length-1; i++)
        {
            m_array[i] = m_array[i+1];
        }   
    }
    //else -> invalid msg
    else    
    {
        std::cout << "complex number not found in the database" << std::endl;
    }

    m_length--;
}

std::string ComplexDB::toString()
{
    std::string output_str = "";
    for(int i = 0; i < m_length; i++)
    {
        output_str += m_array[i].toString() + "\n";
    }
    return output_str;

}

void ComplexDB::save(std::string file_name)
{
    std::ofstream fOut(file_name);
    fOut << this->toString();
}