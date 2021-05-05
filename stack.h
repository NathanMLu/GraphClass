/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef STACK_H
#define STACK_H

#include "data.h"
#include <vector>
using std::vector;


class Stack{
    public:
        Stack(int size);
        ~Stack();
        bool push(int id);
        bool pop(int &id);
        bool peek(int &id);
        bool isEmpty();
    private:
        vector <int> myStack;
};

#endif