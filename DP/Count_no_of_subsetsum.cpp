#include <bits/stdc++.h>
using namespace std;

int findCnt(int arr[],int sum,int n)
{
    int dp[n+1][sum+1];
    int count=0;
    for(int i=0;i<n;i++)  //for corner case
    {
        if(arr[i]==0)
        {
            count++;
        }
    }
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = pow(2,count);
    }
    
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][sum];
}


int main() 
{ 
	int arr[] = { 3, 3, 0, 0 }; 
	int n = sizeof(arr) / sizeof(int); 
	int sum= 0; 
	cout << findCnt(arr, sum, n); 
	return 0; 
} 
