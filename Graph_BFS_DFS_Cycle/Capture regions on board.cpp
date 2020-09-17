int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};



void dfs(int x, int y, int n, int m, vector<vector<char> > &A)
{
    A[x][y] = '#';
    
    for(int i=0;i<4;i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        
        if(newx >= 0 && newx < n && newy >=0 && newy < m && A[newx][newy]=='O')
        {
            dfs(newx,newy,n,m,A);
        }
    }
}



void Solution::solve(vector<vector<char> > &A) 
{
   int n = A.size();
   int m = A[0].size();
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if( (i==0 || j == 0 || i == n-1 || j == m-1 ) && A[i][j] == 'O')
           {
               dfs(i,j,n,m,A);
           }
       }
   }
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
          if(A[i][j] == '#')
          {
              A[i][j]='O';
          }
          else
          {
              A[i][j] = 'X';
          }
       }
   } 
}
