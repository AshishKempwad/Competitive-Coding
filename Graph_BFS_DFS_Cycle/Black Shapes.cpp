int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
void dfs(vector<string> &A,int x,int y,int n,int m)
{
   A[x][y]='N';
   
   for(int i=0;i<4;i++)
   {
       int newx = x + dx[i];
       int newy = y + dy[i];
       
       if(newx >=0 && newx < n && newy >= 0 && newy < m && A[newx][newy]=='X')
       {
           dfs(A,newx,newy,n,m);
       }
       
   }
}


int Solution::black(vector<string> &A)
{
    int count = 0;
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='X')
            {
                dfs(A,i,j,n,m);
                count++;
            }
        }
    }
    
    return count;
    
    
}
