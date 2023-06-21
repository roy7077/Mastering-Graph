#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

//bfs
void bfs(vector<int>& adj[],int node,int n)
{
    //node -> 1st node
    //n-> number of nodes
    
    queue<int> q;
    vector<int> visited(n+1,0);
    q.push(node);
    visited[node]=1;
    
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        cout<<node<<" ";
        
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
    
}

//time _Complexity -  O(number of nodes)+O(2*edges)
//space _Complexity - O(N)

