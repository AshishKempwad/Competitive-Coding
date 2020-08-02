vector <int> bfs(vector<int> g[], int N) 
{
    vector<int>bfs_ans;
    
    bool vis[N+1];
    memset(vis,0,sizeof(vis));
    queue<int>q;
    int start = 0;
    q.push(start);
    vis[0]=1;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        bfs_ans.push_back(u);
        
        for(auto x : g[u])
        {
            if(vis[x]==0)
            {
                vis[x]=1;
                q.push(x);
            }
        }
    }
    
return bfs_ans;
    // Your code here
}
