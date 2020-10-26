int reverse(int n)
{
    int res = 0;
    while(n>=0)
    {
      res = res*10+n%10;
      n=n/10;
    }
    return res;
}


int Solution::isPalindrome(int A)
{
    if(A==reverse(A))
    {
        return 1;
    }
    return 0;
    
}
