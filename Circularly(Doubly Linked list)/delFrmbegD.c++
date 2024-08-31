#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insert(Node** start, int value) {
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
void deleteFromBeginning(Node** start) {
    if (*start == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = *start;

    if ((*start)->next == *start) { 
        *start = nullptr;
        delete temp;
        cout << "Node Deleted" << endl;
        return;
    }
    Node* last = (*start)->prev;
    *start = (*start)->next;
    (*start)->prev = last;
    last->next = *start;
    delete temp;
    cout << "Node Deleted" << endl;
}
void display(Node* start) {
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

    insert(&start, 4);
    insert(&start, 5);
    insert(&start, 6);
    insert(&start, 7);
    insert(&start, 8);

    cout << "List Before Deletion: ";
    display(start);

    deleteFromBeginning(&start);
    cout << "List After Deletion: ";
    display(start);

    deleteFromBeginning(&start);
    cout << "List After Deletion: ";
    display(start);

    return 0;
}
