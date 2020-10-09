/*
Problem Description
Given an integer array A of size N, find the first repeating element in it.
We need to find the element that occurs more than once and whose index of first occurrence is smallest.
If there is no repeating element, return -1.

Example Input
Input 1:
 A = [10, 5, 3, 4, 3, 5, 6]
Input 2:
 A = [6, 10, 5, 4, 9, 120]

Example Output
Output 1:
 5
Output 2:
 -1

*/
int Solution::solve(vector<int> &A)
{
    unordered_map<int,int>mp;
    for(int i=0;i<A.size();i++)
    {
           mp[A[i]]++;
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(mp[A[i]] > 1)
        {
            return A[i];
        }
    }
    return -1;
}
