#include "Node.hpp"
#include <iostream>

//Constructor
Node::Node(int discSize)   //class::constructor
{
    //'this' is a Node*
    this->discSize = discSize;  
    this->nextNode = 0;                             
}

int Node::getdiscSize()
{
    return this->discSize;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}
void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

void Node::discDisplay()
{
    std::cout <<"  ";
            for(int i=0; i< this->getdiscSize(); i++)
                {
                    std::cout<<"*";
                }
            std::cout <<"\n";
}
