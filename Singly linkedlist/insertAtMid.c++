#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtFront(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtPosition(Node** head_ref, int position, int new_data) {
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;

    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;
    for (int i = 1; current != NULL && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Position is greater than the length of the list." << endl;
        delete new_node;
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;

    insertAtFront(&head, 1);
    insertAtFront(&head, 2);
    insertAtFront(&head, 3);
    insertAtFront(&head, 4);
    insertAtFront(&head, 5);
    insertAtFront(&head, 6);

    cout << "After inserting Nodes at the front: ";
    printList(head);

    int position = 3;
    int new_data = 10;
    insertAtPosition(&head, position, new_data);
    cout << "After inserting " << new_data << " at position " << position << ": ";
    printList(head);

    return 0;
}
