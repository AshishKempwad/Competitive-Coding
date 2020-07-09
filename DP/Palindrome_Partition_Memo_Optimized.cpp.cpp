class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>>pal;
    
    int ispal(string s,int i,int j)
    {
        if(i>j)
        {
            return 1;
        }
        if(i==j)
        {
            return 1;
        }
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
               return 0;
            }
            else
            {
                i++;
                j--;
            }
        }
        
        return 1;
    }
    
    
    
    
    int PP(string s,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(pal[i][j]!=-1)
        {
            return pal[i][j];
        }
        
        if(ispal(s,i,j)==true)
        {
            pal[i][j]=1;     //it is a palindrome
            return 0;
        }
        else
        {
            pal[i][j]=0;   //not a palindrome
        }
        
        int mn=INT_MAX;
        int temp;
        int left,right;
        for(int k=i;k<=j-1;k++)
        {
           // temp = 1 + PP(s,i,k) + PP(s,k+1,j);
           //  mn = min(mn,temp);
            
            if(dp[i][k]!=-1)
            {
                left = dp[i][k];
            }
            else
            {
                left=PP(s,i,k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1)
            {
                right = dp[k+1][j];
            }
            else
            {
                right=PP(s,k+1,j);
                dp[k+1][j]=right;
            }
            
            
            temp = 1+left+right;
            
            mn=min(temp,mn);
            
        }
        
        return dp[i][j]=mn;
    }
    
    
    
    int minCut(string s)
    {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        pal.resize(n+1,vector<int>(n+1,-1));
        return PP(s,0,n-1);
    }
};
