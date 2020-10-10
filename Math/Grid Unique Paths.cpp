/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)




*/


/*Method 1 :
  Recursive:
  TC = O(2^n)
  SC = O(2^n)
*/
int count_unique(int i,int j,int n,int m)
{
    if(i > n-1 || j > m-1)  //Base case
    {                       //Checking for out of bound
        return 0;
    }
    
    if( i== n-1 && j == m-1)  //Base case
    {                         //If we reach the destination we return 1
        return 1;
    }
    else
    {
        return count_unique(i+1,j,n,m) + count_unique(i,j+1,n,m);
    }
}



int Solution::uniquePaths(int A, int B) 
{
    int i=0;
    int j=0;
    int paths = count_unique(i,j,A,B);
    return paths;
}

------------------------------------------------------------------------------------------------------------------------------
/*
Method 2 :
DP

TC = O(m*n)
SC = O(m*n)

*/

int count_unique(int i,int j,int n,int m,vector<vector<int>>&dp)
{
    if(i > n-1 || j > m-1)  //Base case
    {                       //Checking for out of bound
        return 0;
    }
    
    if( i== n-1 && j == m-1)  //Base case
    {                         //If we reach the destination we return 1
        return 1;
    }
    else if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    return dp[i][j] = count_unique(i+1,j,n,m,dp) + count_unique(i,j+1,n,m,dp);
    
}



int Solution::uniquePaths(int A, int B) 
{
    int i=0;
    int j=0;
    vector<vector<int>>dp(A+1,vector<int>(B+1,-1));
    int paths = count_unique(i,j,A,B,dp);
    return paths;
}


----------------------------------------------------------------------------------------------------------------
/*
Method  :
Combinatrics

TC = O(m-1) or O(n-1)
SC = O(1)

*/

int Solution::uniquePaths(int A, int B) 
{
    
    //Best method : Solved by using combinatrics
    // Refer : https://www.youtube.com/watch?v=t_f0nwwdg5o
    
    int N = A + B -2;
    int r = A - 1;
    
    double res = 1;
    for(int i=1;i<=r;i++)
    {
        res = res * (N - r + i)/i;
    }
    return (int)res;
}
