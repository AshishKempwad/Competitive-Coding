class Solution {
public:
    vector<vector<int>> dp;
    
    int coinchange(vector<int>& coins,int n,int amount)
    {
        if(n==0)
        {
            return 0;
        }
        
        if(amount==0)
        {
            return 1;
        }
        
       if(dp[n][amount] != -1)
       {
           return dp[n][amount];
       }
        if(coins[n-1]>amount)
        {
            dp[n][amount] = coinchange(coins,n-1,amount);
            return dp[n][amount];
        }
        
         dp[n][amount] = coinchange(coins,n,amount-coins[n-1])+coinchange(coins,n-1,amount);
        
        return dp[n][amount];
    }
    
    
    
    int change(int amount, vector<int>& coins) 
    {
       int n = coins.size();
        
        if(n==0 && amount==0) // to handle corner test case of amount=0 and n=0
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        if(amount==0)  // one way to make sum as zero, that is dont pick any amount of money
        {
            return 1;
        }
        
        dp.resize(n+1,vector<int>(amount+1,-1));
        dp[n][amount] = coinchange(coins,n,amount);
        return dp[n][amount];
    }
};
