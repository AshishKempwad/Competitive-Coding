#include <bits/stdc++.h>
using namespace std;


int BP(string s,int i,int j,char isTrue)
{
    if(i>j)
    {
        return 0;
    }
    
    if(i==j)
    {
        if(isTrue=='T')
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
    }
    
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt=BP(s,i,k-1,'T');
        int lf=BP(s,i,k-1,'F');
        int rt=BP(s,k+1,j,'T');
        int rf=BP(s,k+1,j,'F');
        
        
        if(s[k]=='|')
        {
            if(isTrue=='T')
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
            if(isTrue=='T')
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
            if(isTrue=='T')
            {
                ans+=lt*rf+lf*rt;
            }
            else
            {
                ans+=lt*rt+lf*rf;
            }
        }
    }
    
    return ans%1003;
    
    
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
        
        cout<<BP(s,0,n-1,'T')<<endl;
    }
	return 0;
}
