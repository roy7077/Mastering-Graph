// Time complexity - O(Number of nodes)
// Space complexity- O(N+N+N)
class Solution
{
	public:
	void dfs1(vector<vector<int>>& adj,int node,vector<int>& visited,stack<int>& st)
	{
	    visited[node]=1;
	    for(auto it:adj[node])
	    {
	        if(visited[it]==0)
	        dfs1(adj,it,visited,st);
	    }
	    st.push(node);
	}
	void dfs2(vector<vector<int>>& adj,int node,vector<int>& visited)
	{
	    visited[node]=1;
	    for(auto it:adj[node])
	    {
	        if(visited[it]==0)
	        dfs2(adj,it,visited);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // step - 1 (finishing time)
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            dfs1(adj,i,visited,st);
        }
        
        // step - 2 (reversing the edges)
        vector<vector<int>> adj2(V);
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto it:adj[i])
            adj2[it].push_back(i);
        }
    
        // step - 3 (dfs on reverse graphs)
        int cnt=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            if(visited[node])
            continue;
            
            dfs2(adj2,node,visited);
            cnt++;
        }
        return cnt;
    }
};