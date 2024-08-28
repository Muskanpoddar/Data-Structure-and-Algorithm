#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
void push(Node* &head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}
void append(Node* &head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	Node* last = head;

	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
}
void printList(Node* node)
{
	while (node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;
	push(head, 6);
	push(head, 5);
	push(head, 4);
	push(head, 3);
	push(head, 2);

	cout << "Created Linked list is: ";
	printList(head);

	append(head, 1);
	cout << "\nAfter inserting 1 at the end: ";
	printList(head);

	return 0;
}
