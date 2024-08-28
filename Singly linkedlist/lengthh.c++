#include <iostream>
using namespace std;

// Definition of a node in the singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// Function to calculate the length of the linked list
int length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Length of the linked list: " << length(head) << endl;

    return 0;
}
