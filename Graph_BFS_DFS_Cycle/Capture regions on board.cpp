/*
Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints

1 <= N, M <= 103


Input Format

First and only argument 2D character matrix A of size N X M.


Output Format

Make changes to the the input only as matrix is passed by reference.


Example Input

Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]



Example Output

Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]



Example Explanation

Explanation 1:

 'O' in (4,2) is not surrounded by X from below.



*/
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
