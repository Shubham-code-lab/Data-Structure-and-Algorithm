#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addnode(vector<char> adj[] ,int srow ,int scol ,int erow ,int ecol , int size)
{
	for(int i{0}; i < size ; i++)
		for(int j{0};j<size;j++)
			adj[i].push_back('P');
	int totalobstacle ;
	cout<<"enter the total obstacle :";
	cin>>totalobstacle;
	while(totalobstacle > 0)
	{
		int row,col;
		cout<<"Enter the postion :"<<endl;
		cin>>row>>col;
		if(row >=0 && col >=0 && row < size && col < size)
		adj[row][col] = '#';
		else
			totalobstacle++;
		totalobstacle --;
	}
	adj[srow][scol] = 'S';
	adj[erow][ecol] = 'E';
for(int i{0};i<size;i++)
{
	for(int j{0};j<size;j++)
	  cout<<adj[i][j]<<" ";
   cout<<endl;
}
}

int explore(int r , int c , queue<int>&row , queue<int>&col ,vector<vector<bool>>&check ,vector<char>adj[],int size ,int next_nodes)
{
vector<int> rr{-1,+1,0,0};
vector<int> cc{0,0,+1,-1};
for(int unsigned i{0};i<rr.size();i++)
{
	int newr = r + rr[i];
	int newc = c + cc[i];
	if(newr < 0 || newc < 0)
		continue;
	else if(newr >= size || newc >= size)
		continue;
	else if(adj[newr][newc] == '#')
		continue;
	else if(check[newr][newc]  == true)
		continue;
	else if(check[newr][newc] == false)
	{

		check[newr][newc] = true;
		row.push(newr);
		col.push(newc);
		(next_nodes)++;
	}
}
return (next_nodes);
}

int path(vector<char>adj[],int srow , int scol ,vector<vector<bool>>&check ,int size)
{
	int rownode;
		int colnode;
		int moves = 0;
		int next_nodes = 0;
		int node_layer = 1;
	queue<int> row;
	queue<int> col;
	row.push(srow);
	col.push(scol);
	check[srow][scol] = true;
	while(!row.empty())
	{
     rownode = row.front();
     colnode = col.front();
     row.pop();
     col.pop();
     if(adj[rownode][colnode] == 'E')
     {return moves;break;}
     else check[rownode][colnode] = true;
     next_nodes = explore(rownode ,colnode ,row , col ,check,adj,size,next_nodes);
     node_layer--;
     if(node_layer == 0)
     {
    	 node_layer = next_nodes;
    	 next_nodes = 0;
    	 cout<<rownode <<" "<<colnode<<endl ;
    	 moves++;
     }
	}
	   return -1;
}


int main()
{
	int size ;
	int srow ;
	int scol ;
    int erow ;
    int ecol ;

cout<<"Enter the size of the array :"<<endl;
cin>>size;
vector <vector<bool>> check(size ,vector<bool>(size,false));
cout<<"Enter the Start row and columb of start position :"<<endl;
cin>>srow>>scol;
cout<<"Enter the end row and columb of the end position :"<<endl;
cin>>erow>>ecol;
vector<char> adj[size];
addnode(adj  ,srow ,scol ,erow ,ecol ,size);
cout<<path(adj ,srow ,scol ,check ,size);
return 0;
}
