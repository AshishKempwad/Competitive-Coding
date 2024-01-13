//Recursion
class Solution {
public:
    int solve(vector<int>& prices, int idx, int n, bool buyFlag){
        //BASE CONDITION
        if(idx >= n){
            return 0;
        }

        int profit = 0;

        if(buyFlag){
            //For buying

            /*take means we are buying, hence the solve function we call is going for "selling"
            The profit would be sell function - current day price.
            Flag is set as false, we have bought and now we are looking at selling*/
            int take = solve(prices,idx+1,n,false) - prices[idx];
                                                               
            /*notTake means we havent bought it now, hence we have buy it later. 
            Hence we call buy solve function for buy. 
            Hence the flag passed is true bacuse we want to buy*/                                                   
            int notTake = solve(prices,idx+1,n,true); 

            profit = max({profit,take,notTake});

        }else{
            //For selling

            /*sell means we want to sell it now. After every sell there would the 
            profit associated with it of the current day sell.
            There would be a cooldown period after every one cycle (buy + sell).
            Hence we cannot buy immidiately after selling, hnece there would be a cooldown period of 1 day.
            And as we have sold, we are now planning to buy hence it would be a call to buy with buyFlag as true.
            */

            int sell = prices[idx] + solve(prices,idx+2,n,true);

            /*notSell means we havent sol it yet. Hence we are now calling the solve function for selling.
            Hence buyFlag is set as false as we are now selling and not buying.*/
            int notSell = solve(prices,idx+1,n,false);

            profit = max({profit,sell,notSell});
        }

        return profit;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /*Initailly the flag should be true to buy as you cannot sell before buying*/
        return solve(prices,0,n,true);
    }
};

//Recursion + Memo
class Solution {
public:

    int dp[5001][2];

    int solve(vector<int>& prices, int idx, int n, bool buyFlag){
        //BASE CONDITION
        if(idx >= n){
            return 0;
        }

        if(dp[idx][buyFlag] != -1){
            return dp[idx][buyFlag];
        }

        int profit = 0;

        if(buyFlag){
            //For buying

            /*take means we are buying, hence the solve function we call is going for "selling"
            The profit would be sell function - current day price.
            Flag is set as false, we have bought and now we are looking at selling*/
            int take = solve(prices,idx+1,n,false) - prices[idx];
                                                               
            /*notTake means we havent bought it now, hence we have buy it later. 
            Hence we call buy solve function for buy. 
            Hence the flag passed is true bacuse we want to buy*/                                                   
            int notTake = solve(prices,idx+1,n,true); 

            profit = max({profit,take,notTake});

        }else{
            //For selling

            /*sell means we want to sell it now. After every sell there would the 
            profit associated with it of the current day sell.
            There would be a cooldown period after every one cycle (buy + sell).
            Hence we cannot buy immidiately after selling, hnece there would be a cooldown period of 1 day.
            And as we have sold, we are now planning to buy hence it would be a call to buy with buyFlag as true.
            */

            int sell = prices[idx] + solve(prices,idx+2,n,true);

            /*notSell means we havent sol it yet. Hence we are now calling the solve function for selling.
            Hence buyFlag is set as false as we are now selling and not buying.*/
            int notSell = solve(prices,idx+1,n,false);

            profit = max({profit,sell,notSell});
        }

        return dp[idx][buyFlag] = profit;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /*Initailly the flag should be true to buy as you cannot sell before buying*/
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,n,true);
    }
};
