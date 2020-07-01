class Solution {
public:
    bool subsetsum(vector<int>& nums,int n,int sum)
    {
        if(sum==0)
        {
            return 1;
        }
        if(n==0 && sum!=0)
        {
            return 0;
        }
        
        if(nums[n-1] <= sum)
        {
            return subsetsum(nums,n-1,sum-nums[n-1]) || subsetsum(nums,n-1,sum);
        }
        
        return subsetsum(nums,n-1,sum);
    }
    
    
    
    
    bool canPartition(vector<int>& nums) 
    {
       int sum=0;
        int n = nums.size();
        int ans;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum%2 != 0)
        {
            return 0;
        }
        else
        {
            sum = sum/2;
           ans = subsetsum(nums,n,sum);
        }
        return ans;
    }
};
