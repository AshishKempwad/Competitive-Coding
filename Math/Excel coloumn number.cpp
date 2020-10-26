//Given a column title A as appears in an Excel sheet, return its corresponding column number.
int Solution::titleToNumber(string A) 
{
    int res=0;
    int power=0;
    
    int n = A.size();
    for(int i=n-1;i>=0;i--)
    {
        res = res+(A[i]-64)*pow(26,power);
        power++;
    }
    
    return res;
}
