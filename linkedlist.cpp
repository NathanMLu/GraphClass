/* 
Name: Nathan Lu
COSC 2436
Purpose: To create a bi-directional or undirected graph that is weighted, using linkedlists, queues, stacks, and vectors. An adjancency list is used to implement the structure.
*/

#include "linkedlist.h"

//PUBLIC METHODS BEGIN HERE

linkedList::linkedList(){
    head = NULL;
}

linkedList::~linkedList(){
    clearList();
}

bool linkedList::addNode(int id, string& data, int weight){
    bool success = false;
    bool duplicate = false;
    if(head == NULL){
        addEmpty(id, data, weight); 
        success = true;
    } else if(id > 0 && data.size() != 0 && weight>0){ 
        Node* current = head;
        while(current!=NULL && success == false && duplicate == false){
            if(id == current->data.id){
                duplicate = true;
            } else if(current->next==NULL){
                addTail(id, data, weight, current);
                success = true;           
            }
            current = current->next;  
        }
    }
    return success;
}

bool linkedList::deleteNode(int id){
    bool success = false;
    if(head != NULL){
        Node* current = head;
        while(current!=NULL){
            if(id == current->next->data.id){ //this avoids deleting the head
                if(current->next==NULL){
                    deleteTail(id, current);
                    success = true;
                } else {
                    deleteMiddle(id, current);
                    success = true;
                }
            }
            current = current->next;
        }
    }
    return success;
}

bool linkedList::getNode(int id, Data* data){
    bool success = false;
    if(head!=NULL){
        Node* current = head;
        while(current!=NULL){
            if(id == current->data.id){
                data->id = current->data.id;
                data->weight = current->data.weight;
                data->information = current->data.information;
                success = true;
            }
            current = current->next;
        }
    }
    return success;
}

void linkedList::printList(){
    if(head != NULL){
        Node* current = head;
        bool tail = false;
        while(current!=NULL){
            if(current->next==NULL){
                cout << current->data.id;
            } else {
                cout <<current->data.id << " --> ";
            }
            current = current->next;
        }
    }
}

int linkedList::getCount(){
    int count = 0;
    if(head != NULL){
        Node* current = head;
        while(current != NULL){
            count++;
            current = current->next;
        }
    }
    return count;
}

bool linkedList::clearList(){
    bool success = false;
    if(head != NULL){
        Node* current = head;
        Node* next;
        while(current != NULL){
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        success = true;
    }
    return success;
}

bool linkedList::exists(int id){
    bool exists = false;
    if(head != NULL){
        Node *current = head;
        while(current != NULL && exists==false){
            if(id == current->data.id){
                exists = true;
            }
            current = current->next;
        }
    }
    return exists;
}

int linkedList::getHeadId(){
    int ret=-1;
    if(head != NULL){
        ret = head->data.id;
    }
    
    return ret;
}
//PRIVATE METHODS BEGIN HERE

void linkedList::addTail(int id, string& data, int weight, Node* current){
    Node *temp;
    temp = new Node;
    temp->data.id = id;
    temp->data.information = data;
    temp->data.weight = weight;

    temp->next = NULL;
    current->next = temp;
}

void linkedList::addEmpty(int id, string &data, int weight){
    Node* temp;
    temp = new Node;
    temp->data.id = id;
    temp->data.information = data;
    temp->data.weight = weight;
      
    temp->next = NULL;
    head = temp;
}

void linkedList::deleteTail(int id, Node* current){
    delete (current->next);
    current->next = NULL;
}

void linkedList::deleteMiddle(int id, Node* current){
    Node* temp;
    temp = new Node;
    temp = current->next;
    
    current->next = current->next->next;
    delete temp;
}