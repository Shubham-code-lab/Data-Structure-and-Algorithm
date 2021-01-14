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
	cout<<"List is : ";
    while(temp1 !=  NULL)
    {
    	cout<<temp1->data<<" ";
    	temp1 = temp1->next;
    }
    cout<<endl;
  }

Node* reverseList(Node* head)
{
   Node* temp1 = head;
   if(head == NULL)
   {
    cout<<"List is empty :"<<endl;
	return head;
   }
   Node* next ;
   Node* prev =NULL;
 while(temp1 != NULL)
 {
  next = temp1->next;
  temp1->next = prev;
  prev = temp1;
  temp1 = next;
 }
 head = prev;
 return head;

}

int main()
{
Node* head =NULL;

head = insert(head,12);
head = insert(head,24);
head = insert(head,36);
head = insert(head,48);
head = insert(head,60);
print(head);
head = reverseList(head);
print(head);


}

