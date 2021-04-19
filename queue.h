/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 15

class Queue{
    public:
        Queue();
        ~Queue();
        bool push(int num);
        bool isEmpty();
        int peek();
        int pull();

    private:
        int top;
        int StackArr[QUEUE_SIZE];
};

#endif