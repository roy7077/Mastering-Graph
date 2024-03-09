class Solution {
  public:
  
    bool dfs_cycle(int node,vector<int>* adj,vector<int>& visited,vector<int>& pathvisited,vector<int>& check)
    {
        pathvisited[node]=1;
        visited[node]=1;
        check[node]=1;
        
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                bool a=dfs_cycle(it,adj,visited,pathvisited,check);
                if(a)
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(pathvisited[it])
            {
                check[node]=0;
                return true;
            }
        }
        
        pathvisited[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        vector<int> check(V,0);
        vector<int> safenodes;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            bool ans=dfs_cycle(i,adj,visited,pathvisited,check);
        }
        
        for(int i=0;i<V;i++)
        {
            if(check[i])
            safenodes.push_back(i);
        }
        
        
        return safenodes;
    }
};
