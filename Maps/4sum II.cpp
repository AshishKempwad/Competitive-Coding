/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        
        unordered_map<int,int>mp;
        
        for(auto a: A)
        {
            for(auto b : B)
            {
                mp[a+b]++;
            }
        }
        int count=0;
        for(auto c: C)
        {
            for(auto d: D)
            {
                auto it = mp.find(0-c-d);
                if(it!=mp.end())
                {
                    count = count + it->second;
                }
            }
        }
        return count;
    }
};
