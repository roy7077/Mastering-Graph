class Solution {
public:
    
    bool bfs(int nodee,vector<int>& colour,vector<int>* adj)
    {
        queue<int> q;
	    q.push(nodee);
	    colour[nodee]=1;
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        int cl;
	        if(colour[node])
	        cl=0;
	        else
	        cl=1;
	        
	        q.pop();
	        
	        for(auto x:adj[node])
	        {
	            if(colour[x]!=-1)
	            {
	                if(colour[x]!=cl)
	                return 0;
	            }
	            else
	            {
	                colour[x]=cl;
	                q.push(x);
	            }
	        }
	    }
	    
	    return 1;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> colour(V+1,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(colour[i]==-1)
	        {
	            if(!bfs(i,colour,adj))
	            return false;
	        }
	    }
	    
	    return true;
	    
	}

};