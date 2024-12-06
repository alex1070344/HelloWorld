#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node(int data) {
         value=data; 
         next=NULL;
    }
};