class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        set<pair<int,int>> st;
        vector<int> dis(V,1e9);
        dis[S]=0;
        
        st.insert({0,S});
        while(!st.empty())
        {
            auto it=*(st.begin());
            int d=it.first;
            int node=it.second;
            
            st.erase({d,node});
            for(auto x:adj[node])
            {
                int d2=d+x[1];
                if(dis[x[0]]>d2)
                {
                    dis[x[0]]=d2;
                    st.insert({d2,x[0]});
                }
            }
        }
        
        return dis;
    }
};