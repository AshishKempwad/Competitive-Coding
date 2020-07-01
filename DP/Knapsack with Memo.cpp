vector<vector<int>> dp;

int ks(int W, int wt[], int val[], int n)
{
     if(W==0)
    {
        return 0;
    }
    if(n==0)
    {
        return 0;
    }
    
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    
    if(wt[n-1] <= W)
    {
        dp[n][W] = max(val[n-1]+ks(W-wt[n-1],wt,val,n-1), ks(W,wt,val,n-1));
        return dp[n][W];
    }
    else
    {
        dp[n][W] = ks(W,wt,val,n-1);
        return dp[n][W];
    }
    
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    if(W==0)
    {
        return 0;
    }
    if(n==0)
    {
        return 0;
    }
    dp.resize(n+2,vector<int>(W+2,-1));
    return ks(W,wt,val,n);
    
   // Your code here
}
