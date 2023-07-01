class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            indegree[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        for(auto it:indegree)
        {
            if(it>=1)
            return 1;
        }
        
        return false;
    }
};