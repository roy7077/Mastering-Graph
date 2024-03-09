class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> indegree(N,0);
	    vector<int> adj[N];
	    vector<int> ans;
	    
	    for(auto it:prerequisites)
	    {
	        indegree[it[0]]++;
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        ans.push_back(node);
	        q.pop();
	        
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    
	    for(auto it:indegree)
	    {
	        if(it>=1)
	        return {};
	    }
	    
	    return ans;
    }
};