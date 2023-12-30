//Recursion

class Solution {
public:
    typedef long long ll;
    int dp[100001][2];

    ll solve(vector<int>& nums, bool flag, int idx, int n){
        if(idx >= n){
            return 0;
        }

        int skip = solve(nums,flag,idx+1,n); // We are not taking hence sign would be same(Sign alternates, + and - alternatively)

        int val = nums[idx];

        if(flag == false){
            val = -val;
        }

        int take = solve(nums,!flag,idx+1,n)+val;

        return max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return solve(nums,true,0,n);
    }
};

//recursion + memo
class Solution {
public:
    typedef long long ll;
    ll dp[100001][2];

    ll solve(vector<int>& nums, bool flag, ll idx, int n){
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx][flag] != -1){
            return dp[idx][flag];
        }
        ll skip = solve(nums,flag,idx+1,n); // We are not taking hence sign would be same(Sign alternates, + and - alternatively)

        ll val = nums[idx];

        if(flag == false){
            val = -val;
        }

        ll take = solve(nums,!flag,idx+1,n)+val;

        return dp[idx][flag] = max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return solve(nums,true,0,n);
    }
};
