#include "Stack.hpp"
#include <iostream>

int main()
{
    Stack* t1 = new Stack(1);
    Stack* t2 = new Stack(2);
    Stack* t3 = new Stack(3);

    t1->push(5);
    t1->push(4);
    t1->push(3);

    std::cout<<"Tower 1"<<"\n";
    t1->display();
    std::cout<<"Tower 2"<<"\n";
    t2->display();
    std::cout<<"Tower 3"<<"\n";
    t3->display();
    std::cout<<"/////////////////////////////////////"<<"\n";

    int numMoves = 0;
    while(t3->getCount() < 3)
    {
        std::cout<< "Which tower do you want to choose from?[1/2/3]: ";
        int towerSelect;
        std::cin>> towerSelect;
        //check to see if there are any discs on the selected tower
        int discCount;
        if(towerSelect == 1)
        {
            discCount = t1->getCount();
            if(discCount == 0)
            {
                while(discCount == 0)
                {
                    std::cout<<"There are no discs on that tower. Please Choose a different tower.[2/3]: ";
                    std::cin>> towerSelect;
                    if(towerSelect == 1)
                    {
                        discCount = t1->getCount();
                    }
                    else if (towerSelect == 2)
                    {
                        discCount = t2->getCount();
                    }
                    else
                    {
                        discCount = t3->getCount();
                    }
                }               
            }
        }
        else if(towerSelect == 2)
        {
            discCount = t2->getCount();
            if(discCount == 0)
            {
                while(discCount == 0)
                {
                    std::cout<<"There are no discs on that tower. Please Choose a different tower.[1/3]: ";
                    std::cin>> towerSelect;
                    if(towerSelect == 1)
                    {
                        discCount = t1->getCount();
                    }
                    else if (towerSelect == 2)
                    {
                        discCount = t2->getCount();
                    }
                    else
                    {
                        discCount = t3->getCount();
                    }
                }
            } 
        }
        else
        {
            discCount = t3->getCount();
            if(discCount == 0)
            {
                while(discCount == 0)
                {
                    std::cout<<"There are no discs on that tower. Please Choose a different tower.[1/2]: ";
                    std::cin>> towerSelect;
                    if(towerSelect == 1)
                    {
                        discCount = t1->getCount();
                    }
                    else if (towerSelect == 2)
                    {
                        discCount = t2->getCount();
                    }
                    else
                    {
                        discCount = t3->getCount();
                    }
                }
            }         
        }
        
        std::cout<< "\n";
        std::cout<< "Where do you want to put it?[1/2/3]: ";
        int towerDrop;
        std::cin>> towerDrop;
        std::cout<< "\n";
        

        //this bit actually removes and places the disc
        //////////////////////////////////////////////////////////////////
        if(towerSelect == 1)//moving from tower1
        {
            int d1 = t1->peek();
            if(towerDrop == 1)  //since you're moving to the same tower, we know it is smaller than what is already there
            {
                t1->moveDisk(t1->selectDisc());
            }
            else if(towerDrop == 2) //trying to move to tower2
            {
                if(t2->getCount() > 0)  //t2 already has something in it
                {
                    int d2 = t2->peek();
                    if(d2 == 0){d2 = 10;}
                    if(d1 < d2) //the disc is smaller than what is already there
                    {
                        t2->moveDisk(t1->selectDisc());   //go ahead and switch                     
                    }
                    else //the disk is too big
                    {
                        std::cout<<"You cannot move there." << "\n";
                        
                    }
                    
                }
                else//nothing in t2 yet
                {
                    t2->moveDisk(t1->selectDisc());
                }
            }
            else
            {
                if(t3->getCount() > 0)  //t3 already has something in it
                {
                    int d3 = t3->peek();
                    if(d3 == 0){d3 = 10;}
                    if(d1 < d3) //the disc is smaller than what is already there
                    {
                        t3->moveDisk(t1->selectDisc());   //go ahead and switch                     
                    }
                    else //the disk is too big
                    {
                        std::cout<<"You cannot move there." << "\n";
                        
                    }
                    
                }
                else//nothing in t3 yet
                {
                    t3->moveDisk(t1->selectDisc());
                } 
            }
        }
        //////////////////////////////////////////////////////////////////////////////
        else if(towerSelect == 2)//moving from tower2
        {
            int d2 = t2->peek();
            if(towerDrop == 1)//trying to move to tower 1
            {
                if(t1->getCount() > 0)  //t1 already has something in it
                {
                    int d1 = t1->peek();
                    if(d1 == 0){d1 = 10;}
                    if(d2 < d1) //the disc is smaller than what is already there
                    {
                        t1->moveDisk(t2->selectDisc());   //go ahead and switch                     
                    }
                    else //the disk is too big
                    {
                        std::cout<<"You cannot move there." << "\n";
                        
                    }
                }
                else    //nothing in t1
                {
                    t1->moveDisk(t2->selectDisc());
                }                
            }
            else if(towerDrop == 2) //trying to move to tower2
            {
                t2->moveDisk(t2->selectDisc()); 
            }
            else//trying to move to tower 3
            {
                if(t3->getCount() > 0)  //t3 already has something in it
                {
                    int d3 = t3->peek();
                    if(d3 == 0){d3 = 10;}
                    if(d2 < d3) //the disc is smaller than what is already there
                    {
                        t3->moveDisk(t2->selectDisc());   //go ahead and switch                     
                    }
                    else //the disk is too big
                    {
                        std::cout<<"You cannot move there." << "\n";
                        
                    }
                    
                }
                else//nothing in t3 yet
                {
                    t3->moveDisk(t1->selectDisc());
                } 
            }
        }
        ////////////////////////////////////////////////////////////////////////////
        else    //moving from t3
        {
            int d3 = t3->peek();
            if(towerDrop == 1)//trying to move to tower 1
            {
                if(t1->getCount() > 0)  //t1 already has something in it
                {
                    int d1 = t1->peek();
                    if(d1 == 0){d1 = 10;}
                    if(d3 < d1) //the disc is smaller than what is already there
                    {
                        t1->moveDisk(t3->selectDisc());   //go ahead and switch                     
                    }
                    else //the disk is too big
                    {
                        std::cout<<"You cannot move there." << "\n";
                        
                    }
                }
                else    //nothing in t1
                {
                    t1->moveDisk(t3->selectDisc());
                }                
            }
            else if(towerDrop == 2) //trying to move to tower2
            {
                if(t2->getCount() > 0)  //t2 already has something in it
                {
                    int d2 = t2->peek();
                    if(d2 == 0){d2 = 10;}
                    if(d3 < d2) //the disc is smaller than what is already there
                    {
                        t2->moveDisk(t3->selectDisc());   //go ahead and switch                     
                    }
                    else //the disk is too big
                    {
                        std::cout<<"You cannot move there." << "\n";
                        
                    }
                }
                else    //nothing in t1
                {
                    t2->moveDisk(t3->selectDisc());
                } 
            }
            else//trying to move to tower 3
            {
                t3->moveDisk(t3->selectDisc());
            }
        }

    std::cout<<"Tower 1"<<"\n";
    t1->display();
    std::cout<<"Tower 2"<<"\n";
    t2->display();
    std::cout<<"Tower 3"<<"\n";
    t3->display();
    std::cout<<"/////////////////////////////////////"<<"\n";
    numMoves++;
    }
    std::cout<<"It took you "<< numMoves <<" moves to complete the game!"<<"\n" << "Try to finish in seven moves!";
    return 0;   
}