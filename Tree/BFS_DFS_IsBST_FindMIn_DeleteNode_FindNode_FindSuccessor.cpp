#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node
{
public:
int data;
Node* left;
Node* right;
};

Node* insert(Node* root ,int data)
{
  if(root == NULL)
  {
	 Node* temp1 = new Node();
	 temp1->data = data;
	 temp1->left = NULL;
	 temp1->right = NULL;
	 root = temp1;
	 return root;
  }
  else if(data <= root->data)
	  root->left = insert(root->left, data);
  else
	  root->right = insert(root->right , data);
}

void levelOrderPrint(Node* root)
{
 if(root == NULL)
 {cout<<"Empty "; return ;}
 queue <Node*> Q;
 Q.push(root);
 while(!Q.empty())
 {
   Node* temp1 =Q.front();
   cout<<temp1->data<<" ";
  if(temp1->left != NULL)
	  Q.push(temp1->left);
  if(temp1->right != NULL)
      Q.push(temp1->right);
   Q.pop();
 }
}

void PreOrder(Node* root)
{
 if(root == NULL )
	 return ;
 cout<<root->data<<" ";
 PreOrder(root->left);
 PreOrder(root->right);
}

void InOrder(Node* root)
{
 if(root == NULL)
	 return ;
 InOrder(root->left);
 cout<<root->data<<" ";
 InOrder(root->right);
}

void PostOrder(Node* root)
{
 if(root == NULL)
	 return ;
 PostOrder(root->left);
 PostOrder(root->right);
 cout<<root->data<<" ";
}

bool IsLeftSubTreeSmaller(Node* root ,int value)
{
 if(root == NULL)
	 return true;
 else if(root->data <= value && IsLeftSubTreeSmaller(root->left , value) && IsLeftSubTreeSmaller(root->right , value))
	 return true;
 else return false;
}

bool IsRightSubTreeGreater(Node* root ,int  value)
{
	if(root == NULL)
		return true;
	else if(root->data > value && IsRightSubTreeGreater(root->left , value) && IsRightSubTreeGreater(root->right , value))
		return true;
	else return false;
}

bool CheckIfBinarySearchTree(Node* root)    //not efficient as we check same value again and again time complexity square of n
{
 if(root == NULL)
	 return true;
 if(CheckIfBinarySearchTree(root->left) && CheckIfBinarySearchTree(root->right) &&
	IsLeftSubTreeSmaller(root->left , root->data) && IsRightSubTreeGreater(root->right , root->data))
    return true;
 else
    return false;
}

bool CheckIfBinarySearchTreeEfficentWay(Node* root , int minValue , int maxValue)  //on right side root value is always small which is minValue but after that tre cn go left at that time new value at postion can be greater than left address data
{
  if(root == NULL)
	  return true;
  else if(root->data > minValue && root->data < maxValue && CheckIfBinarySearchTreeEfficentWay(root->left , minValue , root->data)
          && CheckIfBinarySearchTreeEfficentWay(root->right , root->data , maxValue  ))
	  return true;
  else return false;
}

Node* findMin(Node* root)
{
	if(root->left == NULL)
		return root;
	else
		root->left = findMin(root->left);
}
Node* DeleteNode(Node* root , int data)
{
  if(root == NULL)
	  return root;
  else if(data < root->data)
	  root->left = DeleteNode(root->left , data);
  else if(data > root->data)
	  root->right = DeleteNode(root->right , data);
  else
  {
	  if(root->left ==  NULL && root->right == NULL)
	  {
        delete root;
        root = NULL;
	  }
	  else if(root->left == NULL)
	  {
		  Node* temp1 = root->right;
		  delete root;
		  root = temp1;
	  }
	  else if(root->right == NULL)
	  {
		  Node* temp1 = root->left;
		  delete root;
		  root = temp1;
	  }
	  else
	  {
		  Node* temp1 = findMin(root->right);
		  root->data = temp1->data;
          root->right = DeleteNode(root->right , root->data);
	  }
  }
  return root;
}

Node* FindNode(Node* root , int data)
{
	if(data == root->data)
		return root;
	else if(data < root->data)
		return FindNode(root->left , data);
	else
		return FindNode(root->right , data);
}

Node* FindMinInRightSubTree(Node* root)
{
	if(root->left == NULL)
		return root;
	else
		return FindMinInRightSubTree(root->left);  // don't do root->left = FindMinInRightSubTree(root->left); becoz your fuction will return original root value but it can be used to re allocate the address during recurssion
}

int FindSuccessor(Node* root, int data)
{
 if(root == NULL)
	 return -1;
    Node* current = FindNode(root , data);
    if(current->right != NULL)
    {
    	Node* successor =FindMinInRightSubTree(current->right);
       return successor->data;
    }
    else
    {
    	Node* ansister =  root;
    	Node* successor = ansister;
    	while(ansister != current)
    	{
    		if(ansister->data < current->data)
    		{
    			successor = ansister;
    			ansister = ansister->left;
    		}
    		else
    		{
    			ansister = ansister->right;
    		}
    	}
    	return successor->data;
    }
}

 int main()
 {
 Node* root = NULL;
 root = insert(root , 10);
 root = insert(root , 3);
 root = insert(root , 4);
 root = insert(root , 2);
 root = insert(root , 1);
 root = insert(root , 5);
 root = insert(root , 19);
 root = insert(root , 12);
 root = insert(root , 15);
 root = insert(root , 16);
 root = insert(root , 17);
 root = insert(root , 11);

 cout<<"Level Order Traversal to Print data : "<<endl;
 levelOrderPrint(root);
 cout<<"\n\n"<<"PreOrder Traversal to Print data :"<<endl;
 PreOrder(root);
 cout<<"\n\n"<<"InOrder Traversal To print data :"<<endl;
 InOrder(root);
 cout<<"\n\n"<<"PostOrder Traversal To print data :"<<endl;
 PostOrder(root);
 cout<<boolalpha;
 cout<<"\n\n"<<"Check if tree is binary search ineficient way tree :"<<endl;
 cout<<CheckIfBinarySearchTree(root)<<endl;
 cout<<"\n\n"<<"Check if tree is binary search eficient way tree :"<<endl;
 cout<<CheckIfBinarySearchTreeEfficentWay(root , INT_MIN , INT_MAX);
 cout<<"\n\n"<<"Delete Node in a Binary Search tree :"<<endl;
 root = DeleteNode(root , 17);
 cout<<"\n"<<"InOrder Traversal To print data :"<<endl;
 InOrder(root);
 cout<<"\n\n"<<"Delete Node in a Binary Search tree :"<<endl;
 root = DeleteNode(root , 3);
 cout<<"\n"<<"InOrder Traversal To print data :"<<endl;
 InOrder(root);
 cout<<"\n\n"<<"Successor of the entered data is :"<<endl;
 cout<<FindSuccessor(root, 4)<<endl;
 cout<<"\n\n"<<"Successor of the entered data is :"<<endl;
 cout<<FindSuccessor(root, 15)<<endl;
 cout<<"\n"<<"InOrder Traversal To print data :"<<endl;
 InOrder(root);

 return 0;
 }
