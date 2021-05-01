/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "main.h"

int main(){
    string s = "hi";
    string d = "bye";
    graph g;
    cout <<g.addEdge(5, 19, s, 4, d)<<endl;
    cout <<g.addEdge(17, 100, s, 3, d)<<endl;
    cout <<g.addEdge(17, 3, s, 2, d)<<endl;
    //cout <<g.addEdge(17, 2, s, 2, d)<<endl;
    cout <<g.addEdge(17, 2, s, 19, d)<<endl;
    cout <<g.addEdge(17, 2, s, 4, d)<<endl;
    cout <<g.addVertex(6, 20, s, 4, -1)<<endl;
    //cout << g.removeVertex(3)<<endl;
    //cout << g.removeEdge(2,159)<<endl;
    
    
    g.dfs();
    return 0;
}