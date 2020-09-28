int Solution::lengthOfLastWord(const string A) 
{
    int n = A.size();
    int count=0;
    bool flag = true;
    for(int i=n-1;i>=0;i--)
    {
        if(A[i]!=' ')
        {
            count++;
            flag=false;
        }
        else 
        {
            if(flag == false)
            {
                break;
            }
        }
    }
    
    return count;
}
