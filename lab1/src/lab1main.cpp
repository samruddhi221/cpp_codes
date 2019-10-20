//
//  main.cpp
//  ASSIGNMENT1
//  author : Samruddhi Patil
//  student ID: 014550094
//  Created by admin on 9/9/19.
//  Copyright © 2019 admin. All rights reserved.
//

/*
 Create a clockType class with hr, min, sec as private members.
 You should write the program divided into three parts -  clock.h clock.cpp and lab1main.cpp
 lab1main.cpp will have the main function and should support the following statements:
 
 clockType c1(15, 45, 30), c2(3, 20);  // hour, min, sec
 cout << c1;   // add whatever to beautify it
 cout << c2;
 cout << c1+c2;
 c2 = c1+c1;
 cout << c2;
 */

#include <iostream>
#include "clock.h"

int main(){
    clockType c1(15, 45, 30), c2(3, 20);  // hour, min, sec
    std::cout << c1 << std::endl;   // add whatever to beautify it
    std::cout << c2 << std::endl;
    std::cout << c1+c2 << std::endl;
    c2 = c1 + c1;  
    std::cout << c2 << std::endl;
    return 0;
}