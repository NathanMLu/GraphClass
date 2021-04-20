/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

#define GRAPH_SIZE 15

class graph{
    public:
        graph();
        ~graph();
        bool addVertex(int id, string information, int weight, int id1, int id2); //vertex goes between id1 and id2
        bool addVertex(int id, string information, int weight, int id1); //overloaded, only takes one id to add to the end
        bool addVertex(int id, string information, int weight);
        bool addEdge(int weight, int id1, string info1, int id2, string info2); //adds edge between id1 and id2
        bool removeVertex(int id);
        bool removeVertex(int id1, int id2);
        bool removeEdge(int id1, int id2);
        bool isEmpty();
        int getVertexNum();
        int getEdgeNum();
        void dfs();
        void bfs();
        void printVisualization();
        
    private:
        vector <linkedList> mygraph{GRAPH_SIZE}; // vector containing linkedList
        int count;
};
#endif