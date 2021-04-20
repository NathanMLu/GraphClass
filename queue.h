/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "data.h"

#define QUEUE_SIZE 15

class Queue{
    public:
        Queue();
        ~Queue();

        bool push(int id, string info);
        bool pull(Data &queueData);
        bool peek(Data &queueData);
        bool isEmpty();
    private:
        int top;
        Data *myQueue[QUEUE_SIZE];
};

#endif