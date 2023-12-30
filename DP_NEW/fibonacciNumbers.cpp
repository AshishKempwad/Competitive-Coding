//Recursion TC = O(2^n)
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n==1){    //Base condition is always the smallest valid value of n
            return n;   
        }

        return fib(n-1)+fib(n-2);
    }
};

//Recursion + Memo

class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n==0 || n==1){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n) {
        if(n == 0 || n==1){    //Base condition is always the smallest valid value of n
            return n;   
        }

        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//Bottom UP  TC=O(n), SC=O(n)
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        vector<int>dp(n+1);
        dp[0]=0;  //dp[i]= ith fib number
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

//Constant Space complexity
//TC = O(n), SC=O(1)

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }

        int c;
        int a=0,b=1;

        for(int i=1;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
