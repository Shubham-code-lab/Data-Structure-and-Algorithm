#include<iostream>
using namespace std;



class Node
{
public:
 int data;
 Node* next;
};

Node* head = NULL;

void insert(int value)
{
  Node* temp = new Node();
  if(head != NULL)
   {
	temp->next = head;
	temp->data = value;
   }
  else
  {
	  temp->next =NULL;
	  temp->data =value;
  }
	 head = temp;
}

void print()
 {
  Node* temp = head;
  cout<<"element in list are  : "<<endl;
  while(temp != NULL)
   {
	 cout<<" "<<temp->data<<" ";
     temp = temp->next;
   }
  cout<<endl;
 }


int main()
{
int count {0};
cout<<"Enter the number of the integer inserted :"<<endl;
cin>>count;

for(int i{0};i<count;i++)
{
int value{0};
cout<<"Enter the value to enter :"<<endl;
cin>>value;
insert(value);
print();
}
};
