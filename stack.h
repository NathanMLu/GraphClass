/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef STACK_H
#define STACK_H

#include "data.h"


class Stack{
    public:
        Stack(int size);
        ~Stack();
        bool push(int id, string info);
        bool pop(Data &stackData);
        bool peek(Data &stackData);
        bool isEmpty();
    private:
        int stacksize;
        int top; 
        Data *myStack = new Data[stacksize];
};

#endif