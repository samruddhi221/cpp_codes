#include "stockSignlyLL.hpp"

StockDBSinglyLL::StockDBSinglyLL():m_head(NULL), m_length(1)
{
}

StockDBSinglyLL::~StockDBSinglyLL()
{

}

void StockDBSinglyLL::insertNode(Stock stock, int position)
{   
    StockNode* new_node = new StockNode();
    new_node->m_stock_obj = stock;
    if(position == 1)                   //insert at the start of the linked list
    {
        if(m_head == NULL)                 //check if the Linked list is empty
        {

            new_node->m_ptr_next = NULL;
            m_head = new_node;            //make the current node a head
        }
        else
        {
            new_node->m_ptr_next = m_head;
            m_head = new_node;
        }
        m_length++;
    }
    else                                //insert at the given node
    {
        if(position > m_length)
        {
            std::cout << "position out of bounds of the database length" << std::endl;
            return;
        }
        StockNode* temp = m_head;
        for(int i = 1; i < position-1; i++) //traverse to the given position-1
        {
            temp = temp->m_ptr_next;       
        }
        new_node->m_ptr_next = temp->m_ptr_next; //assign next nodes pointer to the given position's next pointer
        temp->m_ptr_next = new_node;
        m_length++;             //update the pointer of previous node
    }
}


void StockDBSinglyLL::appendNode(Stock stock)
{
    StockNode* new_node = new StockNode();
    new_node->m_stock_obj = stock;

    if(m_head == NULL)                 //check if the Linked list is empty
    {
        new_node->m_ptr_next = NULL;
        m_head = new_node;            //make the current node a head
    }
    else
    {
        StockNode* temp = m_head;
        while(temp->m_ptr_next != NULL)
        {
            temp = temp->m_ptr_next;
        }
        temp->m_ptr_next = new_node;
    }
}

void StockDBSinglyLL::deleteNode(int position)
{
    if(m_head == NULL)
    {
        std::cout << "Linked List is already empty." << std::endl;
    }
    else
    {
        if(position == 1)
        {
            //deleting first node
            StockNode* temp = m_head->m_ptr_next;
            delete m_head;
            m_head = temp;                        //make second node a head
        }
        else
        {
            StockNode* temp = m_head;
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
        m_length--;
    }
}

void StockDBSinglyLL::display()
{
    if(m_head == NULL)
    {
        std::cout << "empty linkedlist" << std::endl;
    }
    else
    {
        std::cout << "---------------------------------------------------------------------------------------------------------------------------" << std::endl;
        StockNode* temp = m_head;
        int i = 1;
        while(temp != NULL)
        {
            // std::cout << i << "th node is:" <<std::endl;
            std::cout  << temp->m_stock_obj;
            i++;
            if(i%4==0)
            {
                std::cout<<std::endl;
            }

            temp = temp->m_ptr_next;
            if(temp!=NULL)
            {
                std::cout << "->";
            }
        }
        std::cout << std::endl;
        std::cout << "---------------------------------------------------------------------------------------------------------------------------" << std::endl;
        
    }
    
    
}
    
StockNode* StockDBSinglyLL::findMiddle()
{

    StockNode * temp = m_head;
    StockNode *slow_ptr = temp;  
    StockNode *fast_ptr = temp;  
  
    if (temp==NULL)  
    {  
        return NULL;
    }
    else
    {
        while (fast_ptr != NULL && fast_ptr->m_ptr_next != NULL)  
        {  
            fast_ptr = fast_ptr->m_ptr_next->m_ptr_next;  
            slow_ptr = slow_ptr->m_ptr_next;  
        }
        return slow_ptr;  
    } 
}

