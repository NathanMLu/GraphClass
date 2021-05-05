/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class linkedList{
    public:
        linkedList();
        ~linkedList();
        bool addNode(int id, string& data, int weight); //adds node
        bool deleteNode(int id); //deletes node
        bool getNode(int id, Data* data);
        void printList();
        int getCount(); //number of nodes in list
        bool clearList();
        bool exists(int id);
        int getHeadId();
        int getNodeId(int pos);

    private:
        void addTail(int id, string& data, int weight, Node* current);
        void addEmpty(int id, string& data, int weight); 
        void addMiddle(int id, string& data, int weight, Node* current);
        
        void deleteTail(Node* current);
        void deleteMiddle(Node* current);

        Node *head;
};

#endif