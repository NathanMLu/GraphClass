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

/*
bool graph::addVertex(int id, string information, int weight, int id1, int id2){
    bool added = false;
    linkedList l, j;
    Data temp;
    if(weight>0 && id>0 && information.length() != 0){
        if(mygraph.size() == 0){ //if its empty then create unlinked vertex, ignore id1 and id2
                l.addNode(id, information, weight);
                mygraph.push_back(&l);
                added = true;
                cout << "PRINTING LIST... ";
                (*mygraph[0]).printList();
                cout << "DONE PRINTING"<<endl;
        } else { // if not then link the two vertices
            for(int i = 0; i<mygraph.size(); i++){
                cout << "PRINTING LIST... ";
                (*mygraph[0]).printList();
                cout << "DONE PRINTING"<<endl;

                if((*mygraph[i]).getHeadId()==id1){
                    cout << "ENTERED";
                    (*mygraph[i]).getNode(id1, &temp); // fill temp with data
                    l.addNode(id, information, weight); // create head for new vertex
                    l.addNode(temp.id, temp.information, temp.weight); // add information we got from existing vertex
                    if((*mygraph[i]).addNode(id, information, weight)){ // add information from new l to old vertex
                        added = true;
                    } else {
                        added = false;
                    }
                    mygraph.push_back(&l);
                    if(id2!=-1){  
                        (*mygraph[i]).deleteNode(id2); //remove existing connection
                    }
                } 
                if((*mygraph[i]).getHeadId()==id2 && id2 !=-1){//!= -1 IMPORTANT
                    cout << "ENTERED";
                    (*mygraph[i]).getNode(id2, &temp); // fill temp with data
                    j.addNode(id, information, weight); // create head for new vertex
                    j.addNode(temp.id, temp.information, temp.weight); // add information we got from existing vertex
                    if((*mygraph[i]).addNode(id, information, weight)){ // add information from new l to old vertex
                        added = true; // we need this to check for duplicates
                    } else {
                        added = false;
                    }
                    mygraph.push_back(&j);
                    (*mygraph[i]).deleteNode(id1); //removes connection
                }
            }
        }
    }
    if(added == true){
        count++;
    }
    return added;
}
*/

bool graph::addEdge(int weight, int id1, string info1, int id2, string info2){
    //creates edge between two id's if they exist.
    //if they do not exist creates vertices first then links them.
    int pos1 = -1;
    int pos2 = -1;
    bool found = false;
    linkedList *temp1 = new linkedList();
    linkedList *temp2 = new linkedList();


    //need to check for duplicates!!!

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
    if(pos1 != -1 && pos2 != -1){// found/created both
        //create connection
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



