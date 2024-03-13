// Time complexity - O(V+E)
class Solution {
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> v;
        vector<int> visited(V,0);
        queue<int> q;
        visited[0]=1;
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            v.push_back(node);
            
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return v;
    }
};