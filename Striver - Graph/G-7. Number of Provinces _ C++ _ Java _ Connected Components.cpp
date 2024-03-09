class Solution {
  public:
    
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            dfs(adj,it,visited);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        
        /* we have given a graph in different form
           then that's why we are converting it into
           our adj list */
           
        vector<int> list[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 and i!=j)
                list[i].push_back(j);
            }
        }
        
        /* doing dfs for every  Provinces */
        vector<int> visited(V,0);
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                cnt++;
                dfs(list,i,visited);
            }
        }
        
        return cnt;
    }
};