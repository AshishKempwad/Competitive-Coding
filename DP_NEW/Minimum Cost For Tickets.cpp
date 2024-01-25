class Solution {
public:

    int solve(int i, int n, vector<int>& days, vector<int>& costs){
        /*BASE CONDITION:
        We have come out of index, hence returning 0*/
        if(i >= n){
            return 0;
        }
        
        /*We calculate the costs if we choose 1-day pass.
        costs[0] indicate the costs for 1 day pass.
        Then we add the cost for 1 day pass and call the function for next day from days vector.*/
        int costWithOneDayPass = costs[0] + solve(i+1,n,days,costs);


        /*We calculate the costs if we choose 7-day pass.
        costs[1] indicates the cost for 7 day pass.
        Then we add 7 days to the existing day. So we can travel those many consecutive days.
        We loop in with j till we reach all the days[j] less then max days that we can travel(ie 7 days from days[i]).
        All these days will be covered by the pass. Hence we add the cost and call function on next(i.e j'th index) */
        int maxDaysWithSevenDayPass = days[i] + 7;
        int j = i;
        while(j<n && days[j] < maxDaysWithSevenDayPass){
            j++;
        }
        int costWithSevenDayPass = costs[1] + solve(j,n,days,costs);


        /*We calculate the costs if we choose 30-day pass.
        costs[2] indicates the cost for 30 day pass.
        Then we add 30 days to the existing day. So we can travel those many consecutive days.
        We loop in with j from i till we reach all the days[j] less then max days that we can travel(ie 30 days from days[i])
        All these days will be covered by the pass. Hence we add the cost and call function on next(i.e j'th index) */
        int maxDaysWithThirtyDayPass = days[i] + 30;
        j=i;
        while(j<n && days[j] < maxDaysWithThirtyDayPass){
            j++;
        }
        int costWithThirtyDayPass = costs[2] + solve(j,n,days,costs);



        //Return the minimum of the three
        return min({costWithOneDayPass,costWithSevenDayPass,costWithThirtyDayPass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(0, n, days, costs);
    }
};

//Recursion + Memo
class Solution {
public:
   
    int dp[366];

    int solve(int i, int n, vector<int>& days, vector<int>& costs){
        /*BASE CONDITION:
        We have come out of index, hence returning 0*/
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        
        /*We calculate the costs if we choose 1-day pass.
        costs[0] indicate the costs for 1 day pass.
        Then we add the cost for 1 day pass and call the function for next day from days vector.*/
        int costWithOneDayPass = costs[0] + solve(i+1,n,days,costs);


        /*We calculate the costs if we choose 7-day pass.
        costs[1] indicates the cost for 7 day pass.
        Then we add 7 days to the existing day. So we can travel those many consecutive days.
        We loop in with j till we reach all the days[j] less then max days that we can travel(ie 7 days from days[i]).
        All these days will be covered by the pass. Hence we add the cost and call function on next(i.e j'th index) */
        int maxDaysWithSevenDayPass = days[i] + 7;
        int j = i;
        while(j<n && days[j] < maxDaysWithSevenDayPass){
            j++;
        }
        int costWithSevenDayPass = costs[1] + solve(j,n,days,costs);


        /*We calculate the costs if we choose 30-day pass.
        costs[2] indicates the cost for 30 day pass.
        Then we add 30 days to the existing day. So we can travel those many consecutive days.
        We loop in with j from i till we reach all the days[j] less then max days that we can travel(ie 30 days from days[i])
        All these days will be covered by the pass. Hence we add the cost and call function on next(i.e j'th index) */
        int maxDaysWithThirtyDayPass = days[i] + 30;
        j=i;
        while(j<n && days[j] < maxDaysWithThirtyDayPass){
            j++;
        }
        int costWithThirtyDayPass = costs[2] + solve(j,n,days,costs);



        //Return the minimum of the three
        return dp[i] = min({costWithOneDayPass,costWithSevenDayPass,costWithThirtyDayPass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, n, days, costs);
    }
};
