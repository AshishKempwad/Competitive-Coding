void dfs(int A[SIZE][SIZE],int N,int M,bool vis[SIZE][SIZE],int &count,int i,int j)
{
    int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};
    
    vis[i][j]=1;
    
    for(int k=0;k<8;k++)
    {
        int newi = i+dx[k];
        int newj = j+dy[k];
        if(newi>=0 && newi<N && newj>=0 && newj<M && vis[newi][newj]==0 && A[newi][newj]==1)
        {
            count++;
            
            dfs(A,N,M,vis,count,newi,newj);
        }
    }
}

int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    bool vis[SIZE][SIZE];
    memset(vis,0,sizeof(vis));
    
    int result = INT_MIN;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j]==1 && vis[i][j]==0)
            {
                int count=1;
                dfs(A,N,M,vis,count,i,j);
                result = max(result,count);
                
            }
        }
    }
    
    return result;
   
}
