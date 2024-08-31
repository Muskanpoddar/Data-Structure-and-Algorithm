#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
Node* addToEmpty(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}
void insertBegin(Node** start, int value) {
    if (*start == nullptr) {
        *start = addToEmpty(value);
        return;
    }
    Node* last = (*start)->prev;
    Node* new_node = new Node;
    new_node->data = value; 
    new_node->next = *start;
    new_node->prev = last;
    last->next = (*start)->prev = new_node;
    *start = new_node;
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
    insertBegin(&start, 10);
    insertBegin(&start, 20);
    insertBegin(&start, 30);
    cout << "Circular Doubly Linked List: ";
    traverse(start);

    return 0;
}
