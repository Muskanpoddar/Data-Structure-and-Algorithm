#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}
void append(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == nullptr) {
        *head_ref = newNode;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}
bool search(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    cout << "Doubly linked list: ";
    printList(head);

    int key = 30;
    if (search(head, key)) {
        cout << "Element " << key << " is present in the doubly linked list." << endl;
    } else {
        cout << "Element " << key << " is not present in the doubly linked list." << endl;
    }

    return 0;
}
