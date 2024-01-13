//Recusrion + Memo

//Refer for all Best Time to Sell problems: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/900050/fully-explained-all-buy-and-sell-problems-c-recursive-memoization-minor-difference/
class Solution {
public:

    /*We can have only 1 buy and 1 sell order. k represnts maximum buy-sell you can do*/
    int dp[100001][2];
    int solve(vector<int>& prices, int idx, int k, int n, bool buyFlag){
        if(idx >= n || k <= 0){
            return 0;
        }

        if(dp[idx][buyFlag] != -1){
            return dp[idx][buyFlag];
        }

        int profit = 0;

        if(buyFlag){
            int take = solve(prices, idx+1, k, n, false) - prices[idx];

            int notTake = solve(prices, idx+1, k, n, true);

            profit = max({profit, take, notTake});

        }else{
            int sell = prices[idx] + solve(prices, idx+1, k-1, n, true);

            int notSell = solve(prices, idx+1, k, n, false);

            profit = max({profit, sell, notSell}); 
        }

        return dp[idx][buyFlag] = profit;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices, 0, 1, n, true);
    }
};


//Optimal Approach
TC =O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for(int i=0;i<n;i++){
            minPrice = min(prices[i], minPrice);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};
