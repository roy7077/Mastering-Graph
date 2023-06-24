class Solution {
  public:
  
    void dfs(vector<vector<int>>& grid,int row,int col,int baserow,int basecol,vector<vector<int>>& copy,vector<pair<int,int>>& p)
    {
        copy[row][col]=0;
        p.push_back({baserow-row,basecol-col});
        
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        
        for(int i=0;i<4;i++)
        {
            int r=row+delrow[i];
            int c=col+delcol[i];
            
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1 and copy[r][c]==1)
            dfs(grid,r,c,baserow,basecol,copy,p);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> copy=grid;
        
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and copy[i][j]==1)
                {
                    vector<pair<int,int>> p;
                    dfs(grid,i,j,i,j,copy,p);
                    
                    st.insert(p);
                }
                
            }
        }
        
        return st.size();
    }
};