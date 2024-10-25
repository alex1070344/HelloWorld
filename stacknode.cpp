#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        StackNode* newNode = new StackNode(data);
        if (top == nullptr) {
            top = newNode;
        } else {
            StackNode* temp = top;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int pop() {
        if (top == nullptr) {
            std::cerr << "Stack underflow" << std::endl;
            return -1;
        }

        StackNode* temp = top;
        StackNode* prev = nullptr;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        int poppedData = temp->data;
        if (prev != nullptr) {
            prev->next = nullptr;
        } else {
            top = nullptr;
        }

        delete temp;
        return poppedData;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        StackNode* temp = top;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack elements: ";
    stack.display();

    std::cout << "Popped element: " << stack.pop() << std::endl;

    std::cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}