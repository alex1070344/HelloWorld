#include <iostream>
#include <stdexcept>

class Stack {
private:
    static const int MAX_SIZE = 20;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    int peek() const {
        if (top < 0) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }
};

int main() {
    Stack stack;
    for (int i = 1; i <= 20; ++i) {
        stack.push(i);
    }
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }

    return 0;
}