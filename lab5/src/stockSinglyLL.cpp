#include "stockSignlyLL.hpp"

StockDBSinglyLL::StockDBSinglyLL()
{
    head = NULL;
}

StockDBSinglyLL::~StockDBSinglyLL()
{}

void StockDBSinglyLL::insertNode(Stock stock, int position)
{   
    StockNode* new_node = new StockNode();
    new_node->m_stock_obj = stock;
    if(position == 1)                   //insert at the start of the linked list
    {
        if(head == NULL)                 //check if the Linked list is empty
        {

            new_node->m_ptr_next = NULL;
            head = new_node;            //make the current node a head
        }
        else
        {
            new_node->m_ptr_next = head;
            head = new_node;
        }
    }
    else                                //insert at the given node
    {
        StockNode* temp = head;
        for(int i = 1; i < position-1; i++) //traverse to the given position-1
        {
            temp = temp->m_ptr_next;       
        }
        new_node->m_ptr_next = temp->m_ptr_next; //assign next nodes pointer to the given position's next pointer
        temp->m_ptr_next = new_node;             //update the pointer of previous node
    }
}


void StockDBSinglyLL::appendNode(Stock stock)
{
    StockNode* new_node = new StockNode();
    new_node->m_stock_obj = stock;

    if(head == NULL)                 //check if the Linked list is empty
    {
        new_node->m_ptr_next = NULL;
        head = new_node;            //make the current node a head
    }
    else
    {
        StockNode* temp = head;
        while(temp->m_ptr_next != NULL)
        {
            temp = temp->m_ptr_next;
        }
        temp->m_ptr_next = new_node;
    }
}

void StockDBSinglyLL::deleteNode(int position)
{
    if(head == NULL)
    {
        std::cout << "Linked List is already empty." << std::endl;
    }
    else
    {
        if(position == 1)
        {
            //deleting first node
            StockNode* temp = head->m_ptr_next;
            delete head;
            head = temp;                        //make second node a head
        }
        else
        {
            StockNode* temp = head;
            StockNode* prev_ptr = NULL;
            StockNode* current_ptr = NULL;
            for(int i = 1; i < position-1; i++)
            {
                temp = temp->m_ptr_next;
            }
            current_ptr = temp->m_ptr_next;
            prev_ptr = temp;

            prev_ptr->m_ptr_next = current_ptr->m_ptr_next;
            delete current_ptr;           

        }
    }
}

void StockDBSinglyLL::display()
{
    if(head == NULL)
    {
        std::cout << "empty linkedlist" << std::endl;
    }
    else
    {
        StockNode* temp = head;
        int i = 1;
        while(temp != NULL)
        {
            std::cout << i << "th node is:" <<std::endl;
            std::cout << temp->m_stock_obj << std::endl;
            i++;
            temp = temp->m_ptr_next;
        }
        
    }
    
    
}
    
StockNode* StockDBSinglyLL::findMiddle()
{
    StockNode* slow = head;
    StockNode* fast = head;
    int i = 1, j = 1;
    while(fast->m_ptr_next != NULL)
    {
        slow = slow->m_ptr_next;
        fast = slow->m_ptr_next;
    }
    return slow;
}
