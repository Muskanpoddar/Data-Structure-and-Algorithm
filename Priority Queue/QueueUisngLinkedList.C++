#include <iostream>
using namespace std;

class Node {
public:
    int data;       // Value of the node
    int priority;   // Priority of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node with data and priority
    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

// Priority Queue class using linked list
class PriorityQueue {
private:
    Node* front;    // Front of the priority queue

public:
    // Constructor to initialize an empty queue
    PriorityQueue() {
        front = nullptr;
    }

    // Enqueue function to insert elements into the queue based on their priority
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // Insert at the front if the queue is empty or the priority of the new node is higher
        if (front == nullptr || front->priority > priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse the queue and insert the new node in the correct position
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Dequeue function to remove the element with the highest priority (lowest priority number)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Peek function to view the element with the highest priority
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display function to print all elements of the queue along with their priorities
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << "Data: " << temp->data << " | Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

// Main function to demonstrate the priority queue operations
int main() {
    PriorityQueue pq;

    pq.enqueue(10, 2);  // Insert data 10 with priority 2
    pq.enqueue(20, 1);  
    pq.enqueue(30, 3);  

    cout << "Priority Queue elements after insertion:" << endl;
    pq.display();       // Display the queue

    cout << "\nPeek: " << pq.peek() << endl;  // Peek at the element with the highest priority

    cout << "\nDequeuing highest priority element..." << endl;
    pq.dequeue();       // Dequeue the element with the highest priority

    cout << "\nPriority Queue elements after dequeue:" << endl;
    pq.display();       // Display the queue after dequeue

    return 0;
}
