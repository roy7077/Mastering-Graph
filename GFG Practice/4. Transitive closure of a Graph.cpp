/* 
   DFS
   Time complexity - O(N*(N+E))
   Space complexity- O(N*N)
*/
class Solution{
    public:
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        //making adjancency list
        vector<int> adj[N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==j)
                continue;
                
                if(graph[i][j])
                adj[i].push_back(j);
            }
        }
        
        //reaching from each node to each node
        vector<vector<int>> ans;
        for(int i=0;i<N;i++)
        {
            vector<int> visited(N,0);
            dfs(adj,i,visited);
            
            ans.push_back(visited);
        }
        return ans;
    }
};
