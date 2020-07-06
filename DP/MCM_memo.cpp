#include <bits/stdc++.h>
using namespace std;

int dp[501][501];


int MCM(int arr[],int i,int j)
{
    
    if(i>=j)
    {
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int mn = INT_MAX;
    
    for(int k=i;k<j;k++)
    {
        int temp = MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        mn = min(mn,temp);
    }
    
    return dp[i][j]=mn;
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
	    
	    memset(dp,-1,sizeof(dp));
	    cout<<MCM(arr,1,n-1)<<endl;
	    
	}
	return 0;
}
