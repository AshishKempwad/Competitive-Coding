
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) 
{
    int n = a.size();
    int m = b.size();

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
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max( dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i=n;
    int j=m;
    vector<int>res;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            int ans = a[i-1];
            res.push_back(ans);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
            {  
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(res.begin(),res.end());
    return res;
    

}
