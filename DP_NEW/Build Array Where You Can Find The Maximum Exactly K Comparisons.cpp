//Recursion

class Solution {
public:

    int MOD = 1e9+7;
    int solve(int idx, int searchCost, int maximumValue, int n, int k, int m){
        if(idx >= n)  //Base condition
        {
            if(searchCost == k){  //We have found the result at the leaf node
               return 1;
            }
            return 0;
        }
        int res =0;
        for(int i=1;i<=m;i++){
            if(i > maximumValue){   //We we find the greater value than current max
                res += solve(idx+1, searchCost+1,i,n,k,m)%MOD;
            }else{
                res += solve(idx+1, searchCost, maximumValue, n,k,m)%MOD;  //If the value we find is smaller than current MaximumValue
            }
        }

        return res % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        //n - Represents size of integers that we can have
        //m - Represents the value of integers (it can be 1 to m)
        //k - Represents searchCost
        //We know maximum_value = -1 initally

        return solve(0,0,-1,n,k,m);
    }
};

//Recursion + Memo
class Solution {
public:

    int dp[51][51][101];
    int MOD = 1e9+7;
    int solve(int idx, int searchCost, int maximumValue, int n, int k, int m){
        if(idx >= n)  //Base condition
        {
            if(searchCost == k){  //We have found the result at the leaf node
               return 1;
            }
            return 0;
        }
        if(maximumValue != -1 && dp[idx][searchCost][maximumValue] != -1){
            return dp[idx][searchCost][maximumValue] % MOD;
        }
        int res =0;
        for(int i=1;i<=m;i++){
            if(i > maximumValue){   //We we find the greater value than current max
                res = (res + solve(idx+1, searchCost+1,i,n,k,m))%MOD;
            }else{
                res = (res+ solve(idx+1, searchCost, maximumValue, n,k,m))%MOD;  //If the value we find is smaller than current MaximumValue
            }
        }

        if(maximumValue != -1){
            dp[idx][searchCost][maximumValue] = res % MOD;
        }

        return res % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        //n - Represents size of integers that we can have
        //m - Represents the value of integers (it can be 1 to m)
        //k - Represents searchCost
        //We know maximum_value = -1 initally
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1,n,k,m);
    }
};
