/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
       vector<int>res;
        
        vector<int>goal(26);
        vector<int>curr(26);
        
        for(int i=0;i<p.size();i++)
        {
            goal[p[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            curr[s[i]-'a']++;
            if(i>=p.size())
            {
                curr[s[i-p.size()]-'a']--;
              
            }
            if(goal==curr)
            {
               res.push_back(i-p.size()+1);
            }
            
        }
        return res;
    }
};
