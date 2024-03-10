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

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        vector<int> adj[n];
        for(auto it:edge)
        adj[it[0]].push_back(it[1]);
        
        DisjointSetSize ds(n);
        int extraEdge=0;
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                if(ds.findUPar(i)==ds.findUPar(it))
                extraEdge++;
                else
                ds.unionBySize(i,it);
            }
        }
        
        int disConnected=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i)
            disConnected++;
        }
        
        if(extraEdge>=disConnected-1)
        return disConnected-1;
        else
        return -1;
    }
};