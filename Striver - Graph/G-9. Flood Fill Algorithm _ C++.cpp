class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int row,int col,int oldcolor,int newcolor,vector<vector<int>>& ans,int* delrow,int* delcol)
    {
        ans[row][col]=newcolor;
        
        for(int i=0;i<=3;i++)
        {
            int r=row+delrow[i];
            int c=col+delcol[i];
            
            if(r>=0 and r<image.size() and c>=0 and c<image[0].size() and ans[r][c]==oldcolor and ans[r][c]!=newcolor)
            dfs(image,r,c,oldcolor,newcolor,ans,delrow,delcol);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};
        vector<vector<int>> ans=image;
        int oldcolor=image[sr][sc];
        dfs(image,sr,sc,oldcolor,newColor,ans,delrow,delcol);
        return ans;
    }
};
