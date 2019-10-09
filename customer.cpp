// @file customer.cpp
// @author Rico Chao
// @date 10/28/2017
// @version 1
//
// @brief ENSC 251, HW2, question 1
//
// @section DESCRIPTION
//
// 
//This C++ program simulates a customer queue at the Department of Motor Vehicles
//counter. User is given three choices and they can choose their options by pressing 1, 2,
//or 3. 1 simulates a customer's arrival to the queue, 2 simulates a customer leaving the 
//queue to the counter. 3 is to quit the program. This program demostrates queue's feature, 
//which is first in first out, through simulating customers entering and leaving the line.
//
//
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Rico Chao ____ _____10/28/2017______________
//
// ____ 301310624 ______


#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include "q1.h"

using namespace std;

int main()
{
    int count = 0;
    int k = 0;
    char choice;
    long seconds;
    
    long waitTime[3] = {0, 0, 0};
    //Type long array that is used to record the last three customer's waiting times
    
    long estimateTime = 0;
    //Estimated time that the next customer has to wait
    
    CustomerQueue queue;

    do
    {
        //Checks to see if the queue is empty or not
        if(!queue.emptyQueue())
        {
            cout << "Enter '1' to simulate a customer's arrival, '2' to help the next customer, or '3' to quit." << endl;
        }
        else
        {
            cout << "There are no customers in line. Please enter '1' to simulate a customer's arrival or '3' to quit." << endl;
        }
        
        cin >> choice;
        
        seconds = static_cast<long>(time(NULL));
        
        if(choice == '1')
        {
            //Adds number of customer by one
            count++;
            queue.enter(count, seconds);
            cout << "Customer " << count << " entered the queue at time " << seconds << endl;
        }
        else if(choice == '2')
        {
            int leaveCount = 0;
            long t1;
            
            queue.leave(leaveCount, t1);
            cout << "Customer " << leaveCount << " is being helped at time " << seconds;
            
            if(k > 2)
            {
                k = 0;
            }
            
            waitTime[k] = seconds - t1;
            cout << ". Wait time = " << waitTime[k] << " seconds" << endl;
            
            //Used to compute the estimate time, if less than three customer then average is
            //divided by the number of recorded wait times, if more than three then average
            //is divided by three
            if(waitTime[0] == 0 || waitTime[1] == 0 || waitTime[2] == 0)
            {
                estimateTime = (waitTime[0] + waitTime[1] + waitTime[2])/(k+1);
            }
            else
            {
                estimateTime = (waitTime[0] + waitTime[1] + waitTime[2])/3;
            }  
            
           //Checks if there is a next customer, if yes then print the estimated wait time for next customer
           if(!queue.emptyQueue())
           {
                cout << "The estimated wait time for customer " << leaveCount + 1 << " is " << estimateTime << " seconds." << endl;
           }
            
            k++;
        }
        else if(choice != '1' && choice != '2' && choice != '3')
        {
            //Checks whether the choice input is valid
            cout << "ERROR: invalid choice, please enter a correct choice" << endl;
        }
    
    }while(choice != '3');

    return 0;
}


