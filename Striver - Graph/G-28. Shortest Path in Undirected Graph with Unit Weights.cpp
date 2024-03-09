class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dis(N,1e9);
        queue<int> q;
        q.push(src);
        dis[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                if(dis[node]+1<dis[it])
                {
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(N,-1);
        for(int i=0;i<N;i++)
        {
            if(dis[i]!=1e9)
            ans[i]=dis[i];
        }
        return ans;
    }
};