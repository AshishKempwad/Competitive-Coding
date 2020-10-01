int Solution::maxArr(vector<int> &A) 
{
    
    // Brute Force
    
    int n= A.size();
    int res = INT_MIN;
    int curr;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
             curr=abs(A[i]-A[j])+abs(i-j);
             res = max(res,curr);
        }
    }
    return res;
    
    
    
    //Optimal solution
    
    int n = A.size();
    int max1=INT_MIN;
    int min1 = INT_MAX;
    int max2 = INT_MIN;
    int min2=INT_MAX;
    int res;
    for(int i=0;i<n;i++)
    {
        if(A[i]+i > max1)
        {
            max1=A[i]+i;
        }
        if(A[i]+i < min1)
        {
            min1=A[i]+i;
        }
        if(A[i]-i > max2)
        {
            max2 = A[i]-i;
        }
        if(A[i]-i < min2)
        {
            min2 = A[i]-i;
        }
    }
    
    res = max(max1-min1,max2-min2);
    return res;
}
