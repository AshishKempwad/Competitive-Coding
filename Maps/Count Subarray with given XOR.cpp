/*Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.

Example Input
Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6

Input 2:
 A = [5, 6, 7, 8, 9]
 B = 5
 
Example Output
Output 1:
 4

Output 2:
 2

Example Explanation
Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Explanation 2:
 The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]
 
*/
//WATCH THIS VIDEO:  https://www.youtube.com/watch?v=lO9R5CaGRPY&t=540s for understanding. 


//TC = O(nlogn) for map  & TC=O(n) in average case and O(n^2) in worst case for unordered_map. 
//SC = O(n) both for map as well as unordered_map

int Solution::solve(vector<int> &A, int B)
{
    //Very tricky explanation.
    //Asked in interviews alot.
    
    unordered_map<int,int>mp;
    int count=0;
    int XR = 0;   //Initially XR(it is xor of elements till that point from begining) is 0.
    for(auto ele : A)
    {
        XR = XR ^ ele;
        if(XR == B)
        {
            count++;
        }
        
        if(mp.find(XR ^ B)!=mp.end())
        {
            count = count + mp[XR ^ B];
        }
        
        mp[XR]=mp[XR]+1;
    }
    
    return count;
}
