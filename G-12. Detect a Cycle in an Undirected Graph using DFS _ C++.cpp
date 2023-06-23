class Solution {
  public:
    
    bool dfs(vector<int>* adj,int node,int parent,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                bool ans=dfs(adj,it,node,visited);
                if(ans)
                return 1;
            }
            else if(visited[it]==1 and it!=parent)
            return 1;
        }
        
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                bool ans=dfs(adj,i,-1,visited);
                if(ans)
                return 1;
            }
        }
        
        return 0;
    }
};


