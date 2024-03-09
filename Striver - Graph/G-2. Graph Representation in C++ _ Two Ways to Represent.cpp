#include <iostream>
using namespace std;

/* there are two ways of representing graphs
   1. adjacency matrix
   2. adjacency list
*/

void adjacency_matrix()
{
    int n,e;
    cin>>n>>e; // n-> number of nodes
               // e-> number of edges
    
    int mat[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+;j++)
        mat[i][j]=0;
    }
    
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        
        mat[u][v]=1;
        mat[v][u]=1;
        
        /* here we have unweighted graph thats why
        we are marking it 1 
        
        if we have to make weighted graph then we
        will not mark 1 , we will mark its weight 
        */
    }
    
}

void adjacency_list()
{
    int n,e;
    cin>>n>>e; //n-> number of nodes
               //e-> number of edges 
               
    vector<int> adj[n+1];
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[u].push_back(u);
        
        /* if we had to make weighted graph
           then we will make adjacency_list 
           of pair type
           
           vector<pair<int,int>> adj[n+1]
           
           {a,b,c}
           a->first node
           b->secnd node
           c->weight of the nodes
        */
    }
}
int main() 
{
	
	return 0;
}
