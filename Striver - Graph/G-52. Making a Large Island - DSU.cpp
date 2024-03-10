int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};

class DisjointSetSize{
    public:
    vector<int> size;
    vector<int> parent;
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
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        //step 1 , connects all 1's
        DisjointSetSize ds(n*m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    for(int k=0;k<4;k++)
                    {
                        int r=i+x[k];
                        int c=j+y[k];
                        if(r>=0 and c>=0 and r<n and c<m and grid[r][c])
                        ds.unionBySize(i*n+j,r*n+c);
                    }
                }
            }
        }
        
        //find maximum
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int> st;
                    for(int k=0;k<4;k++)
                    {
                        int r=i+x[k];
                        int c=j+y[k];
                        
                        if(r>=0 and c>=0 and r<n and c<m and grid[r][c])
                        st.insert(ds.findUPar(r*m+c));
                    }
                    int cnt=1;
                    for(auto it:st)
                    cnt+=ds.size[it];
                    
                    maxi=max(maxi,cnt);
                }
            }
        }
        
        //3rd step
        for(int i=0;i<n*m;i++)
        maxi=max(maxi,ds.size[ds.findUPar(i)]);
        
        return maxi;
    }
};
