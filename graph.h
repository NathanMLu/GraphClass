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
        bool addVertex(int id, string information, int weight, int id1, int id2); 
        // pass in -1 for id2 if you only want one edge, weight is replaced
        bool addEdge(int weight, int id1, string info1, int id2, string info2); // adds edge between id1 and id2 if they exist, if not then creates vertex first
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
        bool createVertex(int id, string information, int weight); // creates disconnected vertex
        vector <linkedList> mygraph; // vector containing linkedList
        int count;
};
#endif