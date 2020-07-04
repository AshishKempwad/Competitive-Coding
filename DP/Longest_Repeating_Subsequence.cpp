#include <bits/stdc++.h>
using namespace std;

int LRS(string s1,string s2,int n,int m)
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
           if(s1[i-1]==s2[j-1] && i!=j)   // i!=j this is the only extra condition we add here, rest is normal LCS code
           {
               dp[i][j] = 1+dp[i-1][j-1];
           }
           else
           {
               dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
           }
       }
   }
   
  
   return dp[n][m];
   
}


int main()
{
   int testcases;
   cin>>testcases;
   
   while(testcases--)
   {
       int n;
       cin>>n;
       string s1;
       cin>>s1;
       
       string s2 = s1;
       int m=n;
       cout<<LRS(s1,s2,n,m)<<endl;
       
   }
	return 0;
}
