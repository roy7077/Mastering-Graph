class Solution
{
	public:
	
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node,vector<int>* adj,vector<int>& visited,stack<int>& st)
	{
	    visited[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!visited[it])
	        dfs(it,adj,visited,st);
	    }
	    
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    stack<int> st;
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        dfs(i,adj,visited,st);
	    }
	    
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};