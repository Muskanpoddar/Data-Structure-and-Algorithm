#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node** start, int value) {
    if (*start == nullptr) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    Node* last = (*start)->prev;
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void traverse(Node* start) {
    if (start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

int main() {
    Node* start = nullptr;

    insertEnd(&start, 10);
    insertEnd(&start, 20);
    insertEnd(&start, 30);
    insertEnd(&start, 40);

    cout << "Circular Doubly Linked List: ";
    traverse(start);

    return 0;
}
