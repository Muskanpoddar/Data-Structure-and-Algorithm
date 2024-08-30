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
Node* addAfter(Node* last, int data, int item) {
    if (last == nullptr)
        return nullptr;
    Node* temp;
    Node* p = last->next;

    do {
        if (p->data == item) {
            temp = new Node;
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;

            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << item << " not present in the list." << endl;
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
    cout << "Circular Linked List before adding after a specified node: ";
    traverse(last);

    last = addAfter(last, 25, 20);
    cout << "Circular Linked List after adding 25 after 20: ";
    traverse(last);

    last = addAfter(last, 35, 30);
    cout << "Circular Linked List after adding 35 after 30: ";
    traverse(last);

    last = addAfter(last, 45, 40);
    cout << "Circular Linked List after adding 45 after 40: ";
    traverse(last);

    return 0;
}
