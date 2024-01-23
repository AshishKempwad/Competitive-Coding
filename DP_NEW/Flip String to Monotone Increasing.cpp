//Recursion TC : O(2^n)

class Solution {
public:
    int solve(int idx, int prev, string &s, int n){
        /*BASE CONDITION : 
        If we move out of index, then return 0
        */
        if(idx >= n){
            return 0;
        }

        int flip = INT_MAX;
        int noFlip = INT_MAX;

        /*There can only be 2 items in string either '0' or '1'.
        */
        if(s[idx] == '1'){     
             //CASE1 : idx = 1 & prev = 0   eg : 01                      
            if(prev == 0){
                flip = 1 + solve(idx+1, 0, s, n);
                noFlip = solve(idx+1, 1, s, n);

            }else{  //CASE2 : idx = 1 & prev = 1   eg : 11

               noFlip = solve(idx+1, 1, s, n);

            }

        }else{
            //CASE3 : idx = 0 & prev = 0   eg : 00
            if(prev == 0){   //00
                flip = 1 + solve(idx+1, 1, s, n);
                noFlip = solve(idx+1, 0, s, n);

            }else{ //CASE4 : idx = 0 & prev = 0   eg : 10
              flip = 1 + solve(idx+1, 1, s, n);
        
            }

        }

        return min(flip, noFlip);

    }

    int minFlipsMonoIncr(string s) {
        int n = s.length();
        return solve(0,0,s,n);
    }
};

//Recursion + Memo  TC : O(n)
class Solution {
public:
    int dp[100001][2];
    int solve(int idx, int prev, string &s, int n){
        /*BASE CONDITION : 
        If we move out of index, then return 0
        */
        if(idx >= n){
            return 0;
        }

        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }

        int flip = INT_MAX;
        int noFlip = INT_MAX;

        /*There can only be 2 items in string either '0' or '1'.
        */
        if(s[idx] == '1'){     
             //CASE1 : idx = 1 & prev = 0   eg : 01                      
            if(prev == 0){
                flip = 1 + solve(idx+1, 0, s, n);
                noFlip = solve(idx+1, 1, s, n);

            }else{  //CASE2 : idx = 1 & prev = 1   eg : 11

               noFlip = solve(idx+1, 1, s, n);

            }

        }else{
            //CASE3 : idx = 0 & prev = 0   eg : 00
            if(prev == 0){   //00
                flip = 1 + solve(idx+1, 1, s, n);
                noFlip = solve(idx+1, 0, s, n);

            }else{ //CASE4 : idx = 0 & prev = 0   eg : 10
              flip = 1 + solve(idx+1, 1, s, n);
        
            }

        }

        return dp[idx][prev] = min(flip, noFlip);

    }

    int minFlipsMonoIncr(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,n);
    }
};

//Optimal Solution:
//TC = O (n)

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        /*We miantain 2 variables, countOfOnes - which keeps the count of no. of 1's
        and flips - which checks the flips required till that point to 
        convert/maintain monotonically increasing string.*/
        int countOfOnes = 0;
        int flips = 0;
 
        /* 1)If we see "1", we increase the countOfOnes.
           2)If we see a "0", we have 2 options
              a)Leave "0" as it is - If we plan to leave 0 as it is, then we need to flip all the 1's to 0's 
                                     seen so far in past, as only then it would be monotonically increasing.
              b)Change the "0" to "1" - Else we can flip 0 to 1

              We will choose the the minimum of (a,b).

              We are storing number of flips in flips variable.
              */
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                countOfOnes++;
            }else{
                flips = min(flips+1, countOfOnes);
            }
        }

        return flips;
    }
};
