#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void insert(struct Node** start, int value) {
    if (*start == NULL) {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    Node* last = (*start)->prev;
    struct Node* new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}
void deleteNodeFromEnd(struct Node** start) {
    if (*start == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if ((*start)->next == *start) {
        delete *start;
        *start = NULL;
        cout << "Node Deleted" << endl;
        return;
    }
    Node* last = (*start)->prev;
    last->prev->next = *start;
    (*start)->prev = last->prev;
    delete last;
    cout << "Node Deleted" << endl;
}
void display(struct Node* start) {
    if (start == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    struct Node* temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

int main() {
    struct Node* start = NULL;
    insert(&start, 4);
    insert(&start, 5);
    insert(&start, 6);
    insert(&start, 7);
    insert(&start, 8);

    cout << "List Before Deletion: ";
    display(start);

    deleteNodeFromEnd(&start);
    cout << "List After Deleting last node: ";
    display(start);

    deleteNodeFromEnd(&start);
    cout << "List After Deleting last node: ";
    display(start);

    deleteNodeFromEnd(&start);
    cout << "List After Deleting last node: ";
    display(start);

    return 0;
}
