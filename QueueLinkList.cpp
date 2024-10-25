#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next = nullptr;
        if (rear != nullptr) {
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr) {
            front = rear;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return front->data;
    }
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element is: " << q.peek() << std::endl;

    q.dequeue();
    std::cout << "Front element is: " << q.peek() << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();  // Attempt to dequeue from an empty queue

    return 0;
}