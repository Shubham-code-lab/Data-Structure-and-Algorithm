#include<iostream>
#include<stack>
#include<cstring>
//

//we can only create stack only once hence i have comment out the code


//
using namespace std;

class Node
{
public:
int data;
Node* next;
};

//void ReverseArrayWithStack(char c[],int n)
//{
//  stack<char> S;
//
//  for(int i{0};i<n;i++)
//  {
//	 S.push(c[i]);
//  }
//  for(int i{0};i<n;i++)
//  {
//	  c[i] = S.top();
//	  S.pop();
//  }
//}
//
//void print(char c[], int n)
//{
//	cout<<"The string is  : ";
//  for(int i{0};i<n;i++)
//  {
//	 cout<<c[i];
//  }
//  cout<<endl;
//}
Node* createNode(int data)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
return temp1;
}

Node* push(Node* head , int data)
{
Node* newNode = createNode(data);
newNode->next = head;
head = newNode;
return head;
}

Node* pop(Node* head)
{
if(head == NULL)
	return head;
Node* temp1 = head;
head = temp1->next;
delete temp1;
return head;
}

Node* reverseLinckedList(Node* head)
{
 stack <Node*> L;
 Node* temp1 = head;
 while(temp1->next != NULL)
 {
	 L.push(temp1);
	 temp1 = temp1->next;
 }
 head = temp1;
 while(!L.empty())
 {
	 temp1->next = L.top();
	 temp1 = L.top();
	 L.pop();
 }
   temp1->next = NULL;
   return head;
}

void print(Node* head)
{
 if(head ==  NULL)
 {return ;}
 Node* temp1 = head;
 cout<<" The data are : ";
 while(temp1 != NULL)
 {
	 cout<<temp1->data<<" ";
	 temp1 = temp1->next;
 }
 cout<<endl;
}

int main()
{
Node* head = NULL;
//char c[20];
//cout<<"Enter The string : "<<endl;
//cin.getline(c,19);
//print(c,strlen(c));
//ReverseArrayWithStack(c,strlen(c));
//print(c,strlen(c));
//cin.ignore();
head = push( head ,12 );
head = push( head ,24);
head = push( head ,36);
head = push( head ,48);


print(head);
head = reverseLinckedList(head);
print(head);
}
