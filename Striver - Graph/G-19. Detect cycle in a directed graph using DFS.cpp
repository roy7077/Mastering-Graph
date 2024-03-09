class Solution {
  public:
    bool detectcycle(vector<int>& visited,vector<int>& path,vector<int> adj[],int node)
    {
        visited[node]=1;
        path[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                bool ans=detectcycle(visited,path,adj,it);
                if(ans==true)
                return true;
            }else
            {
                if(path[it]==1)
                return true;
            }
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> visited(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectcycle(visited,path,adj,i))
                return true;
            }
        }
        return false;
    }
};