/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void dfs(vector<int> A[],int x,int y, int N, int M)
{
   A[x][y]=2;
   int newx;
   int newy;
   for(int i=0;i<8;i++)
   {
       newx = x + dx[i];
       newy = y + dy[i];
       
       if(newx>=0 && newx<N && newy>=0 && newy<M && A[newx][newy]==1)
       {
           dfs(A,newx,newy,N,M);
       }
   }
    
}


int findIslands(vector<int> A[], int N, int M) 
{
 
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int x = A[i][j];
            if(A[i][j]==1)
            {
                dfs(A,i,j,N,M);
                count++;
            }
        }
    }
   
   return count;
    // Your code here
}
