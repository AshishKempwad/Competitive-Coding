/*Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
       int count=0;
        int sum=0;
        unordered_map<int,int>mp={{0,1}};
      for(int i=0;i<nums.size();i++)
      {
          sum=sum+nums[i];
          
          if(mp.find(sum-k)!=mp.end())
          {
              count=count+mp[sum-k];
          }
          
          mp[sum]++;
      }
        return count;
    }
};
 
