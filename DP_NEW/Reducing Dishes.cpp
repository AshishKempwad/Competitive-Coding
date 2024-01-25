//Recursion
//TC = O(2^n)
class Solution {
public:
   
    //CLASSIC 0/1 KNAPSACK PROBLEM
    //At every step we can either include or exclude

    int solve(int idx, int time, int n, vector<int>& satisfaction){

        /*BASE CONDITION: We are out of index, hence return 0*/
        if(idx >= n){
            return 0;
        }
        
        /*Like 0/1 Knapsack at every step we can ether include or exclude.
        Every element is associated with some cost, here it is given as satisfaction vector.
        We are just making a decision like include or exclude at every step.
        And then take the maximum of both as we want to maximize the like-time coefficient*/
        int include = satisfaction[idx]*time + solve(idx+1, time+1, n, satisfaction);

        int exclude = solve(idx+1, time, n, satisfaction);

        return max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        /*We sort the satisfaction array so that we get the 
        biggest values at the end and smallest values at the start.
        We want to maximize the like-time coefficient, hence we 
        would want to multiply the biggest satisfaction with biggest time, hence we sort the input array.
        */
        sort(begin(satisfaction), end(satisfaction));
       
        //We start with index=0 and time=1
        return solve(0,1,n,satisfaction);
    }
};

//Recursion + Memo
//TC = O(n^2)

class Solution {
public:
   
    //CLASSIC 0/1 KNAPSACK PROBLEM
    //At every step we can either include or exclude

    int dp[501][501];

    int solve(int idx, int time, int n, vector<int>& satisfaction){

        /*BASE CONDITION: We are out of index, hence return 0*/
        if(idx >= n){
            return 0;
        }

        if(dp[idx][time] != -1){
            return dp[idx][time];
        }
        
        /*Like 0/1 Knapsack at every step we can ether include or exclude.
        Every element is associated with some cost, here it is given as satisfaction vector.
        We are just making a decision like include or exclude at every step.
        And then take the maximum of both as we want to maximize the like-time coefficient*/
        int include = satisfaction[idx]*time + solve(idx+1, time+1, n, satisfaction);

        int exclude = solve(idx+1, time, n, satisfaction);

        return dp[idx][time] = max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        /*We sort the satisfaction array so that we get the 
        biggest values at the end and smallest values at the start.
        We want to maximize the like-time coefficient, hence we 
        would want to multiply the biggest satisfaction with biggest time, hence we sort the input array.
        */
        sort(begin(satisfaction), end(satisfaction));

        memset(dp,-1,sizeof(dp));
       
        //We start with index=0 and time=1
        return solve(0,1,n,satisfaction);
    }
};
