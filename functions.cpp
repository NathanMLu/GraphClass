/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "functions.h"

void makeTestCases(int *ids, char** data, int size){
    for(int i = 0 ; i < size; i++){
        ids[i] = rand() % MAX_ID +1; //creates random int from 1->1000
        for(int j = 0 ; j < BUFFER-1; j++){ //traverses and fills with whatever char. It is set to 'a' initially.
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER-1] = '\0'; //marks the end of the string, we stop 1 before buffer
    }
}

void displayTestCases(int* ids, char** data, int size){
    cout << "Displaying test data... " << endl;
    for(int i  = 0 ; i <size; i++){
        cout << ids[i] << ": " << data[i] << endl;
    }
}