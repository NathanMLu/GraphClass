/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "queue.h"

/*
bool Queue::push(int num){
    if (top < QUEUE_SIZE - 1){ 
        QueueArr[++top] = num;
        return true;
    } else {
        throw 1;
    }
}

bool Queue::isEmpty(){
    bool empty = true;

    if(top >= 0){
        empty = false;
    }

    return empty;
}

int Queue::peek(){
    if(!isEmpty()){
        return QueueArr[0];
    } else {
        throw 1;
    }
}

int Queue::(){
    if(!isEmpty()){
        int temp = myQueue[0];
        for(int i = 0 ;i<top-1; i++){
            QueueArr[i] = QueueArr[i+1];
        }
        return temp;
    } else {
        throw 1;
    }
}
*/

Queue::Queue(){
    top = -1;
}

Queue::~Queue(){
}

bool Queue::push(int id, string info){
    bool valid = false;
    if (top < QUEUE_SIZE - 1 && id > 0 && !info.empty()){
        Data *myStruct = new Data;
        myStruct->id = id;
        myStruct->information = info;
        top++;
        myQueue[top] = myStruct;
        valid = true;
    }
    return valid;  
}

bool Queue::pull(Data &queueData){
    bool popped = false;
    if(top != -1){
        queueData.information = myQueue[0]->information;
        queueData.id = myQueue[0]->id;
        delete myQueue[0];
        for(int i = 0 ;i<top-1; i++){
            myQueue[i] = myQueue[i+1];
        }
        top--;
        popped = true;
    }
    return popped;
}

bool Queue::peek(Data &queueData){
    bool peeked = false;
    if(top != -1){
        queueData.information = myQueue[0]->information;
        queueData.id = myQueue[0]->id;
        peeked = true;
    }
    return peeked;
}

bool Queue::isEmpty(){
    bool empty = true;
    if(top >=0){
        empty = false;
    }
    return empty;
}
