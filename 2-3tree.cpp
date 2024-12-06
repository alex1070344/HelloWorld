#include <iostream>
using namespace std;

class Node {
public:
    int *keys;
    Node **children;
    int n;
    bool leaf;

    Node(bool leaf);
    void insertNonFull(int k);
    void splitChild(int i, Node *y);
    void traverse();

    friend class Tree;
};

class Tree {
public:
    Node *root;
    int t;

    Tree(int t) {
        root = nullptr;
        this->t = t;
    }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    void insert(int k);
};

Node::Node(bool leaf) {
    this->leaf = leaf;
    keys = new int[2 * 2 - 1];
    children = new Node *[2 * 2];
    n = 0;
}

void Node::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) children[i]->traverse();
        cout << " " << keys[i];
    }
    if (!leaf) children[i]->traverse();
}

void Tree::insert(int k) {
    if (root == nullptr) {
        root = new Node(true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * 2 - 1) {
            Node *s = new Node(false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k) i++;
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void Node::insertNonFull(int k) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > k) i--;
        if (children[i + 1]->n == 2 * 2 - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < k) i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

void Node::splitChild(int i, Node *y) {
    Node *z = new Node(y->leaf);
    z->n = 2 - 1;
    for (int j = 0; j < 2 - 1; j++) z->keys[j] = y->keys[j + 2];
    if (!y->leaf) {
        for (int j = 0; j < 2; j++) z->children[j] = y->children[j + 2];
    }
    y->n = 2 - 1;
    for (int j = n; j >= i + 1; j--) children[j + 1] = children[j];
    children[i + 1] = z;
    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y->keys[2 - 1];
    n = n + 1;
}

int main() {
    Tree t(2);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed 2-3 tree is ";
    t.traverse();

    return 0;
}