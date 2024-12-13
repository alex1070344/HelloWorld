#include <iostream>

using namespace std;
#define max 15
#define imax 7

class Node {
public:
    int value;
    Node* next;
    Node(int data=0) {
         value=data;
         next=NULL;
    }
};

class hash_link {
public:
    Node hash[imax];
    void adddata(int input)
    {
        Node* newnode = new Node(input);
        int index = input % imax;
        Node* ptr = &hash[index];
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    void printhash()
    {
        for(int i=0; i<imax; i++) {
            Node* ptr = &hash[i];
            cout<<"第"<<i<<": ";
            while(ptr->next != NULL) {
                ptr = ptr->next;
                cout<<"["<<ptr->value<<"]";
            }
            cout<<endl;
        }
    }
};


int main() {
    int n;
    hash_link hash;
    for(int i = 0; i < max; i++) {
        cin >> n;
        hash.adddata(n);
    }
    hash.printhash();
    return 0;
}