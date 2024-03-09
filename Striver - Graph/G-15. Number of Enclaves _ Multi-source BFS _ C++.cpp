class Solution {
  public:
  
    void dfs(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &copy)
    {
        copy[row][col]=0;
        int n=grid.size();
        int m=grid[0].size();
        
        int delrow[]={1,-1,0,0};
        int delcol[]={0,0,1,-1};
        
        for(int i=0;i<4;i++)
        {
            int r=row+delrow[i];
            int c=col+delcol[i];
            
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1 and copy[r][c]==1)
            dfs(grid,r,c,copy);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        vector<vector<int>> copy=grid;
        int n=grid.size();
        int m=grid[0].size();
        
        //for first row and last row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 and copy[0][i]==1)
            dfs(grid,0,i,copy);
            
            if(grid[n-1][i]==1 and copy[n-1][i]==1)
            dfs(grid,n-1,i,copy);
        }
        
        //for 1st col and last col
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 and copy[i][0]==1)
            dfs(grid,i,0,copy);
            
            if(grid[i][m-1]==1 and copy[i][m-1]==1)
            dfs(grid,i,m-1,copy);
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(copy[i][j]==0 and grid[i][j]==1)
                grid[i][j]=0;
                
                if(grid[i][j])
                cnt++;
            }
        }
        return cnt;
        
    }
};