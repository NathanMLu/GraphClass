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
    cout <<g.addEdge(17, 2, s, 19, d)<<endl;
    cout <<g.addEdge(17, 2, s, 4, d)<<endl;
    cout <<g.addVertex(6, 2400, s, 4, -1)<<endl;
    cout << g.addEdge(4,19,s,4,d);
    cout << g.addVertex(4,79,s,19,100); 
    cout << "PRINTING THE DFS!!!!" << endl;
    g.dfs(100);
    cout << "\nDONE PRINTING!!!!" << endl;
    
    cout << "PRINTING THE BFS!!!!" << endl;
    g.bfs(100);
    cout << "\nDONE PRINTING!!!!" << endl;
    cout << "number of vertices: " << g.getVertexNum() << endl;
    g.printVisualization();
    cout << "number of edges: " <<g.getEdgeNum()<<endl;


    return 0;
}