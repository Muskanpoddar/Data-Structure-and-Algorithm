#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertFront(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = nullptr;
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}
void insertEnd(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    Node* temp = *head;
    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
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
    insertFront(&head, 1);
    insertFront(&head, 4);

    std::cout << "Created DLL is: " << std::endl;
    printList(head);

    return 0;
}
