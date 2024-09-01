#include <iostream>
#define MAX 1000
using namespace std;

class QueueArray {
private:
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    QueueArray() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (size == MAX) {
            cout << "Queue Overflow" << endl;
        } else {
            rear = (rear + 1) % MAX;
            arr[rear] = value;
            size++;
        }
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow" << endl;
        } else {
            front = (front + 1) % MAX;
            size--;
        }
    }

    int peek() {
        if (size != 0) {
            return arr[front];
        }
        cout << "Queue is empty" << endl;
        return -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueArray queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.dequeue();
    queue.display();
    cout << "Front element is: " << queue.peek() << endl;
    return 0;
}
