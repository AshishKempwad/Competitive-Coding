#include <bits/stdc++.h>
using namespace std;

// int arr[55];


int subsetsum(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i] = false;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int diff = INT_MAX;
    
    for(int j=sum/2; j>=0;j--)
    {
        if(dp[n][j] == true)
        {
            diff = sum - 2*j;  // range - 2S1;
            break;
        }
    }
    
    return diff;
}


int main() 
{
    
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
        }
        // sum = accumulate(arr,arr+n,sum);
        
        cout<<subsetsum(arr,n,sum)<<endl;
    }
	return 0;
}
