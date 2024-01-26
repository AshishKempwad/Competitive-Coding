//Recursion + Memo
// TC : O(m * n * maxMove)
// SC : O(m * n * maxMove)

class Solution {
public:
   
    int MOD = 1e9+7;

    int dp[51][51][51];

    int solve(int n, int m, int maxMove,int sr, int sc){

        /*BASE CONDITION:
        If we move out of grid we will return 1, as thats our goal and we have found 1 way to do that.
        If maxMoves <= 0 then we return 0 as we have exhausted the maximum moves.*/

        if(sr < 0 || sr >= n || sc < 0 || sc >= m){
            return 1;
        }

        if(maxMove <= 0){
            return 0;
        }

        if(dp[maxMove][sr][sc] != -1){
            return dp[maxMove][sr][sc]%MOD;
        }

        /*Total ways would be summation of moves in every direction.*/
        int totalMoves = 0;

        totalMoves = (totalMoves + solve(n,m,maxMove-1,sr,sc-1)) % MOD;
        totalMoves = (totalMoves + solve(n,m,maxMove-1,sr-1,sc)) % MOD;
        totalMoves = (totalMoves + solve(n,m,maxMove-1,sr,sc+1)) % MOD;
        totalMoves = (totalMoves + solve(n,m,maxMove-1,sr+1,sc)) % MOD;

        return dp[maxMove][sr][sc] = totalMoves%MOD;                 

    }


    int findPaths(int n, int m, int maxMove, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return solve(n,m,maxMove,sr,sc);
    }
};
