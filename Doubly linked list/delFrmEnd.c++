#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertEnd(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNodeFromEnd(Node** head) {
    if (*head == nullptr) {
        std::cout << "List is empty, nothing to delete." << std::endl;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    if (temp->prev == nullptr) {
        *head = nullptr;
    } else {
        temp->prev->next = nullptr;
    }
    delete temp;
}
void printList(Node* node) {
    Node* last;
    std::cout << "Traversal in forward direction:" << std::endl;
    while (node != nullptr) {
        std::cout << node->data << " ";
        last = node;
        node = node->next;
    }
    std::cout << std::endl;
    std::cout << "Traversal in reverse direction:" << std::endl;
    while (last != nullptr) {
        std::cout << last->data << " ";
        last = last->prev;
    }
    std::cout << std::endl;
}
int main() {
    Node* head = nullptr;
    insertEnd(&head, 6);
    insertEnd(&head, 7);
    insertEnd(&head, 1);
    insertEnd(&head, 4);

    std::cout << "Created DLL is: " << std::endl;
    printList(head);
    deleteNodeFromEnd(&head);
    std::cout << "DLL after deleting node from the end: " << std::endl;
    printList(head);

    return 0;
}
