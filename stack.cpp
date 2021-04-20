/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "stack.h"

Stack::Stack(){
    top = -1;
}

Stack::~Stack(){
}

bool Stack::push(int id, string info){
    bool valid = false;
    if (top < STACK_SIZE - 1 && id > 0 && !info.empty()){
        Data *myStruct = new Data;
        myStruct->id = id;
        myStruct->information = info;
        top++;
        myStack[top] = myStruct;
        valid = true;
    }
    return valid;  
}

bool Stack::pop(Data &stackData){
    bool popped = false;
    if(top != -1){
        stackData.information = myStack[top]->information;
        stackData.id = myStack[top]->id;
        delete myStack[top];
        top--;
        popped = true;
    }
    return popped;
}

bool Stack::peek(Data &stackData){
    bool peeked = false;
    if(top != -1){
        stackData.information = myStack[top]->information;
        stackData.id = myStack[top]->id;
        peeked = true;
    }
    return peeked;
}

bool Stack::isEmpty(){
    bool empty = true;
    if(top >=0){
        empty = false;
    }
    return empty;
}

