#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

void addedge(vector<int>adj[] , int u , int  v )
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool bfs(vector <int>adj[] , vector<bool>&check , vector<int>&dist , vector <int>&prev, int start ,int end)
{
   queue<int> Q;
   Q.push(start);
   check[start] = true;
   dist[start] = 0;
   while(!Q.empty())
   {
	   int u  =Q.front();
	   for(int unsigned i{0}; i< adj[u].size();i++)
	   {
		   if(check[adj[u][i]] == false)
		   {
		   check[adj[u][i]] = true;
		   dist[adj[u][i]] = dist[u] + 1;    //3rd position value is 0 so 0 + 1 = 1 is assign at 0 position
	       prev[adj[u][i]] = u;
		   Q.push(adj[u][i]);
	       }
		   if(adj[u][i] == end)
		     return true;
	   }
       Q.pop();
   }
   if(Q.empty())
	   return false;
}

void path(vector<int>adj[] , int start ,  vector<bool>&check , vector<int>&dist , vector<int>&prev,int end)
{
	bool v = bfs(adj , check , dist, prev ,start ,end);
  if(!v)
  return ;

  int previous = end;
  vector<int> store;
for(auto i : prev)
	cout<<i<<" ";
  store.push_back(previous);
  while(prev[previous] !=  -1)
  {
     store.push_back(prev[previous]);
     previous = prev[previous];
  }
for(auto i: store)
	cout<<i<<" ";
}

int main()
{
	int size;
	cout<<"Enter the size of the array : "<<endl;
	cin>>size;
  	vector<int> adj[size];
  	int connection;
   cout<<"Enter Number of connection : ";
 	cin>>connection;
  	for(int i{0}; i<connection ;i++)
  	{
  	int u,v;
  	cin>>u>>v;
  	addedge(adj , u , v );
  	}
 vector<bool> check(size , false);
 vector<int> dist(size , -1);
 vector<int>prev(size , -1);
 cout<<"Enter start and end :"<<endl;
 int start,end;
 cin>>start>>end;
// bfs(adj , check , dist , prev , start , end);
 path(adj , start , check ,dist ,prev ,end);
 cout<<boolalpha;
 for(auto i : check)
	 cout<<i<<" ";
 cout<<endl;
 for(auto i : dist)
	 cout<<i<<" ";
return 0;
}
