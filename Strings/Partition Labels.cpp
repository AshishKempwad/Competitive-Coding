/*A string S of lowercase English letters is given. 
We want to partition this string into as many parts as possible so that each letter appears
in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"

Output: [9,7,8]

Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

// # NOTE : TC = O(n). It might appear to be O(n^2) but when you observe closely, you will see, 'i=j+1'. Hence its O(n)
//          SC = O(1)

class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        vector<int>preprocess(26);   // The last index of that character
        for(int i=0;i<n;i++)
        {
            preprocess[s[i]-'a']=i;
        }
        vector<int>res;
        int i=0;
        while(i<n)
        {
            int end = preprocess[s[i]-'a'];
            int j=i;
            // If we find any character between the start and end of the character choosen, then see if   
           //it lies in that range or in case it extends that range, we also extend(update) our range
            while(j<end) 
            {
                end = max(end,preprocess[s[j]-'a']);  
                j++;
            }
            res.push_back(j-i+1);
            i=j+1;
        }
        
        return res;
    }
};
