#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};
class CircularQueue {
private:
    Node* front;
    Node* rear;
    
public:
  
    CircularQueue() : front(nullptr), rear(nullptr) {}
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; 
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; 
        }
    }
    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. Cannot dequeue.");
        }

        Node* temp = front;
        int value = front->data;

        if (front == rear) { 
            front = rear = nullptr;
        } else {
            front = front->next;
            rear->next = front; 
        }

        delete temp;
        return value;
    }
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty. Cannot peek.");
        }
        return front->data;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
   
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Queue after enqueue operations: ";
    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    cout << "Queue after dequeue operations: ";
    queue.display();

    cout << "Front element: " << queue.peek() << endl;

    return 0;
}

