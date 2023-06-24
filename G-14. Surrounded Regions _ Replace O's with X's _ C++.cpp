class Solution{
public:

    void dfs(vector<vector<char>>& mat,int row,int col,vector<vector<char>>& copy)
    {
        copy[row][col]='1';
        
        int n=mat.size();
        int m=mat[0].size();
        int delrow[]={1,-1,0,0};
        int delcol[]={0,0,1,-1};
        
        for(int i=0;i<4;i++)
        {
            int r=row+delrow[i];
            int c=col+delcol[i];
            
            if(r>=0 and r<n and c>=0 and c<m and mat[r][c]=='O' and copy[r][c]=='O')
            dfs(mat,r,c,copy);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> copy=mat;
        
        //1st row and last row
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O' and copy[0][i]=='O')
            dfs(mat,0,i,copy);
            
            if(mat[n-1][i]=='O' and copy[n-1][i]=='O')
            dfs(mat,n-1,i,copy);
        }
        
        //1st col and last col
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O' and copy[i][0]=='O')
            dfs(mat,i,0,copy);
            
            if(mat[i][m-1]=='O' and copy[i][m-1]=='O')
            dfs(mat,i,m-1,copy);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(copy[i][j]=='1')
                copy[i][j]='O';
                else
                copy[i][j]='X';
            }
        }

       return copy;
    }
};