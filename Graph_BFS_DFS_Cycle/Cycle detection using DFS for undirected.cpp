bool DFSrec(vector<int> adj[],vector<bool>&vis,int start,int parent)
{
    vis[start]=1;
    for(auto x: adj[start])
    {
        if(vis[x]==0)
        {
            if( DFSrec(adj,vis,x,start)==true)
            {
               return true;
            }
        }
        else if(x!=parent)
        {
            return true;
        }
    }

    return false;
}


bool isCyclic(vector<int> adj[],int V)
{
    
    vector<bool>vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            if(DFSrec(adj,vis,i,-1)==true)
            {
                return true; //cycle exists
            }
        }
    }
    
    return false; //cycle doesnt exist
    // Your code here
}
