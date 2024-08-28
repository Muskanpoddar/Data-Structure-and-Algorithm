#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertAfter(Node* prev_node, int data) {
    // Check if the previous node is NULL
    if (prev_node == nullptr) {
        std::cout << "Previous node cannot be NULL" << std::endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;
    if (newNode->next != nullptr)
        newNode->next->prev = newNode;
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
    Node* first = new Node{1, nullptr, nullptr};
    Node* second = new Node{2, first, nullptr};
    first->next = second;

    head = first;

    std::cout << "Original DLL is: " << std::endl;
    printList(head);
    insertAfter(first, 3);

    std::cout << "DLL after inserting 3 after the first node: " << std::endl;
    printList(head);
    insertAfter(second, 4);

    std::cout << "DLL after inserting 4 after the second node: " << std::endl;
    printList(head);
    return 0;
}
