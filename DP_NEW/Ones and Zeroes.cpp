//Recusrion

class Solution {
public:
    pair<int,int> countZeroAndOne(string s){
        int noOfZeros = 0;
        int noOfOnes = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                noOfZeros++;
            }else if(s[i] == '1'){
                noOfOnes++;
            }
        }

        return {noOfZeros,noOfOnes};
    }

    int solve(int idx, int noOfZeros, int noOfOnes, int totalNumberOfZerosNeeded, int totalNumberOfOnesNeeded, vector<string>& strs){
        if(idx >= strs.size()){
            return 0;
        }

        if(noOfZeros > totalNumberOfZerosNeeded || noOfOnes > totalNumberOfOnesNeeded){
            return 0;
        }

        pair<int,int>pairOfZeroAndOne = countZeroAndOne(strs[idx]);
        /*We have 3 options (2 if you can pick + 1 if you anyway cannot pick) : 
          1) Can Pick 
               a) Will Pick
               b) Will not Pick
          2) Can not Pick
        */

        int willPick = 0;
        int willNotPick = 0;
        int cannotPick = 0;

        if(noOfZeros+pairOfZeroAndOne.first <= totalNumberOfZerosNeeded && noOfOnes+pairOfZeroAndOne.second <= totalNumberOfOnesNeeded){
            willPick = 1 + solve(idx+1,noOfZeros+pairOfZeroAndOne.first,noOfOnes+pairOfZeroAndOne.second,totalNumberOfZerosNeeded,totalNumberOfOnesNeeded, strs);
            willNotPick = solve(idx+1,noOfZeros,noOfOnes,totalNumberOfZerosNeeded,totalNumberOfOnesNeeded,strs);
        }else{
            cannotPick = solve(idx+1,noOfZeros,noOfOnes,totalNumberOfZerosNeeded,totalNumberOfOnesNeeded,strs);
        } 

        return max({willPick,willNotPick,cannotPick});
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        //Pick or not Pick Dp
        return solve(0,0,0,m,n,strs);
    }
};

//Recusrion + Memo

class Solution {
public:
    int dp[601][101][101];
    pair<int,int> countZeroAndOne(string s){
        int noOfZeros = 0;
        int noOfOnes = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                noOfZeros++;
            }else if(s[i] == '1'){
                noOfOnes++;
            }
        }

        return {noOfZeros,noOfOnes};
    }
    int solve(int idx, int noOfZeros, int noOfOnes, int totalNumberOfZerosNeeded, int totalNumberOfOnesNeeded, vector<string>& strs){
        if(idx >= strs.size()){
            return 0;
        }

        if(noOfZeros > totalNumberOfZerosNeeded || noOfOnes > totalNumberOfOnesNeeded){
            return 0;
        }

        if(dp[idx][noOfZeros][noOfOnes] != -1){
            return dp[idx][noOfZeros][noOfOnes];
        }

        pair<int,int>pairOfZeroAndOne = countZeroAndOne(strs[idx]);
        /*We have 3 options (2 if you can pick + 1 if you anyway cannot pick) : 
          1) Can Pick 
               a) Will Pick
               b) Will not Pick
          2) Can not Pick
        */

        int willPick = 0;
        int willNotPick = 0;
        int cannotPick = 0;

        if(noOfZeros+pairOfZeroAndOne.first <= totalNumberOfZerosNeeded && noOfOnes+pairOfZeroAndOne.second <= totalNumberOfOnesNeeded){
            willPick = 1 + solve(idx+1,noOfZeros+pairOfZeroAndOne.first,noOfOnes+pairOfZeroAndOne.second,totalNumberOfZerosNeeded,totalNumberOfOnesNeeded, strs);
            willNotPick = solve(idx+1,noOfZeros,noOfOnes,totalNumberOfZerosNeeded,totalNumberOfOnesNeeded,strs);
        }else{
            cannotPick = solve(idx+1,noOfZeros,noOfOnes,totalNumberOfZerosNeeded,totalNumberOfOnesNeeded,strs);
        } 

        return dp[idx][noOfZeros][noOfOnes] = max({willPick,willNotPick,cannotPick});
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        //Pick or not Pick Dp
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,m,n,strs);
    }
};

