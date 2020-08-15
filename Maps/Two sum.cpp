class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            int ele = target - nums[i];
            
            if(mp.find(ele)!=mp.end())
            {
                return {i,mp[ele]};
            }
            
            mp[nums[i]]=i;
        }
        
        
        return {};
    }
};
