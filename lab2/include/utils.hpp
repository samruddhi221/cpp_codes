
#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "complexNumber.hpp"

/**
 * @brief 
 * 
 * @tparam T 
 * @param file_path 
 * @return std::vector<complexNum<T>> 
 */
template <class T>
std::vector<complexNum<T>> readComplexNumberFromFile(std::string file_path)
{
    std::ifstream fIn(file_path);
    std::string line;
    std::vector<complexNum<T>> complex_numbers;
    while (std::getline(fIn, line))
    {
        
        std::istringstream iss(line);
        T a, b;
        if (!(iss >> a >> b))
        { 
            continue;
        }
        std::cout << a << " " << b << std::endl;
        complexNum<T> complex_num(a,b);
        complex_numbers.push_back(complex_num);
    } 

    return complex_numbers;
}

/**
 * @brief 
 * 
 * @tparam T 
 * @param complex_num 
 * @param file_path 
 */
template <class T>
void writeComplexNumberToFile(complexNum<T> complex_num, std::string file_path)
{
    std::ofstream fOut(file_path);
    fOut << complex_num.toString();
}

#endif 