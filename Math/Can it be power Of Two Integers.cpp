/*



Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 


*/
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
