class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        //reversing a graph 
        vector<int> Rev[V];
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                Rev[it].push_back(i);
            }
        }
        
        /*---------toposort-----(kahn's algorithm)---*/
        vector<int> indegree(V,0);
        for(auto it:Rev)
        {
            for(auto x:it)
            indegree[x]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:Rev[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};