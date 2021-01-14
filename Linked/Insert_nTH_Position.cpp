#include<iostream>

using namespace std;

class Node{
public:
int data;
Node* next;
};

Node* head;

void insert(int data, int n)
{
  Node* temp1 = new Node();
  temp1->data =data;
  temp1->next =NULL;
    if(n==1)
	 {
      temp1->next = head;
      head = temp1;
      return ;
      }
   Node* temp2 = head;
   for(int i{0};i<n-2;i++)   //n-2 becz  we want n-1 position and at start we are at the n+1 position n-2
   {
	  temp2 =temp2->next;
   }
   temp1->next = temp2->next;
	temp2->next = temp1;
}

void print()
{
Node* temp1 = head;
 while(temp1 != NULL)
  {
	cout<<temp1->data<<" ";
	temp1 = temp1->next;
  }
}

int main()
{
 int count{0};
 cout<<"Enter total element in the linked list :"<<endl;
 cin>>count;

 for(int i{0};i<count;i++)
  {
	 int value {0};
	 int position{0};
	 cout<<"enter the vslue and position seperated by spaces :"<<endl;
	 cin>>value>>position;
	 insert(value,position);
  }
print();
return 0;
}
