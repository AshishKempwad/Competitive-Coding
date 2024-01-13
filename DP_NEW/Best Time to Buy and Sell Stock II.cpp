//Recursion

class Solution {
public:
    int solve(int idx, int n, vector<int>& prices, bool buyFlag){

        if(idx >= n){
            return 0;
        }

        int profit = 0;

        if(buyFlag){
            int take = solve(idx+1,n, prices,false) - prices[idx];

            int notTake = solve(idx+1, n, prices, true);

            profit = max({profit, take, notTake});
        }else{

            int sell = prices[idx] + solve(idx+1, n, prices, true);

            int notSell = solve(idx+1, n, prices, false);

            profit = max({profit, sell, notSell});
        }

        return profit;

    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0,n,prices,true); 
    }
};


//Recursion + Memo

class Solution {
public:

    int dp[30001][2];
    
    int solve(int idx, int n, vector<int>& prices, bool buyFlag){

        if(idx >= n){
            return 0;
        }

        if(dp[idx][buyFlag] != -1){
            return dp[idx][buyFlag];
        }

        int profit = 0;

        if(buyFlag){
            int take = solve(idx+1,n, prices,false) - prices[idx];

            int notTake = solve(idx+1, n, prices, true);

            profit = max({profit, take, notTake});
        }else{

            int sell = prices[idx] + solve(idx+1, n, prices, true);

            int notSell = solve(idx+1, n, prices, false);

            profit = max({profit, sell, notSell});
        }

        return dp[idx][buyFlag] = profit;

    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,prices,true); 
    }
};
