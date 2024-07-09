class Solution {
public:

   //TC = O(n*2^n) + O(nlogn)

    void solve(vector<int>& nums,int n, int start,vector<int>&temp,vector<vector<int>>&res){
        res.push_back(temp);

        for(int i=start;i<n;i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(nums,n,i+1,temp,res);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>res;
        //We sort because we need to remove the duplicates.
        //And by sorting removing duplicates becomes easy - it can be done by comparing the current element with previous element.
        sort(nums.begin(),nums.end());   

        solve(nums,n,0,temp,res);

        return res;
    }
};
