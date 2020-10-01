class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A)
    {
        
        //Step 1. Find Maximum sum subarray using Kadane
        
        int n = A.size();
        int currmax = A[0];
        int overallmax = A[0];
        int total;
        for(int i=1;i<n;i++)
        {
            currmax = max(currmax+A[i] , A[i]);
           overallmax = max(currmax , overallmax);
        }
        
        //Step 2. If(overallsum < 0) return it
        
        if(overallmax < 0)
        {
            return overallmax;
            
        }
        
        //Step 3. Calculate total sum of array and Min sum array using Modified Kadane
        
        int currmin = A[0];
        int overallmin = A[0];
        int totalsum = A[0];
        

        for(int i=1;i<n;i++)
        {
            totalsum=totalsum+A[i];
            currmin = min(currmin+A[i] , A[i]);
            overallmin = min(currmin,overallmin); 
        }
        
        //Step 4. Difference between totalsum and overallmin 
        int diff = totalsum - overallmin;
        //Step 5. Return max of Step1 and Step4
        total = max(overallmax , diff);
        
        return total;
        
    }
};
