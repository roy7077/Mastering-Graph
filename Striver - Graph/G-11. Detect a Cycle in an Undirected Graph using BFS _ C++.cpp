class Solution {

  private:
    
    bool iscycle(int src,vector<int> adj[],vector<int>& visited)
    {
        visited[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto adajcentnode:adj[node])
            {
                if(!visited[adajcentnode])
                {
                    visited[adajcentnode]=1;
                    q.push({adajcentnode,node});
                }
                else if(parent!=adajcentnode)
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> v(V,0);
        for(int i=0;i<V;i++)
        {
            if(!v[i])
            {
                if(iscycle(i,adj,v))
                return true;
            }
        }
        return false;
    }
};