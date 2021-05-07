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
    int r1;
    int r2;
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

    cout << "\nRemoving vertex " << ids[0] << " from empty graph... ";
    if(g.removeVertex(ids[0])){
        cout << "removed vertex!" << endl;
    } else {
        cout << "remove vertex failed!" << endl;
    }

    cout << "\nRemoving edge between " << ids[0] << " and " << ids[1] << " from empty graph... ";
    if(g.removeEdge(ids[0], ids[1])){
        cout << "removed edge!" << endl;
    } else {
        cout << "remove edge failed!" << endl;
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
    g.printVisualization();
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

    g.printVisualization();
    cout << "----------------------------------------------" << endl;
    cout << "\nRANDOMLY FILLING THE GRAPH!!! \n\n\n";
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
    g.printVisualization();
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
    

    



    //g.bfs(ids[0]);
    g.printVisualization();
    return 0;
}