#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
void insertAtFront(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(Node* node)
{
	while (node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
	cout << "\n";
}
int main()
{
	Node* head = NULL;

	insertAtFront(&head, 1);
	insertAtFront(&head, 2);
	insertAtFront(&head, 3);
	insertAtFront(&head, 4);
	insertAtFront(&head, 5);
	insertAtFront(&head, 6);

    

	cout << "After inserting Nodes at their front: ";
	printList(head);
	return 0;
}
