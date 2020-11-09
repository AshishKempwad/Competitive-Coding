/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
*/



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if(wordDict.size()==0)
        {
            return false;
        }
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;     // the empty string will always be present in the dict
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    // string word = s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
