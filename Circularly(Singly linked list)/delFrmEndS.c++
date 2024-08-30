#include<iostream>
using namespace std;

struct Node
{
    int num;
    struct Node *next;
} *head;

void insertStart(struct Node **head, int data)
{
    struct Node *newNode = new Node;
    newNode->num = data;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;

        cout << newNode->num << " Inserted\n";
    }
    else
    {
        struct Node *curr = *head;

        while (curr->next != *head)
        {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->next = *head;
        *head = newNode;

        cout << newNode->num << " Inserted\n";
    }
}

void deleteEnd(struct Node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    struct Node *cur = *head, *prev = nullptr;
    while (cur->next != *head)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    if (cur == *head)
    {
        *head = prev->next;
    }
    free(cur);
}
void display(struct Node *head)
{
    cout << "Circular Linked List: ";
    
    if (head == NULL)
    {
        cout << "Empty" << endl;
        return;
    }
    struct Node *temp = head;
    do
    {
        cout << temp->num << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
int main()
{
    struct Node *head = NULL;

    insertStart(&head, 1);
    insertStart(&head, 2);
    insertStart(&head, 3);
    insertStart(&head, 4);
    insertStart(&head, 5);
    
    cout << "Before deletion: ";
    display(head);
    deleteEnd(&head);
    
    cout << "After deletion: ";
    display(head);
    return 0;
}