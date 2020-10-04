int Solution::majorityElement(const vector<int> &A) 
{
    
    //Moore's Voting Algorithn
    
    int res = 0;
    int count = 1;
    
    
    //STEP 1:
    
    for(int i=1;i<A.size();i++)
    {
        if(A[res] == A[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        
        if(count == 0)
        {
            res = i;
            count = 1;
        }
    }
    
    //STEP 2:
    count=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[res] == A[i])
        {
            count++;
        }
    }
    
    if(count > A.size()/2)
    {
        return A[res];
    }
    
    return -1;
}
