//recursion
class Solution {
public:
    int solve(vector<int>& nums, int i, int n){
        if(i >= n){ //No houses left, hence cant rob anything
            return 0;
        }

        int steal = nums[i]+solve(nums,i+2,n);
        int skip = solve(nums,i+1,n);

        return max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n);
    }
};

//Recursion + Memo
class Solution {
public:
     int dp[101];
    int solve(vector<int>& nums, int i, int n){
        if(i >= n){ //No houses left, hence cant rob anything
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int steal = nums[i]+solve(nums,i+2,n);
        int skip = solve(nums,i+1,n);

        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n);
    }
};
