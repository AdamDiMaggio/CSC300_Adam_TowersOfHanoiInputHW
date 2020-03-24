#include "Stack.hpp"
#include <iostream>

Stack::Stack(int stackId)
{
    this->top = 0;
    this->stackId = stackId;
}

void Stack::push(int discSize)
{
    Node* n = new Node(discSize);    
    
    if(!this->top)
    {
        this->top = n; 
    }
    else
    {
        n->setNextNode(this->top); 
        this->top = n; 
    }
    this->count++;
}

int Stack::peek()
{
    return this->top->getdiscSize();     
}

int Stack::pop()
{
    Node* nodeToReturn = this->top;    //locate the node at the front of the list
    this->top = this->top->getNextNode(); //set top to the front's nextNode
    int val = nodeToReturn->getdiscSize(); //save the discSize of the first node
    nodeToReturn->setNextNode(0);
    delete nodeToReturn;    //free up the memory space we were using
    this->count--;
    return val; //output the discSize value we saved
}

int Stack::getCount()
{
    return this->count;
}

int Stack::selectDisc()
{
        int disc = this->pop();
        //std::cout<< "Disc has been selected.\n";
        return disc;  
}

void Stack::moveDisk(int disc)
{
    this->push(disc);
}

void Stack::display()
{
    std::cout<< "   |   " << "\n";
    std::cout<< "   |   " << "\n";


    if(this->top)
    {
        Node* currNode = this->top;
        for(int i=0; i< this->getCount(); i++)
        {
            currNode->discDisplay();
            currNode = currNode->getNextNode();
        }
        std::cout <<"========" << "\n" << "\n";
    }
    else
    {
        std::cout<< "   |   " << "\n";
        std::cout<< "   |   " << "\n";
        std::cout<< "   |   " << "\n";
        std::cout<< "========" << "\n" << "\n";

    }
    
}