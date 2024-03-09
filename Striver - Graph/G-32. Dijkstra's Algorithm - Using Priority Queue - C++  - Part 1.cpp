class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(V,1e9);
        dis[S]=0;
        
        pq.push({0,S});
        
        while(!pq.empty())
        {
           auto it=pq.top();
           pq.pop();
           
           int d=it.first;
           int node=it.second;
           
           for(auto it:adj[node])
           {
               int d2=d+it[1];
               int node2=it[0];
               
               if(dis[node2]>d2)
               {
                   dis[node2]=d2;
                   pq.push({d2,node2});
               }
           }
        }
        return dis;
    }
};