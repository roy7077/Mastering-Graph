class Solution
{
    public:
    int findPar(int node,int par[]){
        
       if(par[node] == node) 
       return (node);
       return par[node] = findPar(par[node],par);
   }
   
   //Function to merge two nodes a and b.
   void union_( int a, int b, int par[], int rank1[]) 
   {
       int u = findPar(a,par);
       int v = findPar(b,par);
       
       if(rank1[u] < rank1[v]){
           par[u] = v;
       }
       else if(rank1[v] < rank1[u]){
           par[v] = u;
       }
       else{
           par[v] = u;
           rank1[u]++;
       }
   }
   
   //Function to check whether 2 nodes are connected or not.
   bool isConnected(int x,int y, int par[], int rank1[]){
       return findPar(x,par) == findPar(y,par);
   }
};
