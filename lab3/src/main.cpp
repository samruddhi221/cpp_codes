/*
//
//  main.cpp
//  ASSIGNMENT3
//  author : Samruddhi Patil
//  student ID: 014550094
//  Created by admin on 10/20/19.
//  Copyright © 2019 admin. All rights reserved.
//

Problem statement:
Create a complex number database to store multiple complex numbers. Your program should have two 
classes ComplexDB and Complex.
1. The ComplexDB should create a dynamic array to store the objects of class Complex.
2. The program should display a menu on the console to insert, delete, display and store complex numbers.
3. Insert and delete should ask the user for a complex number which is to be inserted or deleted from the list.
4. Display should list all the complex numbers on the console.
5.  Save should save all the complex numbers in file lab3complex.txt
6. Implement operator overloading where ever necessary.
(Optional : You can load some initial complex numbers from a file)
*/

#include <iostream>
#include "complexNumber.hpp"
#include "complexDB.hpp"

const std::string OUTPUT_FILE = "../lab3complex.txt";

int main()
{
    complexNum<int> c1(2,3);
    complexNum<int> c2(24,23);
    complexNum<int> c3(12,-3);
    complexNum<int> c4(11,-3);
    complexNum<int> c5(10,-3);
    complexNum<int> c6(9,-3);

    ComplexDB complex_array;
    complex_array.insert(c1);
    complex_array.insert(c2);
    complex_array.insert(c3);

    std::cout << complex_array.toString() << std::endl;
    
    complex_array.insert(c4);
    complex_array.insert(c5);
    complex_array.insert(c6);

    std::cout << complex_array.toString() << std::endl;
    
    complex_array.del(c2);

    std::cout << complex_array.toString() << std::endl;

    complex_array.save(OUTPUT_FILE);
    return 0;
}