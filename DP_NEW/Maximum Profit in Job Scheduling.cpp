//Recursion

class Solution {
public:
   
    int getValidNextJobIndex(vector<vector<int>>&matrix, int n, int l, int currentJobEndTime){
        int h = n-1;

        /*Considering initially dummy result with values n or n+1
        If we dont find the job with startTime >= endTime of prev job then we to send out of bound index 
        and we have searched all index and we dont have such a job or all jobs are over searching*/
        int result = n + 1;  

        while(l <= h){
            int mid = l + (h - l)/2;

            if(matrix[mid][0] >= currentJobEndTime){  //We can consider this job. We update the result with this index. And the we search in left half (need remove duplications also)
                h = mid -1;
                result = mid;
            }else{
                l = mid + 1;  //Havent found the job index, hence search in right half
            }
        }
        return result;
    }

    int solve(int idx, int n, vector<vector<int>>&matrix){

        if(idx >= n){
            return 0;
        }
        
        /*We can only include when the next job's startTime >= endTime
        We pass matrix, starting_Index and endIndex to getValidNextJobIndex function
        It will get us the next job with starting index greater than or equal to the end of current job by using binary search.
        We can use binary search as the matrix is sorted.
        Here we need to find element who's startTime >= matrix[idx][1] -- (matrix[idx][1] represnts endTime of current job)
        We can alternatively also use "lower_bound" function rather than binary search */

        int nextJobIndexPossible = getValidNextJobIndex(matrix, n, idx+1, matrix[idx][1]);
        int taken = matrix[idx][2] + solve(nextJobIndexPossible,n,matrix);

        int notTaken = solve(idx+1,n,matrix);

        return max(taken, notTaken);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        /*Storing the given 3 vectors in {startTime, endTime, profit} format*/
        vector<vector<int>>matrix(n,vector<int>(3,0));
        
        for(int i=0;i<n;i++){
            matrix[i][0] = startTime[i];
            matrix[i][1] = endTime[i];
            matrix[i][2] = profit[i];
        }

       /*Sorting based on startTime
       By default sorting is done based on first parameter, hence no need to write comparator.
       But we are writing it jjust for our practice*/

        sort(begin(matrix),end(matrix));        
        return solve(0,n,matrix);
    }
};

//Recursion + Memo

class Solution {
public:
   
   int dp[500001];  //As only 1 element is changing

    int getValidNextJobIndex(vector<vector<int>>&matrix, int n, int l, int currentJobEndTime){
        int h = n-1;

        /*Considering initially dummy result with values n or n+1
        If we dont find the job with startTime >= endTime of prev job then we to send out of bound index 
        and we have searched all index and we dont have such a job or all jobs are over searching*/
        int result = n + 1;  

        while(l <= h){
            int mid = l + (h - l)/2;

            if(matrix[mid][0] >= currentJobEndTime){  //We can consider this job. We update the result with this index. And the we search in left half (need remove duplications also)
                h = mid -1;
                result = mid;
            }else{
                l = mid + 1;  //Havent found the job index, hence search in right half
            }
        }
        return result;
    }

    int solve(int idx, int n, vector<vector<int>>&matrix){

        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        /*We can only include when the next job's startTime >= endTime
        We pass matrix, starting_Index and endIndex to getValidNextJobIndex function
        It will get us the next job with starting index greater than or equal to the end of current job by using binary search.
        We can use binary search as the matrix is sorted.
        Here we need to find element who's startTime >= matrix[idx][1] -- (matrix[idx][1] represnts endTime of current job)
        We can alternatively also use "lower_bound" function rather than binary search */

        int nextJobIndexPossible = getValidNextJobIndex(matrix, n, idx+1, matrix[idx][1]);
        int taken = matrix[idx][2] + solve(nextJobIndexPossible,n,matrix);

        int notTaken = solve(idx+1,n,matrix);

        return dp[idx] = max(taken, notTaken);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        /*Storing the given 3 vectors in {startTime, endTime, profit} format*/
        vector<vector<int>>matrix(n,vector<int>(3,0));
        
        for(int i=0;i<n;i++){
            matrix[i][0] = startTime[i];
            matrix[i][1] = endTime[i];
            matrix[i][2] = profit[i];
        }

       /*Sorting based on startTime
       By default sorting is done based on first parameter, hence no need to write comparator.
       But we are writing it just for our practice*/

       auto cmp = [&](auto &vec1, auto &vec2){
           return vec1[0] <= vec2[0];
       };

        sort(begin(matrix),end(matrix), cmp);


        memset(dp,-1,sizeof(dp));
        return solve(0,n,matrix);
    }
};
