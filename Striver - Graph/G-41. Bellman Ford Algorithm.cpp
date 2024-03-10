typedef pair<int,int> pi;
class Solution {
    public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dis(V,1e8);
        dis[S]=0;
        
        //relaxing the edges n-1 times
        for(int i=1;i<V;i++)
        {
            for(auto it:edges)
            {
                int n1=it[0];
                int n2=it[1];
                int dst=it[2];
                
                if(dis[n1]!=1e8 and (dis[n1]+dst)<dis[n2])
                dis[n2]=dis[n1]+dst;
            }
        }
        
        //checking for negative cycle
        bool flag=1;
        for(auto it:edges)
        {
            int n1=it[0];
            int n2=it[1];
            int dst=it[2];
            
            if(dis[n1]!=1e8 and (dis[n1]+dst)<dis[n2])
            {
                flag=0;
                break;
            }
        }
        
        if(!flag)
        return {-1};
        
        return dis;
    }
};