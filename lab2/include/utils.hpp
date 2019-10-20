#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "complexNumber.hpp"

/**
 * @brief read a file of complex numbers specified by filepath and returns a vector of complex numbers
 * 
 * @param file_path 
 * @return std::vector<complexNum> 
 */
std::vector<complexNum> readComplexNumberFromFile(std::string file_path);

/**
 * @brief writes the given complex number to specified file path 
 * 
 * @param sum 
 * @param file_path 
 */
void writeComplexNumberToFile(complexNum complex_num, std::string file_path);


#endif //closing header guard