int Solution::numDistinct(string A, string B)
{
    int n = A.size();
    int m=B.size();
    
    int dp[n+1][m+1];
    
    dp[0][0]=1;  //we can create B of size 0 with A of size 0 without deleting anything
  
    for(int i=1;i<=n;i++) // if A is of size>1 and B=0, we can create such subsequence
    {
      dp[i][0]=1;   
    }
    
    for(int i=1;i<=m;i++)//If A is of size 0, we can create B by performing any number of deletions as there is nothing to delete in first place.
    {
        dp[0][i]=0;
    }
    
  
      
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j > i)
            {
                dp[i][j]=0;  //If B.size() > A.size(), we cannot create B from A
            }
            else
            {
                if(A[i-1]==B[j-1])  //if they match
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else  //if they dont match
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    
    return dp[n][m];
}
