#include<iostream>

using namespace std;

class Node
{
public:
int data;
Node* next;
};

Node* createNode(int data)
{
 Node* newNode = new Node();
 newNode->data =data;
 newNode->next = NULL;
 return newNode;
}
Node* push(Node* top,int data)
{
 Node* newNode = createNode(data);
 if(top == NULL)
 {
	 top = newNode;
	 return top;
 }
 newNode->next = top;
 top = newNode;
 return top;
}

Node* pop(Node* top)
{
	if(top == NULL)
	{	cout<<"List is Empty : "<<endl;return top;}
 Node* temp1 = top;
 top = temp1->next;
 delete temp1;
 return top;
}

bool isEmpty(Node* top)
{
	if(top == NULL)
return true;
	return false;
}

void topNode(Node* top)
{
   if(top == NULL)
   {
	   cout<<"List is empty : "<<endl;
	   return;
   }
   cout<<top->data<<endl;
}
void print(Node* top)
{
	Node* temp1 = top;
	cout<<"List is : ";
  while(temp1 != NULL)
  {
	  cout<<temp1->data<<" ";
	  temp1= temp1->next;
  }
  cout<<endl;
}

int main()
{
Node* top = NULL;


cout<<boolalpha;
top = push(top,56);
top = pop(top);
cout<<isEmpty(top)<<endl;
top = pop(top);
top = push(top,12);
top = push(top,24);
top = push(top,36);
top = push(top,48);
topNode(top);
cout<<isEmpty(top)<<endl;
print(top);

}
