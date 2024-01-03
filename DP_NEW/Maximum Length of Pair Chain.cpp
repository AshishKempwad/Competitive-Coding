//Recusrion

class Solution {
public:
    int solve(int idx, int prev, int n,vector<vector<int>>& pairs){
         if(idx >= n){
             return 0;
         }

         int take = 0;
         if(prev == -1 || pairs[idx][0] > pairs[prev][1]){   //We can only choose if the current element's first is greater than prev's second
               take = 1 + solve(idx+1,idx,n,pairs);
         }

         int skip = solve(idx+1,prev,n,pairs);

         return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs),end(pairs));  //Default sorting based on first part of the pair
        return solve(0,-1,n,pairs);
    }
};

//Recursion + Memo
class Solution {
public:

    int dp[1001][1001];
    int solve(int idx, int prev, int n,vector<vector<int>>& pairs){
         if(idx >= n){
             return 0;
         }
          
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
         int take = 0;
         if(prev == -1 || pairs[idx][0] > pairs[prev][1]){   //We can only choose if the current element's first is greater than prev's second
               take = 1 + solve(idx+1,idx,n,pairs);
         }

         int skip = solve(idx+1,prev,n,pairs);
         
         if(prev != -1){
             dp[idx][prev] = max(take,skip);
         }
         return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs),end(pairs));  //Default sorting based on first part of the pair
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,n,pairs);
        
    }
};
