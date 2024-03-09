
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(vector<int> adj[],int node,vector<int>& visited,vector<int>& ans)
    {
        visited[node]=1;
        ans.push_back(node);
        
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            dfs(adj,it,visited,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> visited(V+1,0);
        vector<int> ans;
        dfs(adj,0,visited,ans);
        return ans;
    }
};

// time complexity - O(Number of nodes) + O(2*Number of edges)
