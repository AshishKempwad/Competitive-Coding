/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

*/

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        //A character in s can map to exactly one character in t
        
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        
        for(int i=0;i<s.size();i++)
        {
            if(!mp1.count(s[i]))  //count function in map returns 1 if present else 0
            {
                mp1[s[i]]=i;
            }
            if(!mp2.count(t[i]))  // We try mapping every character in 's' and 't' to a unique number
            {
                mp2[t[i]]=i;
            }
            
            if(mp1[s[i]]!=mp2[t[i]])
            {                          
                return false;
            }
         }
         return true;
    }
        
};
