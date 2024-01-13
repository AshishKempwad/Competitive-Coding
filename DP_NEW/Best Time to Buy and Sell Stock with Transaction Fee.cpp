//Recursion

class Solution {
public:
    
    int solve(int idx, int fee, bool buyFlag, int n, vector<int>& prices){

        if(idx >= n){
            return 0;
        }

        int profit = 0;

        if(buyFlag){

            int take = solve(idx+1, fee, false, n, prices) - prices[idx];

            int notTake = solve(idx+1, fee, true, n, prices);

            profit = max({profit, take, notTake});

        }else{

            int sell = prices[idx] - fee + solve(idx+1, fee, true, n, prices);

            int notSell = solve(idx+1, fee, false, n, prices);

            profit = max({profit, sell, notSell});

        }

        return profit;

    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return solve(0, fee, true, n, prices);
    }
};

//Recursion + Memo

class Solution {
public:

    int dp[50001][2];
    
    int solve(int idx, int fee, bool buyFlag, int n, vector<int>& prices){

        if(idx >= n){
            return 0;
        }

        if(dp[idx][buyFlag] != -1){
            return dp[idx][buyFlag];
        }

        int profit = 0;

        if(buyFlag){

            int take = solve(idx+1, fee, false, n, prices) - prices[idx];

            int notTake = solve(idx+1, fee, true, n, prices);

            profit = max({profit, take, notTake});

        }else{

            int sell = prices[idx] - fee + solve(idx+1, fee, true, n, prices);

            int notSell = solve(idx+1, fee, false, n, prices);

            profit = max({profit, sell, notSell});

        }

        return dp[idx][buyFlag] = profit;

    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, fee, true, n, prices);
    }
};

