/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Example 4:
Input: nums = [1]
Output: [1]
*/


// HACK :  Use stl library "next_permutation" if allowed
--------------------------------------------------------------------------------------------------
// Brute Force:

/* We generate all possible permutations and then from that choose the next permutation.
  1) Generate all permatation
  2) sort them to get them lexographically
  3) Then find the next number of given number
  
 Its TC=O(n!*n)+O(nlogn) = O(n!*n)
     SC = O(n!)
*/

--------------------------------------------------------------------------------------------------------------
// Optimized solution
//TC = O(n)
// SC = O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size(),i,l;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])  //we try to find the breakpoint
            {
                break;
            }
        }
        
        if(i < 0)   // for corner cases: Say given is "321" so its next permutation would be 123, that is round off to back 
        {
            reverse(nums.begin(),nums.end());
        }
        else   // for rest cases
        {
            for(l=n-1;l>i;l--)   // find number greater than current choosen and swap
            {
                if(nums[l] > nums[i])
                {
                    break;
                }
            }
            
            swap(nums[l],nums[i]);
            reverse(nums.begin()+i+1,nums.end());   // reverse rest all front numbers to get lowest next permutation
        }
        
        
    }
};
