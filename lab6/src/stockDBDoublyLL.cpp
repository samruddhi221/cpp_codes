#include "stockDBDoublyLL.hpp"

StockDBDoublyLL::StockDBDoublyLL()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

StockDBDoublyLL::~StockDBDoublyLL()
{}

void StockDBDoublyLL::appendNodeDLL(StockNodeDLL* node)
{
    if(m_head == NULL)
    {
        m_head = node;
        node->m_ptr_nxt = NULL;
        node->m_ptr_prev = NULL;
        m_tail = node;
    }
    else
    {
        StockNodeDLL* temp_node = m_head;
        while(temp_node->m_ptr_nxt != NULL)
        {
            temp_node = temp_node->m_ptr_nxt;
        }
        temp_node->m_ptr_nxt = node;
        node->m_ptr_prev = temp_node;
        node->m_ptr_nxt = NULL;
        m_tail = node;             
    }
    m_size++;
}

void StockDBDoublyLL::insertNodeDLL(StockNodeDLL* node, int position)
{
    //std::cout << "inserting a stock" << std::endl;
    //insert at the start
    if (position == 1)      
    {
        //in case of empty linkedList
        if(m_head == NULL)
        {
            appendNodeDLL(node);
            //std::cout << "1st node inserted" << std::endl;
        }
        //insert before the current list
        else
        {
            m_head ->m_ptr_prev = node;
            node->m_ptr_nxt = m_head;
            node->m_ptr_prev = NULL;
            m_head = node;
        }
    }
    //insert in between two nodes
    else if(position < m_size)
    {
        StockNodeDLL* temp_node = m_head;
        for(int i = 1; i < position-1; i++)    
        {
            //traverse till the previous node of the given position
            temp_node = temp_node->m_ptr_nxt;
        }
        node->m_ptr_prev = temp_node;
        node->m_ptr_nxt = temp_node->m_ptr_nxt;
        temp_node->m_ptr_nxt = node;
        node->m_ptr_nxt->m_ptr_prev = node;
    }
    else
    {
        appendNodeDLL(node);
    }
    
    m_size++;
}

void StockDBDoublyLL::deleteNodeDLL(int position)
{
    //in case of empty linked list
    if(m_head == NULL)
    {
        std::cout << "empty linkedlist" << std::endl;                   //working
    }
    //deletion of a given node
    else
    {
        StockNodeDLL* temp_node = m_head;
        //delete first node when only one node in the LL
        if(position == 1 && m_size > 1)
        {
            temp_node = m_head->m_ptr_nxt;

            delete m_head;

            m_head = temp_node; //make new m_head        
            m_head->m_ptr_prev = NULL;
        }

        //delete other nodes
        else
        {

            StockNodeDLL* temp_prev = NULL;
            StockNodeDLL* temp_next = NULL;
            //traverse till the node to be deleted
            for(int i = 1; i < position; i++)
            {
                temp_node = temp_node->m_ptr_nxt; 
            }

            temp_prev = temp_node->m_ptr_prev; // 1 ->2.prev
            temp_next = temp_node->m_ptr_nxt; // 3 ->2.nxt

            temp_prev->m_ptr_nxt    = temp_next; 
            temp_next->m_ptr_prev   = temp_prev;

            delete temp_node;
        }   
    }
    m_size--;
}

void StockDBDoublyLL::display(StockDBDoublyLL::DIRECTION orientation)
{
    if(m_head == NULL)
    {
        std::cout << "linked list is empty" << std::endl;
    }
    else 
    {
        //if(orientation == "FORWARD")
        if(orientation == DIRECTION::FORWARD)
        {
            StockNodeDLL* temp_node = m_head;
            while(temp_node != NULL)
            {
                std::cout <<  temp_node->getStock() << std::endl;
                temp_node = temp_node->m_ptr_nxt;
            }
        }
        //else if(orientation == "REVERSE")
        else if(orientation == DIRECTION::REVERSE)
        {
            StockNodeDLL* temp_node = m_tail;
            while(temp_node != NULL)
            {
                std::cout <<  temp_node->getStock() << std::endl;
                temp_node = temp_node->m_ptr_prev;
            }
        }
        else
        {
            std::cout << "invalid input." << std::endl;
        } 
    }
}

StockNodeDLL* StockDBDoublyLL::findMiddle()
{

    StockNodeDLL * temp = m_head;
    StockNodeDLL *slow_ptr = temp;  
    StockNodeDLL *fast_ptr = temp;  
  
    if (temp==NULL)  
    {  
        return NULL;
    }
    else
    {
        while (fast_ptr != NULL && fast_ptr->m_ptr_nxt != NULL)  
        {  
            fast_ptr = fast_ptr->m_ptr_nxt->m_ptr_nxt;  
            slow_ptr = slow_ptr->m_ptr_nxt;  
        }
        return slow_ptr;  
    } 
}
