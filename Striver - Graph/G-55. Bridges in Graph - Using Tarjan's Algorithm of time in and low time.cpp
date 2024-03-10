/* Tarjan's algorithm
   Time complexity - O(V*2E)
   Space complexity- O(N+N+N)
*/
class Solution {
    private:
        int timer=0;
        void dfs(vector<int>* adj,int node,int parent,vector<int>& visited,int* tin,int* low,vector<vector<int>>& bridges)
        {
            visited[node]=1;
            tin[node]=low[node]=timer;
            timer++;
            for(auto it:adj[node])
            {
                if(it==parent)
                continue;
                
                if(!visited[it])
                {
                    dfs(adj,it,node,visited,tin,low,bridges);
                    low[node]=min(low[node],low[it]);
                    
                    if(low[it]>tin[node])
                    bridges.push_back({it,node});
                }
                else
                low[node]=min(low[node],low[it]);
            }
        }
    public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int tin[n];
        int low[n];
        vector<int> visited(n,0);
        vector<vector<int>> bridges;
        dfs(adj,0,-1,visited,tin,low,bridges);
        
        return bridges;
    }
};