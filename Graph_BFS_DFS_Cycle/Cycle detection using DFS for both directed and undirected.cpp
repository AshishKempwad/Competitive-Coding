bool DFSrec(vector<int> adj[],vector<bool>&vis,vector<bool>&Recst,int start)
{
    vis[start]=1;
    Recst[start]=1;    //recursion stack
    
    for(auto x: adj[start])
    {
        if(vis[x]==0 && DFSrec(adj,vis,Recst,x)==true)
        {
            return true;
        }
        else if(Recst[x]==true)
        {
            return true;
        }
    }
    
    Recst[start]=0;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    
    vector<bool>vis(V,0);
    vector<bool>Recst(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            if(DFSrec(adj,vis,Recst,i)==true)
            {
                return true; //cycle exists
            }
        }
    }
    
    return false; //cycle doesnt exist
    // Your code here
}
