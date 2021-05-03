/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "graph.h"

graph::graph(){
}

graph::~graph(){
    //clearGraph();
}


bool graph::addVertex(int weight, int id, string info, int id1, int id2){
    int pos1 = -1;
    int pos2 = -1;
    bool success = false;
    bool duplicate = false;
    linkedList *temp = new linkedList();
    Data storage1;
    Data storage2;
    if(weight>0 && id>0 && info.size() != 0){
        if(mygraph.size() == 0){ //if its empty then create unlinked vertex, ignore id1 and id2
            temp->addNode(id, info, weight);
            mygraph.push_back(temp);
            success = true;
        } else { // if not then link the two vertices
            for(int i = 0; i<mygraph.size(); i++){
                if(mygraph[i]->exists(id)){
                    duplicate = true;
                } else if(mygraph[i]->getHeadId()==id1){
                    pos1 = i;
                } else if(mygraph[i]->getHeadId()==id2 && id2 !=-1){   
                    pos2 = i;
                }
            }
        }
        if(pos1!=-1 && pos2!=-1 && duplicate == false){
            temp->addNode(id, info, weight); //adds head data
            mygraph[pos1]->getNode(id1, &storage1);
            temp->addNode(storage1.id, storage1.information, storage1.weight);
            mygraph[pos2]->getNode(id2, &storage2);
            temp->addNode(storage2.id, storage2.information, storage2.weight);
            mygraph.push_back(temp); //connects to graph
            success = true;
        } else if(id2 == -1 && pos1 != -1 && duplicate == false){
            mygraph[pos1]->getNode(id1, &storage1); // collecting data
            temp->addNode(id, info, weight); //adds head data
            temp->addNode(storage1.id, storage1.information, storage1.weight); //add connection
            
            mygraph.push_back(temp);
            mygraph[pos1]->addNode(id, info, weight);
            success = true;
        }  
    }
    return success;
}


bool graph::addEdge(int weight, int id1, string info1, int id2, string info2){
    int pos1 = -1;
    int pos2 = -1;
    bool found = false;
    bool duplicate = false;
    linkedList *temp1 = new linkedList();
    linkedList *temp2 = new linkedList();
    if(weight>0 && (id1 && id2 >0) && (info1.size() && info2.size()!=0)){ //validates data
        for(int i = 0; i<mygraph.size(); i++){
            if(mygraph[i]->getHeadId()==id1){
                pos1 = i;
            } if(mygraph[i]->getHeadId()==id2){
                pos2 = i;
            } 
        }
        if(pos1 ==-1 && pos2 == -1){ // couldn't find either one
            temp1->addNode(id1, info1, weight);
            temp2->addNode(id2, info2, weight);
            mygraph.push_back(temp1);
            mygraph.push_back(temp2);
            pos1 = mygraph.size()-2;
            pos2 = mygraph.size()-1;
        } else if (pos1 == -1){ // couldn't find id1
            if(temp1->addNode(id1, info1, weight)){
                mygraph.push_back(temp1);
                pos1 = mygraph.size()-1;
            }
        } else if (pos2 == -1){ // couldn't find id2
            if(temp1->addNode(id2, info2, weight)){
                mygraph.push_back(temp1);
                pos2 = mygraph.size()-1;
            }
        }      
    }
    if(pos1 != -1 && pos2 != -1 && pos1!=pos2){
        if(mygraph[pos1]->addNode(id2, info2, weight)&&mygraph[pos2]->addNode(id1, info1, weight)){ // creates connection
            found = true;
        }
    }
    return found;
}

bool graph::removeVertex(int id){
    bool removed = false;
    for(int i = 0; i<mygraph.size(); i++){
        if(mygraph[i]->getHeadId()==id){
            mygraph[i]->clearList(); //sets it to null
            mygraph.erase(mygraph.begin()+i); //removes from vector
            removed = true;
        }
        if(mygraph[i]->exists(id)){
            mygraph[i]->deleteNode(id);
        }  
    }
    return removed;
}

bool graph::removeEdge(int id1, int id2){
    bool removed = false;
    int pos1 = -1;
    int pos2 = -1;
    for(int i = 0; i<mygraph.size(); i++){
        if(mygraph[i]->getHeadId()==id1){
            pos1 = i;
        } if (mygraph[i]->getHeadId()==id2){
            pos2 = i;
        }
    }
    if(pos1 != -1 && pos2 != -1 && pos1 != pos2){
        mygraph[pos1]->deleteNode(id2);
        mygraph[pos2]->deleteNode(id1);
        removed = true;
    }
    return removed;
}

bool graph::isEmpty(){
    bool empty = false;
    if(mygraph.size()==0){
        empty = true;
    }
    return empty;
}

bool graph::exists(int id){
    bool exist = false;
    for(int i= 0; i <mygraph.size(); i++){
        //if(mygraph[i])
    }
    return exist;

}

void graph:: dfs(){
    for(int i = 0; i<mygraph.size(); i++){
        cout << endl;
        mygraph[i]->printList();
        cout << endl;
    }
}



