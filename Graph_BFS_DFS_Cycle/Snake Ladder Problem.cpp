int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
    int min_moves = 0;
    
    unordered_map<int,int>mp;
    for(auto x: A)
    {
        mp[x[0]] = x[1];
    }
    for(auto x: B)
    {
        mp[x[0]] = x[1];
    }
    
    vector<bool>vis(101,false);
    queue<int>q;
    q.push(1);
    
    while(!q.empty())
    {
        int qsize = q.size();
        
        for(int i=0;i<qsize;i++)
        {
            int pos = q.front();
            q.pop();
            
            if(pos == 100)
            {
                return min_moves;
            }
            
            if(vis[pos]==false)
            {
                vis[pos]=true;
                
                for(int j=1;j<=6;j++)
                {
                    int loc = pos + j;
                    if(loc <= 100)
                    {
                        if(mp.find(loc) != mp.end())
                        {
                            loc = mp[loc];
                            
                        }
                        q.push(loc);
                    }
                    
                }
            }
            
        }
        
        min_moves++;
    }
    
    return -1;
    
}
