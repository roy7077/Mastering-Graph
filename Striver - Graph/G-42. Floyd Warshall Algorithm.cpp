/* Floyd Warshall
   Time complexity - O(N^3)
   Space complexity- O(N*N)
*/
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(matrix[i][via]==-1 or matrix[via][j]==-1)
	                continue;
	                
	                int dis=matrix[i][via]+matrix[via][j];
	                if(matrix[i][j]==-1)
	                matrix[i][j]=dis;
	                else
	                matrix[i][j]=min(matrix[i][j],dis);
	            }
	        }
	    }
	}
};