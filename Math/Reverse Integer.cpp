int Solution::reverse(int A)
{
    int n=abs(A);
    int res=0;
    
    while(n>0)
    {
        res=res*10+n%10;
        n=n/10;
    }
    
    if(A<0)
    {
        res=res*(-1);
    }
    
    if(res > INT_MAX || res < INT_MIN)
    {
        return 0;
    }
    return res;
}
