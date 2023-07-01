class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> indegree(N,0);
	    vector<int> adj[N];
	    
	    for(auto it:prerequisites)
	    {
	        indegree[it.second]++;
	        adj[it.first].push_back(it.second);
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
	        return 0;
	    }
	    
	    return 1;
	}
};