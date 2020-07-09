class Solution {
public:
    vector<vector<int>> dp;
    
    bool ispal(string s,int i,int j)
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
        
        if(ispal(s,i,j)==true)
        {
            return 0;
        }
        
        int mn=INT_MAX;
        int temp;
        for(int k=i;k<=j-1;k++)
        {
           temp = 1 + PP(s,i,k) + PP(s,k+1,j);
            mn = min(mn,temp);
        }
        
        return dp[i][j]=mn;
    }
    
    
    
    int minCut(string s)
    {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return PP(s,0,n-1);
    }
};
