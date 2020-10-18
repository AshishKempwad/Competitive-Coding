class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    int n = s.length();
		    int m = t.length();
		    
		  //  if(n==0)  //if 's' is NULL, we need 'm' insert operations to make it 't'
		  //  {
		  //      return m;
		  //  }
		  //  if(m==0)  //if 't' is NULL, we need 'n' delete operations on 's' to make it equal to 't'
		  //  {
		  //      return n;
		  //  }
		    
		    int dp[n+1][m+1];
		    
		    for(int i=0;i<=n;i++)
		    {
		        dp[i][0]=i;
		    }
		    
		    for(int i=0;i<=m;i++)
		    {
		        dp[0][i]=i;
		    }
		    
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=m;j++)
		        {
		            if(s[i-1]==t[j-1])
		            {
		                dp[i][j] = dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
		            }
		        }
		    }
		    
		    return dp[n][m];
		}
};
