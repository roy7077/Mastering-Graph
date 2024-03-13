// DisJoint Set by Rank
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class DisjointSetRank{
    vector<int> rank;
    vector<int> parent;
    
    public:
    DisjointSetRank(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v)
        return ;
        
        if(rank[ulp_u]<rank[ulp_v])
        parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
        parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};


class Solution
{
    public:
	int detectCycle(int V, vector<int>adj[])
	{
	    DisjointSetRank ds(V);
	    unordered_set<pair<int, int>,pair_hash> st;
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            if(st.count({min(i,it),max(i,it)}))
	            continue;
	            
	            st.insert({min(i,it),max(i,it)});
	            
	            int p1=ds.findUPar(i);
	            int p2=ds.findUPar(it);
	            
	            if(p1==p2)
	            return 1;
	            
	            ds.unionByRank(i,it);
	        }
	    }
	    return 0;
	}
};