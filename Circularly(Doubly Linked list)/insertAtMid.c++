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
void insertAfter(Node** start, int value1, int value2) {
    if (*start == nullptr)
        return;

    Node* temp = *start;
    while (temp->data != value2) {
        temp = temp->next;
        if (temp == *start)
            return;
    }

    Node* new_node = new Node;
    new_node->data = value1;
    Node* next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
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

    cout << "Circular Doubly Linked List before insertion: ";
    traverse(start);

    insertAfter(&start, 25, 20);
    cout << "Circular Doubly Linked List after inserting 25 after 20: ";
    traverse(start);

    insertAfter(&start, 35, 30);
    cout << "Circular Doubly Linked List after inserting 35 after 30: ";
    traverse(start);

    return 0;
}
