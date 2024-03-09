class Solution {
public:
    
    bool dfs(int node,vector<int>* adj,vector<int>& colour)
    {
        int cl=(!colour[node]);
        
        for(auto x:adj[node])
        {
            if(colour[x]!=-1)
            {
                if(colour[x]!=cl)
                return false;
            }
            else
            {
                colour[x]=cl;
                bool ans=dfs(x,adj,colour);
                if(!ans)
                return false;
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> colour(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(colour[i]==-1)
	        {
	            if(!dfs(i,adj,colour))
	            return false;
	        }
	    }
	    
	    return true;
	}

};