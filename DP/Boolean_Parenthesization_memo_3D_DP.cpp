#include <bits/stdc++.h>
using namespace std;

int dp[201][201][3];

int BP(string s,int i,int j,int isTrue)
{
    if(i>j)
    {
        return dp[i][j][isTrue]=0;
    }
    
    if(i==j)
    {
        if(isTrue==1)
        {
            if(s[i]=='T')
            {
                dp[i][j][isTrue]=1;
            }
            else
            {
                dp[i][j][isTrue]=0;
            }
        }
        else
        {
            if(s[i]=='F')
            {
                dp[i][j][isTrue]=1;
            }
            else
            {
                dp[i][j][isTrue]=0;
            }
        }
        
        return dp[i][j][isTrue];
    }
    
 
    
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt,lf,rt,rf;
        
        if(dp[i][k-1][1]!=-1)  //lt
        {
            lt=dp[i][k-1][1];
        }
        else
        {
            lt=BP(s,i,k-1,1);
            dp[i][k-1][1] = lt;
        }
        
        
        if(dp[i][k-1][0]!=-1)   //lf
        {
            lf=dp[i][k-1][0];
        }
        else
        {
            lf=BP(s,i,k-1,0);
            dp[i][k-1][0] = lf;
        }
        
        if(dp[k+1][j][1]!=-1)    //rt
        {
            rt=dp[k+1][j][1];
        }
        else
        {
            rt=BP(s,k+1,j,1);
            dp[k+1][j][1] = rt;
        }
        
         if(dp[k+1][j][0]!=-1)   //rf
        {
            rf=dp[k+1][j][0];
        }
        else
        {
            rf=BP(s,k+1,j,0);
            dp[k+1][j][0] = rf;
        }
        
        if(s[k]=='|')
        {
            if(isTrue==1)
            {
                ans+=lt*rt+lt*rf+lf*rt;
            }
            else
            {
                ans+=lf*rf;
            }
        }
        else if(s[k]=='&')
        {
            if(isTrue==1)
            {
                ans+=lt*rt;
            }
            else
            {
                ans+=lt*rf+lf*rt+lf*rf;
            }
        }
        else if(s[k]=='^')
        {
            if(isTrue==1)
            {
                ans+=lt*rf+lf*rt;
            }
            else
            {
                ans+=lt*rt+lf*rf;
            }
        }
    }
    
    return dp[i][j][isTrue]=ans%1003;
    
    
}


int main() 
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<BP(s,0,n-1,1)<<endl;
    }
	return 0;
}
