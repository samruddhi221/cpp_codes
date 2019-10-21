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
#include "console.hpp"

const std::string OUTPUT_FILE = "../lab3complex.txt";

int main()
{
    
    ComplexDB complex_db;
    Console console(&complex_db);
    console.complex_db_oprations();

    return 0;
}
