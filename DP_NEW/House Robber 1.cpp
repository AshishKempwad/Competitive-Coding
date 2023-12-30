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

//Bottom UP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        vector<int>t(n+1,0);

        //t[i] = Max stolen money till i'th house

        //If no house : i=0
        t[0]=0;

        //1 house : i =1
        t[1]=nums[0];

        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + t[i-2];  
            int skip = t[i-1]; //Profit till i-1'th house

            t[i] = max(steal,skip);
        }

        return t[n]
;
    }
};

