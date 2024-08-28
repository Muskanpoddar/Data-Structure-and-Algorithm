#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void traverseForward() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    void traverseBackward() {
        if (!head) return;

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    std::cout << "Forward Traversal: ";
    dll.traverseForward();

   
    std::cout << "Backward Traversal: ";
    dll.traverseBackward();

    return 0;
}
