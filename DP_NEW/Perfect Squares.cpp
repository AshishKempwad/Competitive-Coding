//Recursion
class Solution {
public:

    
    int solve(int n){
        /*BASE CONDITION
        If n==0 then we return 0 as it takes 0 perfect squares to reach 0 from 0
        */

        if(n == 0)
        {
            return 0;
        }
        int minCost = INT_MAX;
        for(int i=1; i*i <= n; i++){
            int result = 1 +  numSquares(n - i*i);
            minCost = min(minCost,result);
        }
        return minCost;
    }

    int numSquares(int n) {
        return solve(n);
    }
};

//Recursion + Memo
class Solution {
public:

    int dp[10001];

    int solve(int n){
        /*BASE CONDITION
        If n==0 then we return 0 as it takes 0 perfect squares to reach 0 from 0
        */

        if(n == 0)
        {
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int minCost = INT_MAX;
        for(int i=1; i*i <= n; i++){
            int result = 1 +  solve(n - i*i);
            minCost = min(minCost,result);
        }
        return dp[n] = minCost;
    }

    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
