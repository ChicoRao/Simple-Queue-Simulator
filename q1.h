#ifndef Q1_H
#define Q1_H

class CustomerQueue
{
    public:
    CustomerQueue();
    //Default constructor sets an empty queue for the object of the class
    
    CustomerQueue(const CustomerQueue& q1);
    //Copy constructor
    
    ~CustomerQueue();
    //Destructor
    
    void enter(int num, long enterTime);
    //Precondition: The queue is empty and is ready to add node to the queue
    //Postcondition: Object node has been added to the queue
    
    void leave(int &customerNum, long &t);
    //Precondition: There are items in the queue
    //Postcondition: The front item in the queue is removed from the queue
    // and the item's ticket number and time is stored
    
    bool emptyQueue() const;
    //Checks if the queue is empty, returns true if the front of the queue is empty

    private:

    struct QueueNode
        {
            int ticketNum;
            long time;
            QueueNode *link;
        };
    
    typedef QueueNode* QueueNodePtr;
    
    QueueNodePtr front;
    //Pointer that points the head of the queue, used to 
    //removed the front item from the queue
    
    QueueNodePtr back;
    //Pointer that points to the end of the queue, used for
    //inserting new item in the back of the queue
};

#endif 