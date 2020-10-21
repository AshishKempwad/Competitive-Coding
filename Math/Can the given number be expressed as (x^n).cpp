int Solution::isPower(int A) 
{
    if(A==1)
    {
        return 1;
    }
    
    for(int i=2;i*i<=A;i++)
    {
        int p=1;
        
        while(p>=1 && pow(i,p)<=A)
        {
            if(pow(i,p)==A)
            {
                return 1;
            }
            p++;
        }
    }
    
    return 0;
}
