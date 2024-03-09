
class Solution {
  public:

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> dis(n+1,1e9);
        vector<int> p(n+1);
        dis[1]=0;
        for(int i=1;i<=n;i++)
        p[i]=i;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int node=it.second;
            int d=it.first;
            
            for(auto x:adj[node])
            {
                int d2=d+x.second;
                if(dis[x.first]>d2)
                {
                    pq.push({d2,x.first});
                    dis[x.first]=d2;
                    p[x.first]=node;
                }
            }
        }
        
        if(dis[n]>=1e9)
        return  {-1};
        
        vector<int> ans;
        ans.push_back(n);
        int i=n;
        while(1)
        {
            if(p[i]==i)
            {
                break;
            }
            
            i=p[i];
            ans.push_back(i);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};