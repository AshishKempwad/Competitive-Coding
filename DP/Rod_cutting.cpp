//Based on the idea of unbounded knapsack



#include <bits/stdc++.h>
using namespace std;

int rodcut(int n,int arr[],int price[])
{
    int dp[n+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = max(price[i-1]+dp[i][j-arr[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return dp[n][n];
}

int main() 
{
   int testcases;
   cin>>testcases;
   
   while(testcases--)
   {
       int length;
       cin>>length;
       
       int arr[length];
       for(int i=0;i<length;i++)
       {
           arr[i]=i+1;
       }
       int price[length];
       price[0]=0;
       for(int i=0;i<length;i++)
       {
           cin>>price[i];
       }
       
       cout<< rodcut(length,arr,price)<<endl;
       
   }
	return 0;
}
