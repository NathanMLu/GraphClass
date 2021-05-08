/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "functions.h"

void makeTestCases(int *ids, int *weights, char** data, int size){
    int duplicate = (rand()%size)+1;
    string dup = "duplicate";
    string neg = "negative weight";
    string bad = "bad data";
    for(int i = 0 ; i < size-3; i++){
        ids[i] = rand() % MAX_ID +1; //creates random int from 1->1000
        if(i==duplicate){
            duplicate = ids[i];
        }
        weights[i] = rand() % MAX_ID +1;
        for(int j = 0 ; j < BUFFER-1; j++){ //traverses and fills with whatever char. It is set to 'a' initially.
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER-1] = '\0'; //marks the end of the string, we stop 1 before buffer
    }
    ids[size-3] = duplicate; //guarantees duplicate
    ids[size-2] = (rand() %size) +1;
    ids[size-1] = -1; //bad data
    weights[size-3] = duplicate;
    weights[size-2] = (rand() % 3) - 10;
    weights[size-1] = -1;
    for(int i=0; i <dup.size(); i++){
        data[size-3][i] = dup.at(i);
    }
    for(int i=0; i <neg.size(); i++){
        data[size-2][i] = neg.at(i);
    }
    for(int i=0; i <bad.size(); i++){
        data[size-1][i] = bad.at(i);
    }

}

void displayTestCases(int* ids, int* weights, char** data, int size){
    cout << "Displaying test data... " << endl;
    for(int i  = 0 ; i <size; i++){
        cout << ids[i] << ": " << data[i] << " | weight: " << weights[i] << endl;
    }
    cout << "----------------------------------------------" << endl;
}