/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "graph.h"

graph::graph(){
    count = 0;
}

graph::~graph(){
    //clearGraph();
}


bool graph::addVertex(int weight, int id, string info, int id1, int id2){
    //NEED TO CHECK FOR DUPLICATES
    int pos1 = -1;
    int pos2 = -1;
    bool success = false;
    linkedList *temp1 = new linkedList();
    linkedList *temp2 = new linkedList();
    Data temp;
    if(weight>0 && id>0 && info.size() != 0){
        if(mygraph.size() == 0){ //if its empty then create unlinked vertex, ignore id1 and id2
            cout << "empty filled first " << endl;
            (*temp1).addNode(id, info, weight);
            mygraph.push_back(temp1);
            success = true;
            count++;
        } else { // if not then link the two vertices
            for(int i = 0; i<mygraph.size(); i++){
                if(id2 == -1 && (*mygraph[i]).getHeadId() == id1){
                    cout << "id was -1 so created blank" << endl;
                    (*mygraph[i]).getNode(id1, &temp); // collecting data
                    (*temp2).addNode(id, info, weight); //adds head data
                    (*temp2).addNode(temp.id, temp.information, temp.weight); //add connection
                    mygraph.push_back(temp2);
                    (*mygraph[i]).addNode(id, info, weight);
                    success = true;
                    count++;
                } else {
                    if((*mygraph[i]).getHeadId()==id1){
                        (*mygraph[i]).getNode(id1, &temp); // collecting data
                        if(pos2 != -1){
                            (*mygraph[pos2]).addNode(temp.id, temp.information, temp.weight);
                            (*mygraph[i]).addNode(id, info, weight);
                        } else {
                            (*temp1).addNode(id, info, weight); //adds head data
                            (*temp1).addNode(temp.id, temp.information, temp.weight); //add connection
                            mygraph.push_back(temp2); //connects to graph
                            (*mygraph[i]).addNode(id, info, weight);
                        }
                        pos1 = i;
                    } if((*mygraph[i]).getHeadId()==id2 && id2 !=-1){
                        (*mygraph[i]).getNode(id2, &temp); // collecting data
                        if(pos1 != -1){
                            (*mygraph[pos1]).addNode(temp.id, temp.information, temp.weight);
                            (*mygraph[i]).addNode(id, info, weight);
                        } else {
                            (*temp2).addNode(id, info, weight); //adds head data
                            (*temp2).addNode(temp.id, temp.information, temp.weight); //add connection
                            mygraph.push_back(temp2); //connects to graph
                            (*mygraph[i]).addNode(id, info, weight);
                        }
                        pos2 = i;
                    }
                }
            }
        }
        if(pos1 != -1 && pos2 != -1){ 
            success = true;
            count++;
        }   
    }
    return success;
}


bool graph::addEdge(int weight, int id1, string info1, int id2, string info2){
    int pos1 = -1;
    int pos2 = -1;
    bool found = false;
    linkedList *temp1 = new linkedList();
    linkedList *temp2 = new linkedList();
    if(weight>0 && (id1 && id2 >0) && (info1.size() && info2.size()!=0)){ //validates data
        for(int i = 0; i<mygraph.size(); i++){ //traverses the vector and checks head
            if((*mygraph[i]).getHeadId()==id1){ // if the data exists
                pos1 = i;
            } else if((*mygraph[i]).getHeadId()==id2){ // if the data exists
                pos2 = i;
            } 
        }
        if(pos1 ==-1 && pos2 == -1){ // couldn't find either one
            (*temp1).addNode(id1, info1, weight);
            (*temp2).addNode(id2, info2, weight);
            mygraph.push_back(temp1);
            mygraph.push_back(temp2);
            pos1 = mygraph.size()-2;
            pos2 = mygraph.size()-1;
        } else if (pos1 == -1){ // couldn't find id1
            if((*temp1).addNode(id1, info1, weight)){
                mygraph.push_back(temp1);
                pos1 = mygraph.size()-1;
            }
        } else if (pos2 == -1){ // couldn't find id2
            if((*temp1).addNode(id2, info2, weight)){
                mygraph.push_back(temp1);
                pos2 = mygraph.size()-1;
            }
        }      
    }
    if(pos1 != -1 && pos2 != -1){//create connection
        (*mygraph[pos1]).addNode(id2, info2, weight);
        (*mygraph[pos2]).addNode(id1, info1, weight);
        found = true;
        count++;
    }
    return found;
}



void graph:: dfs(){
    for(int i = 0; i<mygraph.size(); i++){
        (*mygraph[i]).printList();
        cout << "printed";
    }
}



