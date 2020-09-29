int Solution::solve(string A)
{
    
    int i = 0;
    int j = A.size()-1;
    
    int change_allowed = 1;
    while(i <= j)
    {
        if(change_allowed < 0)
        {
            return 0;
        }
        
        if(A[i] == A[j])
        {
            i++;
            j--;
        }
        else
        {
            if(A[i] == A[j-1])
            {
                j--;
            }
            else if(A[i+1] == A[j])
            {
                i++;
            }
            
            change_allowed--;
        }
    }
    
    if(change_allowed < 0)
    {
        return 0;
    }
    
    return 1;
    
}
