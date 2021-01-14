#include<iostream>

using namespace std;

class Node
{
public:
int data;
Node* next;
};

Node* head =NULL;

void insert(int data,int n)
{

Node* temp1 = new Node();
temp1->data =data;
temp1->next =NULL;
 if(n == 1)
  {
   head = temp1;
   return;
  }

Node* temp2 = head;
for(int i{0};i<n-2;i++)
 {
 temp2 = temp2->next;
 }
temp2->next = temp1;

}

void deleteNode(int pos)
{
 Node* temp1 = head;
 if(pos == 1)
 {
 head = temp1->next;
 delete temp1;
 }

 for(int i{0};i<pos-2;i++)
 {
 temp1 = temp1->next;    //temp1 is n-1
 }
 Node* temp2 =temp1->next;  //temp2 is n
 temp1->next = temp2->next;
 delete temp2;
}

void print()
{
Node* temp1	=head;
cout<<"List is : ";
 while(temp1 != NULL)
  {
	 cout<<temp1->data<<" ";
	 temp1 = temp1->next;
  }
 cout<<endl;
}

int main()
{
int size{};
cout<<"Enter the size of the linked list :"<<endl;
cin>>size;
for(int i{0};i<size;i++)
  {
	int value{0};
	cout<<"Enter number to insert : "<<endl;
	cin>>value;
	insert(value,(i+1));
  }
print();
for(int i{0};i<size;i++)
{
int pos{1};
cout<<"Enter the position of the number to be deleted : ";
cin>>pos;
deleteNode(pos);
print();
}
return 0;
}
