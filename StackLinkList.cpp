#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty, cannot pop." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
        std::cout<<stack.peek()<<" ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < 11; i++)
    {
        stack.pop();
    }
    return 0;
}