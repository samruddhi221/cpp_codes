/**
 * @file main.cpp
 * @author Samruddhi Patil
 * @brief Implementatioin of single linked list
 * @version 0.1
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 * problem statement:
 * lab5: Create a Singly Linked List of the stocks owned by a person.
1. Create a Stock class
2. The class should store a stock symbol (like AAPL, GOOG), the price of each stock and the number of stocks owned.
3. Use has-a implementation for the node. 
(https://sites.google.com/site/franksjsu180ds/FranksNote/notes-on-link-list/create-a-linked-node (Links to an external site.))
4. Load some initial stocks from a file.
5. The program should allow a user to insert, delete, display_all stocks
6. Write a function to find the middle of the linked list. (Try to do it in just one pass).

 */

#include <iostream>
#include <string>
#include "stock.hpp"
#include "stockNode.hpp"
#include "stockSignlyLL.hpp"
#include "console.hpp"

int main()
{
    // Stock A("APPL", 100, 10);
    // Stock B("fb", 90,12);
    // Stock C("google", 80,15);

    // // StockNode node;

    // StockDBSinglyLL stockDB;
    // stockDB.display();
    // stockDB.insertNode(A,1);
    // stockDB.display();
    // stockDB.appendNode(B);
    // stockDB.display();
    // stockDB.insertNode(C,2);
    // stockDB.display();
    // stockDB.deleteNode(2);
    // stockDB.display();

    StockDBSinglyLL stockDB;
    Console console(&stockDB);
    console.process_commands();

    return 0;
}