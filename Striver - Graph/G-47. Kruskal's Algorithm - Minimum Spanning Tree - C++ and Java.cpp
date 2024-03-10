/* DisJoint set
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