// Method - 1 
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        K++;
        vector<pair<int,int>> adj[n];
        
        for(auto it:flights)
        adj[it[0]].push_back({it[1],it[2]});
            
        vector<int> dis(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            
            int stop=f.first;
            int node=f.second.first;
            int d=f.second.second;
            
            if(stop==K or node==dst)
            continue;
            
            for(auto x:adj[node])
            {
                int d1=d+x.second;
                if(dis[x.first]>d1)
                {
                    dis[x.first]=d1;
                    q.push({stop+1,{x.first,d1}});
                }
            }
        }
        
        if(dis[dst]>=1e9)
        return -1;
        else
        return dis[dst];
    }
};

// Method - 2 
typedef pair<int,int> pi;
class Solution {
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //making adjancacy list
        vector<pi> adj[n+1];
        for(auto it:flights)
        adj[it[0]].push_back({it[1],it[2]});
        
        //second step
        queue<pi> q;
        vector<int> v(n+1,1e9);
        v[src]=0;
        
        q.push({0,src});
        int stps=0;
        while(!q.empty() and stps<(k+1))
        {
            int size=q.size();
            
            //exploring all flights from current node
            while(size--)
            {
                auto it=q.front();
                q.pop();

                int node=it.second;
                int dis=it.first;
                for(auto x:adj[node])
                {
                    int current_dis=dis+x.second;
                    if(v[x.first]>current_dis)
                    {
                        v[x.first]=current_dis;
                        q.push({current_dis,x.first});
                    }
                }
            }
            stps++;

        }
        return v[dst]>=1e9 ? -1:v[dst];
    }