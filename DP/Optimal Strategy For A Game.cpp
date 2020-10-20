
int dp[100][100];

int maxval(int arr[],int i,int j,int sum)
{
    if(j==i+1)
    {
        return max(arr[i],arr[j]);
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    dp[i][j] = max ( (sum - maxval(arr,i+1,j,sum-arr[i])) , (sum - maxval(arr,i,j-1,sum-arr[j]) ) );
    
    return dp[i][j];
    
}

long long maximumAmount(int arr[], int n) 
{
    if(n==1)
    {
        return arr[0];
    }
    
    if(n==2)
    {
        return max(arr[0],arr[1]);
    }
    
    int sum=0;
    sum = accumulate(arr,arr+n,sum);
    memset(dp,-1,sizeof(dp));
   
    return maxval(arr,0,n-1,sum);
    
}
