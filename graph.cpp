/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "graph.h"

graph::graph(){
}

graph::~graph(){
    clearGraph();
}

bool graph::addVertex(int id, string information, int weight, int id1, int id2){
    bool added = false;
    if(weight>0 && id>0 && information.length() != 0){
        for(int i = 0; i<count; i++){
            if(mygraph[i].getHeadId()==id1){
                linkedList l;
                Data temp;
                mygraph[i].getNode(id1, &temp); // fill temp with data
                l.addNode(id, information, weight); // create head for new vertex
                l.addNode(temp.id, temp.information, temp.weight); // add information we got from existing vertex
                if(mygraph[i].addNode(id, information, weight)){ // add information from new l to old vertex
                    added = true;
                } else {
                    added = false;
                }
                mygraph.push_back(l);
                if(id2!=-1){
                    mygraph[i].deleteNode(id2); //remove existing connection
                }
            } 
            if(mygraph[i].getHeadId()==id2 && id2 !=-1){//!= -1 IMPORTANT
                linkedList j;
                Data temp;
                mygraph[i].getNode(id2, &temp); // fill temp with data
                j.addNode(id, information, weight); // create head for new vertex
                j.addNode(temp.id, temp.information, temp.weight); // add information we got from existing vertex
                if(mygraph[i].addNode(id, information, weight)){ // add information from new l to old vertex
                    added = true; // we need this to check for duplicates
                } else {
                    added = false;
                }
                mygraph.push_back(j);
                mygraph[i].deleteNode(id1); //removes connection
            }
        }
    }
    if(added = true){
        count++;
    }
    return added;
}


