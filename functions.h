/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "data.h"

#define MAX_ID 1000
#define BUFFER 16 //marks the length of the string generated

using std::cout;
using std::endl;

void makeTestCases(int *ids, char** data, int size);
void displayTestCases(int *ids, char** data, int size);
#endif