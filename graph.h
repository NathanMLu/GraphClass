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
        //constructor
        ~graph();
        //destructor
        bool addVertex(int weight, int id, string info, int id1, int id2); 
        // adds vertex between two vertices, if id2 is set to -1, creates single vertex with one link to id1 vertex. 
        // does not remove connection between existing ids
        bool addEdge(int weight, int id1, string info1, int id2, string info2); 
        // creates edge between two id's if they exist, if they dont exist creates vertices first then links them.
        bool removeVertex(int id);
        // removes a given vertex id and all conections to it (may make the graph disconnected)
        bool removeEdge(int id1, int id2);
        // removes an edge between two valid id's
        bool isEmpty();
        bool exists(int id);
        int getVertexNum();
        int getEdgeNum();
        void dfs();
        void bfs();
        void printVisualization();
        void clearGraph();
        
    private:
        bool createVertex(int id, string information, int weight);
        vector <linkedList*> mygraph; // vector containing linkedList
};
#endif