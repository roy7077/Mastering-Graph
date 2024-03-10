// Method - 1 
// DFS
class Solution {
  public:
  
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    
    int numProvinces(vector<vector<int>> v, int V) {
        
        vector<int> adj[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(v[i][j]==1 and i!=j)
                adj[i].push_back(j);
            }
        }
        
        vector<int> visited(V,0);
        int cnt=0;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited);
                cnt++;
            }
        }
        
        return cnt;
        
    }
};

// Method - 2 
// By disjoint set
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
    int numProvinces(vector<vector<int>> Mat, int V) {
        
        //adj list
        vector<int> adj[V+1];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i==j)
                continue;
                
                if(Mat[i][j])
                adj[i+1].push_back(j+1);
            }
        }
        
        //counting
        DisjointSetSize ds(V+1);
        for(int i=1;i<=V;i++)
        {
            for(auto it:adj[i])
            ds.unionBySize(i,it);
        }
        
        int cnt=0;
        for(int i=1;i<=V;i++)
        {
            if(ds.findUPar(i)==i)
            cnt++;
        }
        
        return cnt;
    }
};