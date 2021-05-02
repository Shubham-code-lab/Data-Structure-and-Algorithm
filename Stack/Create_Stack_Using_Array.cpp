#include<iostream>
#define MAX_SIZE 101
using namespace std;

int A[MAX_SIZE];

int t = -1;

void push(int data)
{
if(t == MAX_SIZE -1)
{
	cout<<"Stack Overflow "<<endl;
	return;
}
   A[++t] = data;
}
void pop()
{
if(t == -1)
 {
	cout<<"Array is empty :"<<endl;
	return;
 }
t--;
}

bool isEmpty()
{
 if(t == -1)
 {
  return true;
 }
 return false;
}

void top()
{
if(t == -1)
 {
	cout<<"Array is emoty "<<endl;return;
 }
cout<<A[t]<<endl;
}

void print()
{
cout<<"The List is : "<<endl;
for(int i{0};i<=t;i++)
{
 cout<<A[i]<<" ";
}
cout<<endl;
}
int main()
{
	cout<<boolalpha;
	push(56);
	pop();
	cout<<isEmpty()<<endl;
	pop();
	push(12);
	push(24);
	push(36);
	push(48);
	top();
	cout<<isEmpty()<<endl;
    print();
}
