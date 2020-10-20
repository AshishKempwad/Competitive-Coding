ll FindMaxSum(ll arr[], ll n)
{
    // if(n==0)
    // {
    //     return 0;
    // }
    
    // if(n==1)
    // {
    //     return arr[0];
    // }
    // if(n==2)
    // {
    //     return max(arr[0],arr[1]);
    // }
    
    long long dp[n+1];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    
    for(long long i=2;i<n;i++)
    {
       dp[i]=max(dp[i-2]+arr[i],dp[i-1]);    
    }
    
    return dp[n-1];
    // Your code here
}
