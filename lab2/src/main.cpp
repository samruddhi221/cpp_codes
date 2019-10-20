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
const std::string OUTPUT_FILE = "../ComplexObj.txt";

int main() 
{
    
    complexNum sum(0,0);

    std::vector<complexNum> complex_numbers = readComplexNumberFromFile(INPUT_FILE);

    for(int i = 0; i < complex_numbers.size() ; i++)
    {
        complex_numbers[i].printNum();
        sum += complex_numbers[i];
    }

    sum.printNum();

    writeComplexNumberToFile(sum, OUTPUT_FILE);
}