//Recursion

class Solution {
public:
    int solve(int idx, int k, int n, bool buyFlag, vector<int>& prices){
        if(idx >= n || k <= 0){
            return 0;
        }

        int profit = 0;
 
        if(buyFlag){

            int take = solve(idx+1, k, n, false, prices) - prices[idx];

            int notTake = solve(idx+1, k, n, true, prices);

            profit = max({profit, take, notTake});

        }else{

            int sell = prices[idx] + solve(idx+1, k-1, n, true, prices);

            int notSell = solve(idx+1, k, n, false, prices);

            profit = max({profit, sell, notSell});

        }

        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(0, k, n, true, prices);
    }
};

//Recursion + Memo

class Solution {
public:

    int dp[1001][1001][2];
 
    int solve(int idx, int k, int n, bool buyFlag, vector<int>& prices){
        if(idx >= n || k <= 0){
            return 0;
        }

        if(dp[idx][k][buyFlag] != -1){
            return dp[idx][k][buyFlag];
        }

        int profit = 0;
 
        if(buyFlag){

            int take = solve(idx+1, k, n, false, prices) - prices[idx];

            int notTake = solve(idx+1, k, n, true, prices);

            profit = max({profit, take, notTake});

        }else{

            int sell = prices[idx] + solve(idx+1, k-1, n, true, prices);

            int notSell = solve(idx+1, k, n, false, prices);

            profit = max({profit, sell, notSell});

        }

        return dp[idx][k][buyFlag] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, k, n, true, prices);
    }
};
