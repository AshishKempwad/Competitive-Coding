class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int lastgoodindex = nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i+nums[i] >= lastgoodindex)
            {
                lastgoodindex = i;
            }
        }
        
        if(lastgoodindex == 0)
        {
            return true;
        }
        return false;
    }
};
