int Solution::atoi(const string A)
{
    long long int res = 0;
    bool flag = false;
    int i=0;
    if(A[0]=='-')
    {
        flag = true;
        i++;
    }
    if(A[0]=='+')
    {
        i++;
    }
    for(;i<A.size();i++)
    {
        int temp = A[i] - '0';
        if(temp >= 0 && temp <= 9)
        {
            res = res*10 + temp;
        }
        else
        {
            break;
        }
        
        if(res > INT_MAX)
        {
            if(flag == true)
            {
                return INT_MIN;
            }
            
            return INT_MAX;
        }
    }
    if(flag == true)
    {
        return (-1) * res;
    }
    
    return res;
}
