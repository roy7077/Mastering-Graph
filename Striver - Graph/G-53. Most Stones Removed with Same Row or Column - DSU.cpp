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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones)
        {
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        
        DisjointSetSize ds(maxRow+maxCol+1);
        unordered_map<int,int> stonesNodes;
        for(auto it:stones)
        {
            int r=it[0];
            int c=it[1]+maxRow+1;
            ds.unionBySize(r,c);
            stonesNodes[r]=1;
            stonesNodes[c]=1;
        }
        
        int cnt=0;
        for(auto it:stonesNodes)
        {
            if(ds.findUPar(it.first)==it.first)
            cnt++;
        }
        return n-cnt;
    }
};