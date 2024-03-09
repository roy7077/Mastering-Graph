class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int delrow=r+i;
                    int delcol=c+j;
                    
                    if(delrow>=0 and delrow<n and delcol>=0 and delcol<m and grid[delrow][delcol]=='1' and visited[delrow][delcol]==0)
                    {
                        visited[delrow][delcol]=1;
                        q.push({delrow,delcol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 and grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        
        return cnt;
    }
};