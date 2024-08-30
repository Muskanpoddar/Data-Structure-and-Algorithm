#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* addToEmpty(Node* last, int data) {
    if (last != nullptr)
        return last;

    Node* temp = new Node;
    temp->data = data;
    last = temp;
    last->next = last;

    return last;
}
Node* addEnd(Node* last, int data) {
    if (last == nullptr)
        return addToEmpty(last, data);

    Node* temp = new Node;
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}
void traverse(Node* last) {
    if (last == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = last->next; 

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);

    cout << endl;
}

int main() {
    Node* last = nullptr;

    last = addToEmpty(last, 10);
    last = addEnd(last, 20);
    last = addEnd(last, 30);
    last = addEnd(last, 40);

    cout << "Circular Linked List: ";
    traverse(last);

    return 0;
}
