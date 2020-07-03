class Solution {
public:
    vector<vector<int>> memo;
    
    int lcs(string &text1,string &text2,int m,int n)
    {
       
        if(m==-1 || n==-1)
        {
            return 0;
        }
        
        if(memo[m][n]!=-1)
        {
            return memo[m][n];
        }
        else
        {
            
            if(text1[m]==text2[n])
            {
                memo[m][n] = 1+lcs(text1,text2,m-1,n-1);
            }
            else
            {

              memo[m][n] = max(lcs(text1,text2,m-1,n),lcs(text1,text2,m,n-1));
            }
        }
       
        return memo[m][n];
    }
    
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        memo.resize(m,vector<int>(n,-1));
        
        return lcs(text1,text2,m-1,n-1);
    }
    
    
};
