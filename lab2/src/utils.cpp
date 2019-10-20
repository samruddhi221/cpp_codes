#include "utils.hpp"

std::vector<complexNum> readComplexNumberFromFile(std::string file_path)
{
    std::ifstream fIn(file_path);
    std::string line;
    std::vector<complexNum> complex_numbers;
    while (std::getline(fIn, line))
    {
        
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b))
        { 
            continue;
        }
        std::cout << a << " " << b << std::endl;
        complexNum complex_num(a,b);
        complex_numbers.push_back(complex_num);
    } 

    return complex_numbers;
}

void writeComplexNumberToFile(complexNum complex_num, std::string file_path)
{
    std::ofstream fOut(file_path);
    fOut << complex_num.toString();
}