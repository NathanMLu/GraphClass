/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/
#include "stack.h"

Stack::Stack(int size){
    myStack.reserve(size);
}

Stack::~Stack(){
}

bool Stack::push(int id){
    bool valid = false;
    Data data;
    
    if (id > 0){
        myStack.push_back(id);
    }
    return valid;   
}

bool Stack::pop(int &id){
    bool popped = false;
    if(myStack.size() != 0){
        int id = myStack.back();
        myStack.pop_back();
        popped = true;
    }  
    return popped;
}

bool Stack::peek(int &id){
    bool peeked = false;
    if(myStack.size() != 0 ){
        id = myStack.back();
        peeked = true;
    }
    return peeked;
}

bool Stack::isEmpty(){
    return myStack.empty();
}
