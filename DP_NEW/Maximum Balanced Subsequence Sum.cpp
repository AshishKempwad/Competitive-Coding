//Recursion
class Solution {
public:
    long long solve(int idx, int prev,vector<int>& nums, int n){
        if(idx >= n){
            return 0;   //No element hence sum is 0
        }

        int take = 0;
        if(prev == -1 || nums[idx] - idx >= nums[prev] - prev){  //Either its 1st element or follows the condition of being balanced
            take = nums[idx] + solve(idx+1,idx,nums,n);
        }
        int skip = solve(idx+1,prev,nums,n);

        return max<long long>(take,skip);

    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(begin(nums),end(nums));
        if(maxElement <= 0){ //To handle the negative testcases
            return maxElement;
        }
        return solve(0,-1,nums,n);
    }
};

//Recursion + Memo
class Solution {
public:
    int dp[4900][4900];
    long long solve(int idx, int prev,vector<int>& nums, int n){
        if(idx >= n){
            return 0;   //No element hence sum is 0
        }
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        int take = 0;
        if(prev == -1 || nums[idx] - idx >= nums[prev] - prev){  //Either its 1st element or follows the condition of being balanced
            take = nums[idx] + solve(idx+1,idx,nums,n);
        }
        int skip = solve(idx+1,prev,nums,n);
        
        if(prev != -1){
            dp[idx][prev] = max<long long>(take,skip);
        }
        return max<long long>(take,skip);

    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(begin(nums),end(nums));
        if(maxElement <= 0){ //To handle the negative testcases
            return maxElement;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums,n);
    }
};

//Fails to pass all testcases even with DP. Optimal Solution
