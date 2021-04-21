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

class graph{
    public:
        graph();
        ~graph();
        bool addVertex(int id, string information, int weight, int id1, int id2); //vertex goes between id1 and id2
        bool addEdge(int weight, int id1, string info1, int id2, string info2); //adds edge between id1 and id2, may create extra vertex
        bool removeVertex(int id);
        bool removeEdge(int id1, int id2);
        bool isEmpty();
        int getVertexNum();
        int getEdgeNum();
        void dfs();
        void bfs();
        void printVisualization();
        void clearGraph();
        
    private:
        //WILL NEED PRIVATE OVERLOADS
        bool createVertex(int id, string information, int weight);
        vector <linkedList> mygraph; // vector containing linkedList
        int count;
};
#endif