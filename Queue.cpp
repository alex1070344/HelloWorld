#include <iostream>

class Queue {
private:
    static const int SIZE = 20;
    int arr[SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    bool isFull() const {
        return count == SIZE;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return value;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            std::cout << arr[(front + i) % SIZE] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Queue q;

    for (int i = 1; i <= 20; ++i) {
        q.enqueue(i);
    }

    q.display();

    return 0;
}