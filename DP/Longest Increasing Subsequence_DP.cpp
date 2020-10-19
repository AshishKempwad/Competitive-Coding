
int Solution::lis(const vector<int> &A) 
{
    //DP solution
    //TC=O(n^2)
    
    vector<int>LIS(A.size());
    int n=A.size();
    
    if(n<=0)
    {
        return 0;
    }
    //Idea is to find the maximum lis till that point
    LIS[0]=1;
    for(int i=1;i<n;i++)
    {
        LIS[i]=1;
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
            {
                LIS[i]=max(LIS[i],LIS[j]+1);
            }
        }
    }
    
    int res=LIS[0];
    for(int i=1;i<n;i++)
    {
        res=max(res,LIS[i]);
    }
    return res;
} 
