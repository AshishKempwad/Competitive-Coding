//Recursion
//TC = O(k^n), k - Max element in nums and n - total no. of elements

class Solution {
public:

    long long int solve(int idx, int n,vector<int>& nums){
        /*If we are at the last index or beyond that, 
        then no. of steps to reach the last index would be 0.
        Its logical right, that it would take 0 jumps to reach 
        last index from last index, as we are already standing at last index or beyond that*/
        if(idx >= n){
            return 0;
        }
        long long int minJumps = INT_MAX;

        for(int i=1;i<=nums[idx];i++){
            minJumps = min(minJumps, 1 + solve(idx+i,n,nums));
        }

        return minJumps;
    }
    int jump(vector<int>& nums) {

        int n = nums.size() - 1;  //We are taking size()-1 and not size()
        return solve(0,n,nums);
    }
};

//Recursion + Memo
//TC = O(k * n), k - Max element in nums and n - total no. of elements

class Solution {
public:
 
    int dp[10001];

    long long int solve(int idx, int n,vector<int>& nums){
        /*If we are at the last index or beyond that, 
        then no. of steps to reach the last index would be 0.
        Its logical right, that it would take 0 jumps to reach 
        last index from last index, as we are already standing at last index or beyond that*/
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        long long int minJumps = INT_MAX;

        for(int i=1;i<=nums[idx];i++){
            minJumps = min(minJumps, 1 + solve(idx+i,n,nums));
        }

        return dp[idx] = minJumps;
    }
    int jump(vector<int>& nums) {

        int n = nums.size() - 1;  //We are taking size()-1 and not size()

        memset(dp,-1,sizeof(dp));
        return solve(0,n,nums);
    }
};
