/*
Given a square matrix filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. 
You can traverse up, down, right and left. (Check Your Task for more details).
You have to start from the Source, traverse through the blank cells and reach the Destination. You can move Up, Down, Right and Left. The description of cells is as follows:

    A value of cell 1 means Source.
    A value of cell 2 means Destination.
    A value of cell 3 means Blank cell.
    A value of cell 0 means Wal





*/
bool is_possible(vector <vector <int>> &M, int N)
{
    vector<vector<bool>> vis(N,vector<bool>(N,false));
    // bool vis[MAX][MAX];
    // memset(vis,false,sizeof(vis));
    queue<pair<int,int>>q;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(M[i][j]==1)
            {
                vis[i][j]=1;
                q.push({i,j});
                break;
            }
        }
    }
    
    if(q.empty())  // if no starting point,then theres no way to destination
    {
        return 0;
    }
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    while(!q.empty())
    {
       int x = q.front().first;
       int y = q.front().second;
       q.pop();
       
       for(int i=0;i<4;i++)
       {
           int newx=x+dx[i];
           int newy=y+dy[i];
           
           if(newx >=0 && newx<N && newy >=0 && newy<N && M[newx][newy]==2)
           {
               return 1;
           }
           
           if(newx >=0 && newx<N && newy >=0 && newy<N && M[newx][newy]==3 && vis[newx][newy]==0) //space to move ahead
           {
               vis[newx][newy]=1;
               q.push({newx,newy});
           }
       }
    }
    
    return 0;
    
}
