//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i-x >= 0)
        {
            dp[i]=max(dp[i],dp[i-x]);
        }
        if(i-y>=0)
        {
            dp[i]=max(dp[i],dp[i-y]);
        }
        if(i-z>=0)
        {
            dp[i]=max(dp[i],dp[i-z]);
        }
        if(dp[i]!=-1)
        {
            dp[i]++;
        }
    }
    
    return  dp[n]!=-1 ?  dp[n] :  0;
    //Your code here
}
