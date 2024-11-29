#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;
        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    

    int height(Node* n) {
        return n ? n->height : 0;
    }
    int balanceFactor(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    void updateHeight(Node* n) {
        if (n) {
            n->height = 1 + max(height(n->left), height(n->right));
        }
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* balance(Node* n) {
        updateHeight(n);
        int bf = balanceFactor(n);
        if (bf > 1) {
            if (balanceFactor(n->left) < 0) {
                n->left = rotateLeft(n->left);
            }
            return rotateRight(n);
        }
        if (bf < -1) {
            if (balanceFactor(n->right) > 0) {
                n->right = rotateRight(n->right);
            }
            return rotateLeft(n);
        }
        return n;
    }
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }
        return balance(node);
    }
    //印出樹
    void printTree(Node* root, string indent, bool last) {
        if (root != nullptr) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
            cout << root->key << endl;
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }

public:
    Node* root;
    AVLTree() : root(nullptr) {}
    
    void insert(int key) {
        root = insert(root, key);
    }
    void printTree() {
        printTree(root, "", true);
    }
    //前序
    void inOrderRecF(Node* node) const {
        if (node != nullptr) {
            std::cout << node->key << " ";
            inOrderRecF(node->left);
            inOrderRecF(node->right);
        }
    }
    //中序
    void inOrderRecM(Node* node) const {
        if (node != nullptr) {
            inOrderRecM(node->left);
            std::cout << node->key << " ";
            inOrderRecM(node->right);
        }
    }
    //後序
    void inOrderRecL(Node* node) const {
        if (node != nullptr) {
            inOrderRecL(node->left);
            inOrderRecL(node->right);
            std::cout << node->key << " ";
        }
    }
};

int main() {
    AVLTree tree;
    //輸入
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(30);
    tree.insert(45);
    tree.insert(42);
    //輸出
    tree.printTree();
    //前序
    std::cout << "前序:";
    tree.inOrderRecF(tree.root);
    std::cout << endl;
    //中序
    std::cout << "中序:";
    tree.inOrderRecM(tree.root);
    std::cout << endl;
    //後序
    std::cout << "後序:";
    tree.inOrderRecL(tree.root);
    return 0;
}