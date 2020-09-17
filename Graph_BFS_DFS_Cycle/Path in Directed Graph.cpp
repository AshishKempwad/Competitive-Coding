bool findpath(int A,int node,vector<bool>&vis,vector<vector<int>>&graph)
{
    if(node == A)
    {
        return true;
    }
    if(!vis[node])
    {
        vis[node]=true;
        for(auto x : graph[node])
        {
            if(findpath(A,x,vis,graph))
            {
                return true;
            }
        }
    }
    
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<bool>vis(A+1,false);
    vector<vector<int>>graph(A+1);
    
    for(auto x: B)
    {
        graph[x[0]].push_back(x[1]);
    }
    
    if(findpath(A,1,vis,graph))
    {
        return 1;
    }
    return 0;
}
