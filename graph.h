/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using std::queue;
using std::stack;
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
        // returns true if graph is empty
        bool exists(int id);
        // checks if an id exists
        int getVertexNum();
        // returns number of vertices
        int getEdgeNum();
        //returns number of edges
        int getVertex();
        //returns the first vertex it finds in the graph, useful for BFS and DFS
        void dfs(int id);
        //dfs with picking the higher id
        void bfs(int id);
        //bfs picking the lower id
        void printVisualization();
        //prints visualization of the linkedLists
        void clearGraph();
        //clears the graph
        
    private:
        int getPos(int id); //private function to getPosition of id
        vector <linkedList*> mygraph; // vector containing linkedList
};
#endif