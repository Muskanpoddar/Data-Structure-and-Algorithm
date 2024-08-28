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
void deleteNodeFromBeginning(Node** head) {
    if (*head == nullptr) {
        std::cout << "List is empty, nothing to delete." << std::endl;
        return;
    }

    Node* del_node = *head;
    *head = del_node->next;

    if (*head != nullptr)
        (*head)->prev = nullptr;

    delete del_node;
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
    insertFront(&head, 6);
    insertFront(&head, 7);
    insertFront(&head, 1);
    insertFront(&head, 4);

    std::cout << "Created DLL is: " << std::endl;
    printList(head);
    deleteNodeFromBeginning(&head);

    std::cout << "DLL after deleting node from the beginning: " << std::endl;
    printList(head);

    return 0;
}
