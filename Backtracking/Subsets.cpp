class Solution {
public:

    /*
    For an array of length n
    Number of subsets: Each element in the array can either be included in a subset or not. Therefore, the total number of subsets is 2^n.
    Generating each subset: To generate each subset, we potentially iterate through the entire array. 
    In the worst case, this operation takes O(n)time for each subset.
    Thus, the total time complexity is O(2^n * n)

    */

    void solve(vector<int>& nums, int n, int start, vector<int>&temp,vector<vector<int>>&res){
        res.push_back(temp);

        for(int i=start;i<n;i++){
            temp.push_back(nums[i]);
            solve(nums,n,i+1,temp,res);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>res;

        solve(nums,n,0,temp,res);
        return res;
    }
};
