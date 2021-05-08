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


bool graph::addVertex(int weight, int id, string info, int id1, int id2){
    int pos1 = -1;
    int pos2 = -1;
    bool success = false;
    bool duplicate = false;
    linkedList *temp = new linkedList();
    Data storage1;
    Data storage2;
    if(weight>0 && id>0 && info.size() != 0 &&id1!=id2){
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
        if(id2 == -1 && pos1 != -1 && duplicate == false){
            mygraph[pos1]->getNode(id1, &storage1);
            temp->addNode(id, info, weight);
            temp->addNode(storage1.id, storage1.information, storage1.weight);

            mygraph.push_back(temp);
            mygraph[pos1]->addNode(id, info, weight);
            success = true;
        } else if(pos1!=-1 && pos2!=-1 && duplicate == false){
            temp->addNode(id, info, weight);
            mygraph[pos1]->getNode(id1, &storage1);
            temp->addNode(storage1.id, storage1.information, storage1.weight);
            mygraph[pos2]->getNode(id2, &storage2);
            temp->addNode(storage2.id, storage2.information, storage2.weight);
            mygraph.push_back(temp);
            mygraph[pos2]->addNode(id, info, weight);
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
    if(weight>0 && (id1 && id2 >0) && (info1.size() && info2.size()!=0)&&id1!=id2){ //validates data
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
        if(mygraph[i]->exists(id)){
            exist = true;
        }
    }
    return exist;

}

int graph::getVertexNum(){
    return mygraph.size();
}

int graph::getEdgeNum(){
    int count = 0; 
    for(int i  = 0 ; i <mygraph.size(); i++){
        count = count + (mygraph[i]->getCount()-1);
    }

    return count/2; //because it is undirected
}

//QUESTION IS IT OK TO USE OTHER CLASS THAT I DIDNT MAKE LIKE c++ stack or queue class
void graph::dfs(int id){
    bool found = false;
    bool visited [mygraph.size()];
    Data storage;
    int store = id;
    stack <int> myStack;

    for(int i = 0; i<mygraph.size(); i++){
        visited[i] = false;
        if(mygraph[i]->getHeadId() == store){
            mygraph[i]->getNode(store, &storage);
            found = true;
        }
    }
    if(found == true){
        myStack.push(storage.id); //adding the first data
        while(!myStack.empty()){
            store = myStack.top();
            myStack.pop();
            if(visited[getPos(store)] == false){
                cout << store << " ";
                visited[getPos(store)] = true;
            }
            for(int i = 0 ; i<=(mygraph[getPos(store)]->getCount())-1; i++){
                id = mygraph[getPos(store)]->getNodeId(i);//stores the id of the index given (i)
                if(visited[getPos(id)]==false){
                    myStack.push(id);
                }
            }
        }
    }
}

void graph::bfs(int id){
    bool found = false;
    bool visited [mygraph.size()];
    Data storage;
    int store = id;
    queue <int> myQueue;

    for(int i = 0; i<mygraph.size(); i++){
        visited[i] = false;
        if(mygraph[i]->getHeadId() == store){
            mygraph[i]->getNode(store, &storage);
            found = true;
        }
    }
    if(found == true){
        myQueue.push(storage.id); //adding the first data
        while(!myQueue.empty()){
            store = myQueue.front();
            myQueue.pop();
            if(visited[getPos(store)] == false){
                cout << store << " ";
                visited[getPos(store)] = true;
            }
            for(int i = 0 ; i<=(mygraph[getPos(store)]->getCount())-1; i++){
                id = mygraph[getPos(store)]->getNodeId(i);//stores the id of the index given (i)
                if(visited[getPos(id)]==false){
                    myQueue.push(id);
                }
            }
        }
    }
}

void graph::printVisualization(){
    /*
    int id = -1;
    if(mygraph.size()!=0){
        id = mygraph[0]->getNodeId(0);
    }
    bool found = false;
    bool visited [mygraph.size()];
    Data storage;
    int store = id;
    stack <int> myStack;


    bool first = true;

    for(int i = 0; i<mygraph.size(); i++){
        visited[i] = false;
        if(mygraph[i]->getHeadId() == store){
            mygraph[i]->getNode(store, &storage);
            found = true;
        }
    }
    if(found == true){
        myStack.push(storage.id); //adding the first data
        while(!myStack.empty()){
            store = myStack.top();
            myStack.pop();
            if(visited[getPos(store)] == false){
                cout << store << "--";
                visited[getPos(store)] = true;
            }
            for(int i = 0 ; i<=(mygraph[getPos(store)]->getCount())-1; i++){
                id = mygraph[getPos(store)]->getNodeId(i);//stores the id of the index given (i)
                if(visited[getPos(id)]==false){
                    myStack.push(id);
                }
            }
        }
    }
    */
    for(int i = 0; i<mygraph.size(); i++){
        cout << endl;
        mygraph[i]->printList();
        cout << endl;
    }
}

void graph::clearGraph(){
    for(int i = 0 ; i <mygraph.size(); i++){
        mygraph[i]->clearList();
        mygraph[i] = NULL;
    }
}

int graph::getVertex(){
    int num = -1;
    if(mygraph.size()!=0){
        num = mygraph[0]->getHeadId();
    }
    return num;
}

int graph::getPos(int id){
    int pos = -1;
    for(int i = 0 ; i < mygraph.size(); i++){
        if(mygraph[i]->getHeadId()==id){
            pos = i;
        }
    }
    return pos;
}



