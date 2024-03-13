// Time complexity - O(V+E)
class Solution {
    public:
    void dfs(vector<int>* adj,int parent,int node,vector<int>& visited,vector<int>& ans)
    {
        visited[node]=1;
        ans.push_back(node);
        for(auto it:adj[node])
        {
            if(it==parent)
            continue;
            
            if(!visited[it])
            dfs(adj,node,it,visited,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        dfs(adj,-1,0,visited,ans);
        return ans;
    }
};