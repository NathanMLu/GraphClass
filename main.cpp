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
    cout << "size is " << size << endl;
    int ids[size];
    int weights[size];
    char *data[size];
    for(int i = 0 ; i < size; i++){
        data[i] = new char[BUFFER]; //creating char array of buffer size;
    }

    //generating test cases
    makeTestCases(ids, weights, data, size);
    cout << "TEST CASES ARE MADE" << endl;
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

    //filling graph
    for(int i = 1; i < 5; i++){
        int r1 = (rand() % (size-1)) + 1;
        int r2 = (rand() % size-1) + 1;
        cout << "\nAdding edge between " << ids[r1] << " and " << ids[r2] << "... ";
        if(g.addEdge(weights[r1], ids[r1], data[r1], ids[r2], data[r2])){ //use the weight of the first one
            cout << "added!" << endl;
        }  else {
            cout << "failed!" << endl;
        }
    }
    g.bfs(ids[]);
    g.printVisualization();
    return 0;
}