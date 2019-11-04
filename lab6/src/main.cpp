#include <iostream>
#include "stockDLL.hpp"
#include "stockNodeDLL.hpp"
#include "stockDBDoublyLL.hpp"
#include "consoleDLL.hpp"

int main()
{
    using direction = StockDBDoublyLL::DIRECTION;
    StockDBDoublyLL stockDB;

    StockNodeDLL * node0 = new StockNodeDLL();
    node0->setStock("Apple", 10, 10);
    stockDB.insertNodeDLL(node0, 1);
    
    StockNodeDLL * node1 = new StockNodeDLL();
    node1->setStock("fb", 20,18);
    stockDB.appendNodeDLL(node1);
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    stockDB.display(direction::FORWARD);
    
    StockNodeDLL * node2 = new StockNodeDLL();
    node2->setStock("b", 20,18);
    stockDB.insertNodeDLL(node2,1);
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    stockDB.display(direction::FORWARD);
    
    StockNodeDLL * node3 = new StockNodeDLL();
    node3->setStock("google", 2,8);
    stockDB.insertNodeDLL(node3,4);
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    stockDB.display(direction::FORWARD);
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    stockDB.display(direction::REVERSE);
    
    stockDB.deleteNodeDLL(2);
    stockDB.display(direction::FORWARD);

    if(node0!= NULL){delete node0;}
    if(node1!= NULL){delete node1;}
    if(node2!= NULL){delete node2;}
    if(node3!= NULL){delete node3;}



    // ConsoleDLL console;
    // console.process_commands();
    
    return 0;
}