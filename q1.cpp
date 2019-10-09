#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "q1.h"

using namespace std;

CustomerQueue::CustomerQueue(): front(NULL), back(NULL)
{
}

CustomerQueue::CustomerQueue(const CustomerQueue& q): front(NULL), back(NULL)
{
    QueueNodePtr Ptr1 = q.front;
    while (Ptr1 != NULL)
    {
    enter(Ptr1->ticketNum, Ptr1->time);
    Ptr1 = Ptr1->link;
    }
}

CustomerQueue::~CustomerQueue()
{
    QueueNodePtr tempPtr = front;
    while (tempPtr != NULL)
    {   
        QueueNodePtr next = tempPtr->link;
        delete tempPtr;
        tempPtr = next;
    }
}

bool CustomerQueue::emptyQueue() const
{   
    return (front == NULL);
}

void CustomerQueue::enter(int num, long enterTime)
{
    if(emptyQueue())
    {
        front = new QueueNode;
        front->ticketNum = num;
        front->time = enterTime;
        front->link = NULL;
        back = front;
    }
    else
    {
        QueueNodePtr tempPtr;
        tempPtr = new QueueNode;
        tempPtr->ticketNum = num;
        tempPtr->time = enterTime;
        tempPtr->link = NULL;
        back->link = tempPtr;
        back = tempPtr;
    }
}

void CustomerQueue::leave(int &customerNum, long &t)
{
    if(emptyQueue())
    {
        cout << "ERROR: Cannot remove item from empty queue" << endl;
        exit(1);
    }
    
    customerNum = front->ticketNum;
    t = front->time;
    
    QueueNodePtr leavePtr;
    leavePtr = front;
    front = front->link;
    
    if(front == NULL)
    {
        back = NULL;
    }
    
    delete leavePtr;
}
    


