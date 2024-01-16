//Recursion
//TC = O(n^k)
class Solution {
public:
    
    bool solve(int idx, vector<int>& nums, int n){
        if(idx == n-1){
            return true;
        }

        for(int i=1;i<=nums[idx];i++){
            if(solve(idx+i, nums, n) == true){
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return solve(0, nums, n);
    }
};

//Recursion + Memo
// TC = O(n*k)
class Solution {
public:

    int dp[10001];
    
    bool solve(int idx, vector<int>& nums, int n){
        if(idx == n-1){
            return true;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        for(int i=1;i<=nums[idx];i++){
            if(solve(idx+i, nums, n) == true){
                return dp[idx+i] = true;
            }
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, nums, n);
    }
};


//Optimal
//TC : O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0;

        for(int i=0;i<n;i++){
            if(i > maxReachable){
                return false;
            }
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};
