#include<iostream>
#define MAX_VAL 4
using namespace std;

int arr [MAX_VAL];
int front =-1;
int rear =-1;


bool isEmpty()
{
  if(front == -1 && rear == -1)
    return true;
  return false;
}

bool isFull()
{
	if((rear+1) % MAX_VAL == front)
		{cout<<"queue is full";return true;}
	return false;
}

void enqueue(int data)                //enqueue/psuh at rear
{
 if(isFull())        //full
	  return;
 else if(isEmpty())                   //empty
	 {
	 rear = front = 0;
	 arr[rear] = data;
	 }
 else
 {
	 rear = (rear+1)% MAX_VAL;
     arr[rear] = data;
}}

void dequeue()
{
 if(isEmpty())                        //empty
   {cout<<"Array is Empty cann't remove "<<endl;
   return ;}
 else if(front == rear)     //one element
 {
	front = -1;
	rear = -1;
 }
 else
   front = (front+1)%MAX_VAL;
}

int frontval()
{
	if(front != -1)
return arr[front];
return -1;
}



int main()
{
	int option;
do
{

cout<<"1. to enqueue into array "<<"\n"<<"2. to dequeue from array "<<"\n"<<"3. to check array is empty "
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
	  isEmpty();
  }
  else if(option == 4)
  {
	  cout<<"Front value is : ";
	  cout<<frontval()<<endl;
  }
  else if(option == 5)
  {
	  cout<<isFull()<<endl;
  }
  else if(option == 6)
  {
	  cout<<"exited from while loop"<<endl;
  }
}while(option != 6);

return 0;
}
