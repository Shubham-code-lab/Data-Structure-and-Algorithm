#include<iostream>

using namespace std;

class Node
{
public:
  int data;
  Node* next;
};

Node* insert(Node* head, int data)
{
 Node* temp1 = new Node();
 temp1->data = data;
 temp1->next = NULL;
 if(head == NULL)
 {
	 head = temp1;
	 return head;
 }
 Node* temp2 = head;
 while(temp2->next != NULL)
 {
	 temp2 = temp2->next;
 }
 temp2->next = temp1;
 return head;
}

void print(Node* head)
{
  Node* temp1 = head;
  cout<<"The list is : ";
  while(temp1 != NULL)
  {
	  cout<<temp1->data<<" ";
	  temp1 = temp1->next;
  }
  cout<<endl;
}

void printListRecursion(Node* head)
{
if(head == NULL)
{
 return;
}
cout<<head->data<<" ";
printListRecursion(head->next);
}

void printReverseListRecursion(Node* head)
{
  if(head == NULL)
  {
	  return;
  }
  printReverseListRecursion(head->next);
  cout<<head->data<<" ";
}

Node* ReverseLinkedList(Node* head)
{

   if(head->next == NULL)
   {
	   return head;
   }

	   Node* newhead = ReverseLinkedList(head->next);
	   head->next->next = head;
	   head->next = NULL;
	   return newhead;

}
int main()
{
Node* head =NULL;
 head = insert(head,12 );
 head = insert(head,24);
 head = insert(head,36);
 head = insert(head,48);
 head = insert(head,60);

 print(head);


 printListRecursion(head);
cout<<endl;
 printReverseListRecursion(head);

 head = ReverseLinkedList(head);
cout<<endl;
 print(head);
 return 0;
}
