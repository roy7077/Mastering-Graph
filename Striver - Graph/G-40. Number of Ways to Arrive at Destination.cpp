#define ll long long
int mod=1e9+7;
typedef pair<int,int> pi;
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //making adj list
        vector<pi> adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //dis algorithm
        vector<ll> dis(n,1e18);
        vector<int> ways(n,0);
        dis[0]=0;
        ways[0]=1;
        
        priority_queue <pi, vector<pi>, greater<pi>> pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int node=it.second;
            ll steps=it.first;
            pq.pop();
            
            for(auto x:adj[node])
            {
                ll temp=steps+x.second;
                if(temp<dis[x.first])
                {
                    pq.push({temp,x.first});
                    dis[x.first]=temp;
                    ways[x.first]=ways[node];
                }
                else if(temp==dis[x.first])
                ways[x.first]=(ways[x.first]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};