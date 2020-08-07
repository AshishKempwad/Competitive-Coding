bool dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&recst,int start)
{
    vis[start]=1;
    recst[start]=1;
        
     for(auto x : adj[start])
     {
        if(!vis[x] && dfs(adj,vis,recst,x)==true)
        {
            return true;
        }
        else if(recst[x]==true)
        {
            return true;
        }
     }
     
       recst[start]=0;
        return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C)
{
    vector<vector<int>>adj(A+1,vector<int>());
    int n = B.size();
    
    for(int i=0;i<n;i++)
    {
        adj[B[i]].push_back(C[i]);
    }
    
    vector<bool>vis(A+1,false);
    vector<bool>recst(A+1,false);    //recursion stack
    
    for(int i=0;i<=A;i++)
    {
        if(!vis[i])
        {
            if(dfs(adj,vis,recst,i)==true)
            {
                return 0;    //cannot take the course
            }
        }
    }
    
    return 1;   //no cycle hence, can take the course
}
