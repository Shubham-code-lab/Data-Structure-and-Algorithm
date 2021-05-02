#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* front =NULL;
Node* rear = NULL;

void enqueue(int data)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if(front == NULL && rear == NULL)
	{
	 front = rear = temp1;
	 return ;
	}
	else
	{
	  rear->next = temp1;
      rear = temp1;
	}
}

void dequeue()
{
	Node* temp1 = front;
   if(rear == NULL && front == NULL)
    return;
   else if(front->next == NULL && rear->next == NULL)
	   front = rear =NULL;
   else
	  front = front->next;
   delete temp1;
}

int top()
{
if(front == NULL)
	return -1;
else
	return front->data;
}

bool isEmpty()
{
if(front == NULL)
	return true;
else
	return false;
}

int main()
{

	int option;
do
{

cout<<"1. to enqueue into Lincked List "<<"\n"<<"2. to dequeue from Lincked List "<<"\n"<<"3. to check Lincked List is empty "
		<<"\n"<<"4. to check front of queue "<<"\n"<<"5. to check as is full or not" <<"\n"<<"6. to Exit"<<endl;
  cin>>option;
  if(option == 1)
  {
	  int data;
	  cout<<"enter the data :"<<endl;
	  cin>>data;
	  enqueue(data);
  }
  else if(option == 2)
  {
	  dequeue();
  }
  else if(option == 3)
  {
	  cout<<isEmpty()<<endl;
  }
  else if(option == 4)
  {
	  cout<<"Front value is : ";
	  cout<<top()<<endl;
  }
  else if(option == 5)
  {
	  cout<<isEmpty()<<endl;
  }
  else if(option == 6)
  {
	  cout<<"exited from while loop"<<endl;
  }
}while(option != 6);
	
return 0;
}
