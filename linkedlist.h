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
        bool addNode(int id, string& data); //adds node
        bool deleteNode(int id); //deletes node
        bool getNode(int id, Data* data); //passes in string and id and 
        void printList(bool backwards = false); //prints forwards or backwards based on bool
        int getCount(); //number of nodes in list
        bool clearList(); //resets
        bool exists(int id); //checks if id exists in list

    private:
        void addHead(int id, string& data);
        void addTail(int id, string& data, Node* current);
        void addMiddle(int id, string& data, Node* current);
        void addEmpty(int id, string& data); //if it is empty
        
        void deleteHead(int id);
        void deleteTail(int id, Node* current);
        void deleteMiddle(int id, Node* current);

        Node *head;
};

#endif