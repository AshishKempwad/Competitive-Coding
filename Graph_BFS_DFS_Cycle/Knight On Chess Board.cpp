int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    if(C == E && D==F)
    {
        return 0;
    }
    vector<vector<bool>>vis(A+1,vector<bool>(B+1,0));
    vis[C][D]=1;
    
    queue<pair<int,int>>q;
    
    q.push({C,D});
    int count=0;
    
    while(!q.empty())
    {
        int n = q.size();
        
        for(int i=0;i<n;i++)
        {
            pair<int,int>temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            
            for(int i=0;i<8;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx > 0 && newx <= A && newy > 0 && newy <= B && vis[newx][newy]==0)
                {
                    if(newx == E && newy == F)
                    {
                        return count+1;
                    }
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        
        count++;
    }
    
    return -1;  
}
