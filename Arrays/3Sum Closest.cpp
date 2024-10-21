/*
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) 
    {
        int n=A.size();
        sort(A.begin(),A.end());
        long long int sum;
        long long int res = INT_MAX;
        long long int ans;
        for(int i=0;i<n;i++)
        {
            int l=i+1;
            int h=n-1;
            
            while(l<h)
            {
                sum=A[i]+A[l]+A[h];
                if(sum > target)
                {
                    h--;
                }
                else if(sum < target)
                {
                    l++;
                }
                else
                {
                    l++;
                    h--;
                }
                
                if(abs(sum-target) < res)
                {
                    res=abs(sum-target);
                    ans=sum;
                }
            }
        }
        
        return ans;
    }
};



########################################JAVA#########################################

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int closestNumber = 100000;

        Arrays.sort(nums);

        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;

            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];

                if(Math.abs(sum-target) < Math.abs(closestNumber-target)){
                    closestNumber = sum;
                }

                if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }

        return closestNumber;
    }
}
