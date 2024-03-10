// DisJoint Set by Rank
#include <iostream>
#include <vector>
using namespace std;

class DisjointSetRank{
    vector<int> rank;
    vector<int> parent;
    
    public:
    DisjointSetRank(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v)
        return ;
        
        if(rank[ulp_u]<rank[ulp_v])
        parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
        parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};


int main() {
	DisjointSetRank ds(7);
	
	ds.unionByRank(1,2);
	ds.unionByRank(2,3);
	ds.unionByRank(4,5);
	ds.unionByRank(6,7);
	ds.unionByRank(5,6);
	
// 	if(ds.findUPar(3)==ds.findUPar(7))
// 	cout<<"same"<<endl;
// 	else
// 	cout<<"NOt same"<<endl;
	
// 	ds.unionByRank(3,7);
// 	if(ds.findUPar(3)==ds.findUPar(7))
// 	cout<<"same"<<endl;
// 	else
// 	cout<<"NOt same"<<endl;
	return 0;
}



//Disjoint Set by size
#include <iostream>
#include <vector>
using namespace std;

class DisjointSetSize{
    vector<int> size;
    vector<int> parent;
    
    public:
    DisjointSetSize(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v)
        return ;
        
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main() {
	DisjointSetSize ds(7);
	
	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);
	ds.unionBySize(5,6);
	
// 	if(ds.findUPar(3)==ds.findUPar(7))
// 	cout<<"same"<<endl;
// 	else
// 	cout<<"NOt same"<<endl;
	
// 	ds.unionBySize(3,7);
// 	if(ds.findUPar(3)==ds.findUPar(7))
// 	cout<<"same"<<endl;
// 	else
// 	cout<<"NOt same"<<endl;
	return 0;
}
