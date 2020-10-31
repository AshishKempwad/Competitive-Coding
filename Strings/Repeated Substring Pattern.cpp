/*Given a non-empty string check if it can be constructed by taking a 
substring of it and appending multiple copies of the substring together.
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

//TC=O(n^2)

class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
       //The size of substring which we want to append multiple times 
        //can never br greater then half the length of the original string 
        
        int len = s.size();
        
        if(len == 1)   // if len==1, theres no substring to append
        {
            return false;
        }
        
        for(int i=len/2;i>=1;i--)  // Here this loop helps us get the size of the subtring and not the index
        {
            if(len%i==0) // for a subtring to form the string by appending multiple times it should be in the multiple of string
            {
                int no_of_times_to_append = len/i;   // no. of times we will append the substring
                
                string build="";
                
                string sub_string = s.substr(0,i);  // substring we will append to create the original string
                
                for(int j=0;j<no_of_times_to_append;j++)
                {
                     build.append(sub_string);      //substr(int pos,int len)
                }
                
                if(build==s)    // if its equal to string, return true
                {
                    return true;
                }
            }
        }
        return false;
    }
};
