#include <iostream>

struct BTreeNode {
    int data;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void inOrderTraversal() const {
        inOrderRec(root);
    }

private:
    BTreeNode* root;

    BTreeNode* insertRec(BTreeNode* node, int value) {
        if (node == nullptr) {
            return new BTreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void inOrderRec(BTreeNode* node) const {
        if (node != nullptr) {
            inOrderRec(node->left);
            std::cout << node->data << " ";
            inOrderRec(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    int value;

    std::cout << "Please enter 8 integers:" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "In-order traversal of the binary search tree:" << std::endl;
    tree.inOrderTraversal();
    std::cout << std::endl;

    return 0;
}