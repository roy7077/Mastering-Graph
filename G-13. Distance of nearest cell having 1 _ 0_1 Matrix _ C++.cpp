class Solution 
{
    public:
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    
	    vector<vector<int>> temp=grid;
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,int>> q;
	    
	    /* pushing all ones to our queue */
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            q.push({{i,j},0});
	        }
	    }
	    
	    int delrow[]={1,-1,0,0};
	    int delcol[]={0,0,1,-1};
	    while(!q.empty())
	    {
	        auto it=q.front();
	        int row=it.first.first;
	        int col=it.first.second;
	        int step=it.second;
	        q.pop();
	        
	        for(int i=0;i<4;i++)
	        {
	            int r=row+delrow[i];
	            int c=col+delcol[i];
	            
	            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==0)
	            {
	                grid[r][c]=step+1;
	                q.push({{r,c},step+1});
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(temp[i][j]==1)
	            grid[i][j]=0;
	        }
	    }
	    
	    return grid;
	}
};