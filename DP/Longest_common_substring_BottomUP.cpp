	  

#include <bits/stdc++.h>
using namespace std;

int LCSubstring(char *X,char *Y,int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    
    int res = INT_MIN;
     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            res = max(res,dp[i][j]);
        }
    }
    
    return res;
    
}



int main() 
{
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int n,m;
	    cin>>n>>m;
	    char X[n];
	    char Y[m];
	   // cin.get(X,n);
	   // cin.get(Y,m);
	    for(int i=0;i<n;i++)
	    {
	        cin>>X[i];
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin>>Y[i];
	    }
	    
	    cout<<LCSubstring(X,Y,n,m)<<endl;
	    
	}
	return 0;
}
