int Solution::maxSubArray(const vector<int> &A)
{
    //Kadane's Algorithm
    
    int n = A.size();
    int result = A[0];
    int maxend = A[0];
    
    for(int i=1;i<n;i++)
    {
        maxend = max(maxend+A[i],A[i]);
        result = max(result,maxend);
       
    }
    return result;
    
   
}
