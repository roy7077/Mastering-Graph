class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> pq;
        
        /* pushing all the level 1 oranges to a queue*/
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                pq.push({{i,j},0});
            }
        }
        
        int t=0;
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};
        
        while(!pq.empty())
        {
            auto it=pq.front();
            int row=it.first.first;
            int col=it.first.second;
            int tt=it.second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int r=row+delrow[i];
                int c=col+delcol[i];
                
                if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1)
                {
                    grid[r][c]=2;
                    pq.push({{r,c},tt+1});
                    
                    t=max(tt+1,t);
                }
            }
        }
        
        /* check is there any fresh oranges where we cannot reach */
        for(auto it:grid)
        {
            for(auto x:it)
            {
                if(x==1)
                return -1;
            }
        }
        
        return t;
    }
};