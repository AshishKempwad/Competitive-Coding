int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    
    queue<pair<int,int>>q;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]==2)
            {
                q.push({i,j});
            }
        }
    }
    
    if(q.empty())
    {
        return -1;
    }
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int timer=-1;
    
    while(!q.empty())
    {
        int z = q.size();
        while(z--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    int newx = x+dx[i];
                    int newy = y+dy[i];
                    
                    if(newx>=0 && newx<R && newy>=0 && newy<C && matrix[newx][newy]==1)
                    {
                        matrix[newx][newy]=2;
                        q.push({newx,newy});
                    }
                }
            }
        }
        
        timer++;
    }
    
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]==1)
            {
                return -1;
            }
        }
    }
    
    return timer;
    
    // Your code goes here
}
