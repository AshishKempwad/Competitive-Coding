//Recursion
class Solution {
public:
    int solve(int idx, int d, int n,vector<int>& jobDifficulty){
        /*
        Base Condition:
        When only 1 day is left, we will have to do all the jobs on that day itself.
        And we need to find the maximum Dificulty and return 
        */
        if(d == 1){
            int maxD = jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                maxD = max(maxD, jobDifficulty[i]);
            } 
            return maxD;
        }

        int maxD = jobDifficulty[idx];
        int finalResult = INT_MAX;

        /* Try one by one possibility
          Take index = {idx} wala job on first day
          Take index = {idx,idx+1} wala jobs on first day
          Take index = {idx,idx+1,idx+2} wala jobs on first day
          .....and so on 
        */

        /*We are going till "n-d" as we need to have remaining jobs for the rest days.
        That is, We can do at max "n-d" jobs at once on first day. So that we have atleast d jobs for remaining d days.
        As condition says we have to do atleast 1 job per day.
        */
        for(int i=idx;i<=n-d;i++){  
             maxD = max(maxD,jobDifficulty[i]);

             int result = maxD + solve(i+1,d-1,n,jobDifficulty);
             finalResult = min(finalResult,result); 
        }

        return finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(d > n){  // If no. of days are more than the jobs, then we cant schedule them all, hence return -1
            return -1;
        }
        return solve(0,d,n,jobDifficulty);
    }
};

//Recursion + Memo
class Solution {
public:

    int dp[301][11];
    int solve(int idx, int d, int n,vector<int>& jobDifficulty){
        /*
        Base Condition:
        When only 1 day is left, we will have to do all the jobs on that day itself.
        And we need to find the maximum Dificulty and return 
        */
        if(d == 1){
            int maxD = jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                maxD = max(maxD, jobDifficulty[i]);
            } 
            return maxD;
        }

        if(dp[idx][d] != -1){
            return dp[idx][d];
        }

        int maxD = jobDifficulty[idx];
        int finalResult = INT_MAX;

        /* Try one by one possibility
          Take index = {idx} wala job on first day
          Take index = {idx,idx+1} wala jobs on first day
          Take index = {idx,idx+1,idx+2} wala jobs on first day
          .....and so on 
        */

        /*We are going till "n-d" as we need to have remaining jobs for the rest days.
        That is, We can do at max "n-d" jobs at once on first day. So that we have atleast d jobs for remaining d days.
        As condition says we have to do atleast 1 job per day.
        */
        for(int i=idx;i<=n-d;i++){  
             maxD = max(maxD,jobDifficulty[i]);

             int result = maxD + solve(i+1,d-1,n,jobDifficulty);
             finalResult = min(finalResult,result); 
        }

        return dp[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(d > n){  // If no. of days are more than the jobs, then we cant schedule them all, hence return -1
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,d,n,jobDifficulty);
    }
};
