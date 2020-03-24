class Node
{
    private:
        int discSize;
        Node* nextNode; 
    
    public:
        Node(int discSize);
        int getdiscSize();   //return discSize
        Node* getNextNode();
        void setNextNode(Node* n);
        void discDisplay();
};