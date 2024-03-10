/* Method - 1 
   Prim's Algorithm
   Time complexity - O(ElogE)
   Space complexity- O(E)
*/
typedef pair<int,int> pi;
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {

        //Prim's algorithm
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> visited(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int wt=it.first;
            int node=it.second;
        
            if(visited[node])
            continue;
            
            visited[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            {
                if(!visited[it[0]])
                pq.push({it[1],it[0]});
            }
        }
        return sum;
    }
};

/* Method - 2 
   DisJoint set
   Kruskal's Algorithm
*/
class DisjointSetSize{
    vector<int> size;
    vector<int> parent;
    
    public:
    DisjointSetSize(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v)
        return ;
        
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

typedef pair<int,pair<int,int>> pi;
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pi> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            edges.push_back({it[1],{i,it[0]}});
        }
        
        sort(edges.begin(),edges.end());
        DisjointSetSize ds(V);
        int sum=0;
        for(auto it:edges)
        {
            if(ds.findUPar(it.second.first)!=ds.findUPar(it.second.second))
            {
                sum+=it.first;
                ds.unionBySize(it.second.first,it.second.second);
            }
        }
        return sum;
    }
};