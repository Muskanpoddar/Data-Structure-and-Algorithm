#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insert(Node** start, int value) {
    if (*start == NULL) {
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
void deleteNode(Node** start, int key) {
    if (*start == NULL) return;

    Node *curr = *start, *prev_1 = NULL;
    while (curr->data != key) {
        if (curr->next == *start) {
            cout << "List doesn't have node with value = " << key << endl;
            return;
        }
        prev_1 = curr;
        curr = curr->next;
    }
    if (curr->next == *start && prev_1 == NULL) {
        *start = NULL;
        free(curr);
        return;
    }
    if (curr == *start) {
        prev_1 = (*start)->prev;
        *start = (*start)->next;
        prev_1->next = *start;
        (*start)->prev = prev_1;
        free(curr);
    } else if (curr->next == *start) {
        prev_1->next = *start;
        (*start)->prev = prev_1;
        free(curr);
    } else {
        Node* temp = curr->next;
        prev_1->next = temp;
        temp->prev = prev_1;
        free(curr);
    }
}
void display(Node* start) {
    Node* temp = start;
    while (temp->next != start) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}
int main() {
    Node* start = NULL;

    insert(&start, 4);
    insert(&start, 5);
    insert(&start, 6);
    insert(&start, 7);
    insert(&start, 8);
    cout << "List Before Deletion: ";
    display(start);

    deleteNode(&start, 9);
    cout << "\nList After Deletion: ";
    display(start);

    deleteNode(&start, 4);
    cout << "\nList After Deleting 4: ";
    display(start);

    deleteNode(&start, 8);
    cout << "\nList After Deleting 8: ";
    display(start);

    deleteNode(&start, 6);
    cout << "\nList After Deleting 6: ";
    display(start);
    return 0;
}
