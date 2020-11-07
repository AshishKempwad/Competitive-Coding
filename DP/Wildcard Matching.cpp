/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
*/


class Solution {
public:
    bool isMatch(string s, string p) 
    {
        
        
        /*
           We here check few conditions: (Logic)
           1)dp[0][0] = T;
            i.e : If string is empty and pattern is also empty then we say that its a match
            
           2) dp[i][0]=F;
             i->string
             j->pat
             
             i.e If pat is empty and string is not empty, then there is no match
             
           3)dp[0][j]=dp[0][j-1] if(pat[j-1]=="*")
             else dp[0][j]=F;
             
           4)if(str[i-1]==pat[j-1] || pat[j-1]=='?' )
            {
               dp[i][j]=dp[i-1][j-1];
            }
            
           5)if(pat[i][j]=="*")
            {
                dp[i][j]=dp[i-1][j] || dp[i][j-1];  i.e "*" is either empty or it also includes the current character
            }
            
            else
            {
            dp[i][j]=F;
            }
           
        */
        
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1));
        
        dp[0][0]=true;
        
        for(int i=1;i<=n;i++)   //string
        {
           dp[i][0]=false;
        }
         for(int j=1;j<=m;j++)   //string
        {   
             if(p[j-1]=='*')
            {
              dp[0][j]=dp[0][j-1];  
            }
             else
             {
               dp[0][j]=false;
             }
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        
        return dp[n][m];
        
        
    }
};

