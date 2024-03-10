// Using disJoint set
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSetSize ds(n*m);
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> ans(operators.size(),0);
        int cnt=0;
        for(int i=0;i<operators.size();i++)
        {
            int row=operators[i][0];
            int col=operators[i][1];
            int node1=row*m+col;
            if(visited[row][col])
            {
                ans[i]=cnt;
                continue;
            }
            
            visited[row][col]=1;
            cnt++;
            for(int k=0;k<4;k++)
            {
                int delr=row+x[k];
                int delc=col+y[k];
            
                if(delr>=0 and delc>=0 and delr<n and delc<m and visited[delr][delc]==1)
                {
                    int node2=delr*m+delc;
                    if(ds.findUPar(node1)!=ds.findUPar(node2))
                    {
                        cnt--;
                        ds.unionBySize(node1,node2);
                    }
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};