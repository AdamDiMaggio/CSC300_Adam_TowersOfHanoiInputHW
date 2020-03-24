#include "Node.hpp"

class Stack 
{
    private:
        Node* top;
        int count;
        int stackId;


    public:
        Stack(int stackId);
        void push(int discSize); //add node to top
        int peek(); //return top's value
        int pop();  //return value of top and remove it
        int getCount();

        int selectDisc();
        void moveDisk(int disc);

        void display();
};