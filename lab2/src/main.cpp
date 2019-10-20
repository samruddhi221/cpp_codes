//
//  main.cpp
//  ASSIGNMENT2
//  author: Samruddhi Patil
//  Created by admin on 9/10/19.
//  Copyright © 2019 admin. All rights reserved.
//

/*
 LAB2 PROBLEM STATEMENT:
 Write a C++ program to perform following operations on complex numbers (a+ib)
 
 1. It should have a complex number class to store 1 complex number.
 
 2. Create an array of complex number objects to store multiple numbers.
 
 3. Read the complex numbers from file complex.txt. If that is too hard for you, you can read the numbers from console.
 
 4. Display all the complex numbers.
 
 5. Add all the complex numbers and display the result. Store the result in file ComplexObj.txt.
 */

#include <iostream>
#include <vector>
#include "complexNumber.hpp"
#include "utils.hpp"


const std::string INPUT_FILE = "../complex.txt";
const std::string INPUT_FILE_DOUBLE = "../complex_double.txt";

const std::string OUTPUT_FILE_SUM = "../ComplexObj.txt";
const std::string OUTPUT_FILE_DOUBLE_SUM = "../ComplexObjdouble.txt";

const std::string OUTPUT_FILE_SUBTRACTION = "../ComplexObjSub.txt";
const std::string OUTPUT_FILE_DOUBLE_SUBTRACTION = "../ComplexObjSubdouble.txt";

int main() 
{
    
    complexNum<int> sum(0,0);
    complexNum<double> sum_d(0.0,0.0);

    complexNum<int> diff(0,0);
    complexNum<double> diff_d(0.0,0.0);

    std::vector<complexNum<int>> complex_numbers = readComplexNumberFromFile<int>(INPUT_FILE);
    std::vector<complexNum<double>> complex_numbers_d = readComplexNumberFromFile<double>(INPUT_FILE_DOUBLE);

    // for(int i = 0; i < complex_numbers.size() ; i++)
    // {
    //     complex_numbers[i].printNum();
    //     sum += complex_numbers[i];
    //     diff -= complex_numbers[i];
    // }

    for(auto complex_num:complex_numbers)
    {
        complex_num.printNum();
        sum += complex_num;
        diff -= complex_num;
    }

    // for(int i = 0; i < complex_numbers_d.size() ; i++)
    // {
    //     complex_numbers_d[i].printNum();
    //     sum_d += complex_numbers_d[i];
    //     diff_d -= complex_numbers_d[i];
    // }

    for(auto complex_num_d:complex_numbers_d)
    {
        complex_num_d.printNum();
        sum_d += complex_num_d;
        diff_d -= complex_num_d;
    }

    sum.printNum();
    diff.printNum();

    sum_d.printNum();
    diff_d.printNum();

    writeComplexNumberToFile<int>(sum, OUTPUT_FILE_SUM);
    writeComplexNumberToFile<int>(diff, OUTPUT_FILE_SUBTRACTION);

    writeComplexNumberToFile<double>(sum_d, OUTPUT_FILE_DOUBLE_SUM);
    writeComplexNumberToFile<double>(diff_d, OUTPUT_FILE_DOUBLE_SUBTRACTION);
}