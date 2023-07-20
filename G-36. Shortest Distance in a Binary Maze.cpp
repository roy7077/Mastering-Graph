class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,pair<int, int> dis) 
    {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        
        int n=grid.size();
        int m=grid[0].size();
        
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        
        q.push({{s.first,s.second},0});
        visited[s.first][s.second]=1;
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int r=it.first.first;
            int c=it.first.second;
            int d=it.second;
            
            if(dis.first==r and dis.second==c)
            return d;
            
            for(int i=0;i<4;i++)
            {
                int delrow=r+x[i];
                int delcol=c+y[i];
                
                if(delrow>=0 and delrow<n and delcol>=0 and delcol<m and visited[delrow][delcol]==0 and grid[delrow][delcol]!=0)
                {
                    visited[delrow][delcol]=1;
                    q.push({{delrow,delcol},d+1});
                }
            }
        }
        
        return -1;
    }
};