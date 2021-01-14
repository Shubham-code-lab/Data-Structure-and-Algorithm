#include<iostream>
using namespace std;

class Node
  {
  public:
	int data;
	Node* next;
	Node* prev;
  };

Node* newNode(int data)
 {
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	temp1->prev = NULL;
	return temp1;
 }

Node* insert(int data ,Node* head)
 {
  Node* temp1 = newNode(data);
  if(head  == NULL)
  {
	  head = temp1;
	  return temp1;
  }
  Node* temp2 = head;
  while(temp2->next != NULL)
  {
	  temp2 = temp2->next;
  }
   temp2->next = temp1;
   temp1->prev = temp2;
   return head;
 }

Node* deleteNode(Node* head, int pos)
 {
	Node* temp1 = head ;
	if(pos == 1)
	{
		head = temp1->next;
		delete temp1;
		return head;
	}
  for(int i{1};i<pos;i++)
	  temp1 = temp1->next;
  if(temp1->next ==  NULL)
  {
	  temp1->prev->next = NULL;
	  delete temp1;
  }
  else
  {
  temp1->prev->next = temp1->next;
  temp1->next->prev = temp1->prev;
  delete temp1;
  }
  return head;
}

void printLinckedList(Node* head)
 {
  Node* temp1 = head;
  cout<<"The list is forward : ";
  while(temp1 != NULL)
  {
	  cout<<temp1->data<<" ";
      temp1 = temp1->next;
  }
  cout<<endl;
 temp1 = head;
 cout<<"The List in reverse : ";
 while(temp1->next != NULL)
	 temp1 = temp1->next;
 while(temp1 != NULL)
 {
	 cout<<temp1->data<<" ";
	temp1 = temp1->prev;
 }
 cout<<endl;
 }

int main()
{
Node* head = NULL;
head = insert(12, head);
head = insert(24, head);
head = insert(36, head);
head = insert(48, head);
head = insert(60, head);
head = insert(72, head);
printLinckedList(head);
head = deleteNode(head, 2);
printLinckedList(head);
head = deleteNode(head, 1);
printLinckedList(head);
head = deleteNode(head, 4);
printLinckedList(head);
return 0;
}
