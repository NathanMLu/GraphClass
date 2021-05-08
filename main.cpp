/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "main.h"

int main(){
    //declaring random seed and arrays for id and data
    srand(time(NULL));
    int size = (rand() % (TESTCASEOFFSET + 1)) + TESTCASEMIN;
    int r1, r2, r3, r4;
    int ids[size];
    int weights[size];
    char *data[size];
    for(int i = 0 ; i < size; i++){
        data[i] = new char[BUFFER]; //creating char array of buffer size;
    }

    //generating test cases
    makeTestCases(ids, weights, data, size);
    cout << "----------------------------------------------" << endl;
    cout << "\nMAKING TEST CASES!!! \n\n" << endl;
    displayTestCases(ids, weights, data, size);

    //creating graph
    graph g;

    //testing all methods on empty graph
    cout << "\nBEGINNING TESTING!!! \n\n" << endl;
    cout << "Testing isEmpty on empty graph... ";
    if(g.isEmpty()){
        cout << "the graph is empty!" << endl;
    } else { 
        cout << "the graph is not empty!" << endl;
    }

    cout << "\nTesting getVertexNum on empty graph... " << g.getVertexNum()<<endl;
    cout << "\nTesting getEdgeNum on empty graph... " << g.getEdgeNum()<<endl;
    cout << "\nTraversing empty graph using DFS... " << endl;
    g.dfs(ids[0]);
    cout << "\nTraversing empty graph using BFS... " << endl;
    g.bfs(ids[0]);

    cout << "\nChecking if " << ids[0] << " exists in an empty graph... ";
    if(g.exists(ids[0])){
        cout << "exists!" << endl;
    } else { 
        cout << "does not exist!" << endl;
    }

    cout << "\nDeleting vertex " << ids[0] << "... ";
    if(g.removeVertex(ids[0])){
        cout << "removed!" << endl;
    } else {
        cout << "failed!" << endl;
    }

    cout << "\nRemoving edge between " << ids[0] << " and " << ids[1] << "... ";
    if(g.removeEdge(ids[0], ids[1])){
        cout << "removed!" << endl;
    } else {
        cout << "failed!" << endl;
    }

    //filling graph methodically
    r1 = 1;
    cout << "----------------------------------------------" << endl;
    cout << "\nFILLING THE GRAPH METHODICALLY!!! \n\n";
    for(int i = 0; i < size/2; i++){
        cout << "\nAdding edge between " << ids[i] << " and " << ids[r1] << "... ";
        if(g.addEdge(weights[i], ids[i], data[i], ids[r1], data[r1])){ //use the weight of the first one
            cout << "added!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
        r1++;
    }
    r1 = size-2;
    for(int i = 0; i < size-1; i++){
        cout << "\nAdding vertex " << ids[i] << " between " << ids[r1] << " and " << ids[r1+1] << "... ";
        if(g.addVertex(weights[i], ids[i], data[i], ids[r1], ids[r1+1])){ //use the weight of the first one
            cout << "added!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
        r1--;
    }
    cout << "----------------------------------------------" << endl;
    cout << "\nRANDOMLY FILLING THE GRAPH!!! \n\n";
    //randomly adding elements to the graph

    for(int i = 0; i < rand()%size; i++){
        r1 = (rand()%size);
        cout << "\nAdding edge between " << ids[i] << " and " << ids[r1] << "... ";
        if(g.addEdge(weights[i], ids[i], data[i], ids[r1], data[r1])){ //use the weight of the first one
            cout << "added!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
    }
    for(int i = 0; i < rand()%size; i++){
        r1 = (rand()%size);
        r2 = (rand()%size);
        cout << "\nAdding vertex " << ids[i] << " between " << ids[r1] << " and " << ids[r2] << "... ";
        if(g.addVertex(weights[i], ids[i], data[i], ids[r1], ids[r2])){ //use the weight of the first one
            cout << "added!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "\nDELETING HALF OF THE EDGES FROM THE GRAPH!!! \n\n";
    r1 = g.getVertexNum()/2;
    for(int i = 0; i < r1; i++){
        cout << "\nDeleting vertex " << ids[i] << "... ";
        if(g.removeVertex(ids[i])){ //use the weight of the first one
            cout << "deleted!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
    }

    cout << "----------------------------------------------" << endl;
    cout << "\nPERFORMING BASIC TESTS!!! \n\n";

    cout << "Testing isEmpty on graph... ";
    if(g.isEmpty()){
        cout << "the graph is empty!" << endl;
    } else { 
        cout << "the graph is not empty!" << endl;
    }

    cout << "\nTesting getVertexNum on graph... " << g.getVertexNum()<<endl;
    cout << "\nTesting getEdgeNum on graph... " << g.getEdgeNum()<<endl;
    cout << "\nTraversing graph using DFS..." << endl;
    g.dfs(g.getVertex());
    cout << "\n\nTraversing graph using BFS..." << endl;
    g.bfs(g.getVertex());

    cout << "\n\nChecking if " << ids[0] << " exists in graph... ";
    if(g.exists(ids[0])){
        cout << "exists!" << endl;
    } else { 
        cout << "does not exist!" << endl;
    }

    cout << "\nDeleting vertex " << ids[0] << "... ";
    if(g.removeVertex(ids[0])){
        cout << "deleted!" << endl;
    } else {
        cout << "failed!" << endl;
    }

    cout << "\nDeleting edge between " << ids[0] << " and " << ids[1] <<"... ";
    if(g.removeEdge(ids[0], ids[1])){
        cout << "removed!" << endl;
    } else {
        cout << "failed!" << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << "\nFILLING GRAPH!!! \n\n"; 
       
    for(int i  = 0; i < size; i++){
        r1 = rand() %size;
        cout << "\nAdding edge between " << ids[i] << " and " << ids[r1] << "... ";
        if(g.addEdge(weights[i], ids[i], data[i], ids[r1], data[r1])){ //use the weight of the first one
            cout << "added!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "\nRANDOMLY TESTING ALL METHODS!!! \n\n";    
    for(int i = 0 ; i < 40; i++){
        r1 = (rand() % 10);
        if(r1 == 0){
            //addVertex
            r2 = rand() %size;
            r3 = rand() %size;
            r4 = rand() %size;
            cout << "\nAdding vertex " << ids[r2] << " between " << ids[r3] << " and " << ids[r4] << "... ";
            if(g.addVertex(weights[r2], ids[r2], data[r2], ids[r3], ids[r4])){ //use the weight of the first one
                cout << "added!" << endl;
            } else {
                cout << "failed!" << endl;
            }
        } else if (r1 == 1){
            //addEdge
            r2 = rand() %size;
            r3 = rand() %size;
            cout << "\nAdding edge between " << ids[r2] << " and " << ids[r3] << "... ";
            if(g.addEdge(weights[r2], ids[r2], data[r2], ids[r3], data[r3])){ //use the weight of the first one
                cout << "added!" << endl;
            } else {
                cout << "failed!" << endl;
            }
        } else if (r1 == 2){
            //removeVertex
            r2 = rand() %size;
            cout << "\nDeleting vertex " << ids[r2] << "... ";
            if(g.removeVertex(ids[r2])){
                cout << "removed!" << endl;
            } else {
                cout << "failed!" << endl;
            }
        } else if (r1 == 3){
            //removeEdge
            r2 = rand() %size;
            r3 = rand() %size;
            cout << "\nDeleting edge between " << ids[r2] << " and " << ids[r3] <<"... ";
            if(g.removeEdge(ids[r2], ids[r3])){
                cout << "removed!" << endl;
            } else {
                cout << "failed!" << endl;
            }
        } else if (r1 == 4){
            //isEmpty
            cout << "\nTesting isEmpty on graph... ";
            if(g.isEmpty()){
                cout << "the graph is empty!" << endl;
            } else { 
                cout << "the graph is not empty!" << endl;
            }
        } else if (r1 == 5){
            //exists
            r2 = rand() % size;
            cout << "\nChecking if " << ids[r2] << " exists in graph... ";
            if(g.exists(ids[r2])){
                cout << "exists!" << endl;
            } else { 
                cout << "does not exist!" << endl;
            }
        } else if (r1 == 6){
            //vertexNum
            cout << "\nThe number of vertices is " << g.getVertexNum() << endl;
        } else if (r1 == 7){
            //edgeNum
            cout << "\nThe number of edges is " << g.getEdgeNum() << endl;
        } else if (r1 == 8){
            //dfs
            cout << "\nTraversing the graph using DFS: "; 
            g.dfs(g.getVertex());
            cout << endl;
        } else if (r1 == 9){
            //bfs
            cout << "\nTraversing the graph using BFS: "; 
            g.bfs(g.getVertex());
            cout << endl;
        } else {
            cout << "there is a problem with random!" << endl;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "\nCLEARING THE GRAPH!!! \n\n";  
    g.clearGraph();  
    cout << "the graph has been cleared!" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\nTESTING THE GRAPH WITH BAD DATA!!! \n\n";
    for(int i = 0; i <size; i++){
        r1 = size-((rand()%3)+1);
        r2 = size-((rand()%3)+1);
        r3 = size-((rand()%3)+1);
        cout << "\nAdding vertex " << ids[r1] << " between " << ids[r2] << " and " << ids[r3] << "... ";
        if(g.addVertex(weights[r1], ids[r1], data[r1], ids[r2], ids[r3])){ //use the weight of the first one
            cout << "added!" << endl;
        } else {
            cout << "failed!" << endl;
        }
        cout << "\nAdding edge between " << ids[r1] << " and " << ids[r2] << "... ";
        if(g.addEdge(weights[r1], ids[r1], data[r1], ids[r2], data[r2])){ //use the weight of the first one
            cout << "added!" << endl;
        } else {
            cout << "failed!" << endl;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "\nCLEARING LIST MANUALLY!!! \n\n";
    for(int i = 0; i < size; i++){
        cout << "\nDeleting vertex " << ids[i] << "... ";
        if(g.removeVertex(ids[i])){
            cout << "removed!" << endl;
        } else {
            cout << "failed!" << endl;
        }
    }


    



    return 0;
}