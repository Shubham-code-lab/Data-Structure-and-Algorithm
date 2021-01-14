#include<iostream>
#include<vector>

using namespace std;

void adjNode(vector <int> adj[] , int u , int v)
{
	adj[u].push_back(v);          //directed graph adj[ij] = adj[ji]
	adj[v].push_back(u);
}


void dfs(vector<int> adj[], vector<bool> &check , int now ,vector<int>&countVec ,int &count)
{
  if(check[now] ==  true)
	  return;
  else
  {
	  check[now] = true;
      countVec[now] = count;
	  for(int unsigned i{0};i<adj[now].size();i++)
	  {
		  cout<<adj[now][i]<<" ";
         dfs(adj , check ,adj[now][i] , countVec ,count);
	  }
  }
}


int main()
{
int totalSize;
cout<<"Enter the size of the vector : "<<endl;
cin>>totalSize;
vector<int> adj[totalSize];

for(int i{0};i<totalSize;i++)
{
int u,v;
cin>>u;
cout<<" : ";
cin>>v;
adjNode(adj , u , v);
}
vector<bool> check(totalSize,false);
int nodeVal;
cout<<"Enter the Node to traverse :"<<endl;
cin>>nodeVal;

cout<<"\n"<<boolalpha;
vector<int> countVec(totalSize , 0);
int count = 0;
int i = 0 ;
while(i < totalSize )
{
	if(check[nodeVal] == false)
  dfs(adj , check , nodeVal , countVec ,count);
	cout<<"\n";
  count++;
  i++;
  nodeVal = i;
}
for(auto vec : countVec)
	cout<<vec<<" ";
cout<<"\n";
for(auto b : check)
	cout<<b<<" ";

return 0;
}
