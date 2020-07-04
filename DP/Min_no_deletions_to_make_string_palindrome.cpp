#include <bits/stdc++.h>
using namespace std;



int min_ins(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();
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
           if(s1[i-1]==s2[j-1])
           {
               dp[i][j] = 1+dp[i-1][j-1];
           }
           else
           {
               dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
           }
       }
   }
   
   int LCS = dp[n][m];
   int res = n - LCS;
   return res;
   
}



int main() 
{
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
       
        string s1;
        cin>>s1;
        
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        
        cout<<min_ins(s1,s2)<<endl;
    }
	return 0;
}
