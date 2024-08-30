#include<iostream>
using namespace std;

struct Node
{
  int num;
  struct Node *next;
};
void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->num = data;
  if (*head == NULL)
    {
      *head = newNode;	
      (*head)->next = *head;

      cout << newNode->num << " Inserted\n"; return; 
    } 
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
  void deleteBegin (struct Node **head) 
  { 
      struct Node *p, *temp; p = *head;
      while (p->next != (*head))
    {
      p = p->next;
    }
  temp = *head;
  p->next = (*head)->next;
  *head = (*head)->next;

  free (temp);
}
void deleteSpecific (struct Node **head, int pos)
{
  if (pos < 1)
    {
      cout << "Invalid position entered";
      }
      else if (pos == 1) { 
          deleteBegin (head); 
      } 
      else { 
          struct Node *p, *q; 
          int del, k = 0; 
          del = pos - 1; p = *head;
          while (k != del) {
              q = p;
              p = p->next;
	  k++;
	}
      q->next = p->next;
      free (p);			
    }			
}
void display (struct Node *head)
{
  cout << "\nCircular Linked List : " << endl;
  if (head == NULL)
    return;

  struct Node *temp = head;
  do
    {
      cout << temp->num << " "; temp = temp->next;
    }
  while (temp != head);
  cout << endl;
}
int main ()				
{
  struct Node *head = NULL;

  insertStart (&head, 1);
  insertStart (&head, 2);
  insertStart (&head, 3);
  insertStart (&head, 4);
  insertStart (&head, 5);
  cout << "Before deletion ";
  display (head);
  deleteSpecific (&head, 3);
  cout << "After deletion ";
  display (head);
  return 0;
}
