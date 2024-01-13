//Recursion

class Solution {
public:
    
    int solve(int idx, int transactions, int n, bool buyFlag,vector<int>& prices){
        if(idx >= n || transactions >= 2){
            return 0;
        }

        int profit = 0;

        if(buyFlag){

            int take = solve(idx+1, transactions, n, false, prices) - prices[idx];

            int notTake = solve(idx+1, transactions, n, true, prices);

            profit = max({profit, take, notTake});
        }
        else{
            int sell = prices[idx] + solve(idx+1, transactions+1, n, true, prices);

            int notSell = solve(idx+1, transactions, n, false, prices);

            profit = max({profit, sell, notSell});
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0, 0, n, true, prices);
    }
};

//Recursion + Memo

class Solution {
public:

    int dp[100001][3][2];
    
    int solve(int idx, int transactions, int n, bool buyFlag,vector<int>& prices){
        if(idx >= n || transactions >= 2){
            return 0;
        }

        if(dp[idx][transactions][buyFlag] != -1){
            return dp[idx][transactions][buyFlag];
        }

        int profit = 0;

        if(buyFlag){

            int take = solve(idx+1, transactions, n, false, prices) - prices[idx];

            int notTake = solve(idx+1, transactions, n, true, prices);

            profit = max({profit, take, notTake});
        }
        else{
            int sell = prices[idx] + solve(idx+1, transactions+1, n, true, prices);

            int notSell = solve(idx+1, transactions, n, false, prices);

            profit = max({profit, sell, notSell});
        }

        return dp[idx][transactions][buyFlag] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, n, true, prices);
    }
};
