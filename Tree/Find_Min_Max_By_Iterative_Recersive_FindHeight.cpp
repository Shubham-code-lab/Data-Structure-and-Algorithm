#include<iostream>
using namespace std;

class Node
{
	public:
 int data;
 Node* left;
 Node* right;
};

Node* insert(Node* root, int data)
{
  if(root  == NULL)
  {
	  Node* temp1 = new Node();
	  temp1->data = data;
	  temp1->left = NULL;
	  temp1->right = NULL;
	  root = temp1;
	  return root;
  }
  else if(data <= root->data)
	  root->left = insert(root->left , data);
  else
	  root->right = insert(root->right ,data);
  return root;
}

int FindMinIterative(Node* root)
{
	if(root == NULL)
     return -1;
	while(root->left != NULL)
	 root = root->left;
	return root->data;
}

int FindMinRecursive(Node* root)
{
   if(root == NULL)
	   return -1;
   else if(root->left == NULL)
	   return root->data;
   return FindMinRecursive(root->left);
}

int FindMaxIterative(Node* root)
{
  if(root == NULL)
	  return -1;
  while(root->right != NULL)
	  root = root->right;
  return root->data;
}

int FindMaxRecursion(Node* root)
{
   if(root == NULL)
	   return -1;
   else if(root->left == NULL)
	   return root->data;
   return FindMaxRecursion(root->right);
}


int FindHeight(Node* root)
{
   if(root == NULL)
	   return -1;
   else
   {
	   int idepth = FindHeight(root->left);
	   int rdepth = FindHeight(root->right);
	   if(idepth > rdepth)
		   return (idepth + 1);
	   else
		   return (rdepth + 1);
   }
}
int main()
{
Node* root = NULL;
root = insert(root,20);
root = insert(root,10);
root = insert(root,12);
root = insert(root,13);
root = insert(root,24);
root = insert(root,22);
root = insert(root,27);
cout<<"Minimum Value using iterative : "<<endl;
cout<<FindMinIterative(root)<<endl;
cout<<"Minimum Value using recursion : "<<endl;
cout<<FindMinRecursive(root)<<endl;
cout<<"Maximum Value using iterative : "<<endl;
cout<<FindMaxIterative(root)<<endl;
cout<<"Maximum Value using recursion : "<<endl;
cout<<FindMaxRecursion(root)<<endl;
cout<<"Height of Tree : "<<endl;
cout<<FindHeight(root)<<endl;
return 0;
}
