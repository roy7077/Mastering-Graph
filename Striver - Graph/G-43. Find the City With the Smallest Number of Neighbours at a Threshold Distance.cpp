/* Method - 1
   Floyd warshall Algorithm
   Time complexity - O(N^3)
   Space complexity- O(N*N)
*/
class Solution {
    public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        //adjacency matrix
        vector<vector<int>> floyd(n,vector<int>(n,1e9));
        for(auto it:edges)
        {
            floyd[it[0]][it[1]]=it[2];
            floyd[it[1]][it[0]]=it[2];
        }
        
        //floyd warshall
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                floyd[i][j]=min(floyd[i][j],floyd[i][via]+floyd[via][j]);
            }
        }
        
        int node=-1;
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                if(floyd[i][j]<=distanceThreshold)
                cnt++;
            }
            
            if(cnt<mini)
            {
                mini=cnt;
                node=i;
            }
            else if(cnt==mini)
            node=max(node,i);
        }
        return node;
    }
};

/* Method - 2
   Dijkstra Algorithm
   Time complexity - O (N*(V+ElogV)) 
   Space complexity- O((N*N)+(N+N))
*/
typedef pair<int,int> pi;
class Solution {
    public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        //adjacency list
        vector<pi> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //Dijkstra Algorithm
        int node=-1;
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
            priority_queue<pi,vector<pi>,greater<pi>> pq;
            vector<int> dis(n,1e9);
            dis[i]=0;
            pq.push({0,i});
            while(!pq.empty())
            {
                auto it=pq.top();
                pq.pop();
                
                int node=it.second;
                int dst=it.first;
                
                for(auto x:adj[node])
                {
                   int temp=dst+x.second;
                   if(dis[x.first]>temp)
                   {
                       dis[x.first]=temp;
                       pq.push({temp,x.first});
                   }
                }
            }
            
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                if(dis[j]<=distanceThreshold)
                cnt++;
            }
            
            if(cnt<mini)
            {
                mini=cnt;
                node=i;
            }
            else if(mini==cnt)
            node=max(node,i);
        }
        return node;
    }
};