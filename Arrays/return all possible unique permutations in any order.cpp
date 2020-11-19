Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order. 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
public:
    
    void permutate(vector<int>nums,int l,int h,vector<vector<int>>&res)  //Most important thing is that "DO NOT PASS nums WITH ADDRESS"
    {                                                                        
        if(l==h)
        {
            res.push_back(nums);
        }
        else
        {
            for(int i=l;i<=h;i++)
            {
                if(nums[i]!=nums[l] || i==l)
                {
                    swap(nums[l],nums[i]);
                    permutate(nums,l+1,h,res);
                    // swap(nums[l],nums[i]);  // as we dont pass by address, we dont unswap it
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        permutate(nums,0,n-1,res);
        return res;
    }
};
