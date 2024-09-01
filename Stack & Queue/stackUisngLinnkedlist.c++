#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if (top != nullptr) {
            return top->data;
        }
        cout << "Stack is empty" << endl;
        return -1;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.display();
    cout << "Top element is: " << stack.peek() << endl;
    return 0;
}
