/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/


int Solution::compareVersion(string A, string B) 
{
    int n = A.size();
    int m = B.size();
    
    int i=0;
    int j=0;
    
    while(i<n || j<m)
    {
         unsigned long long int num1=0;
         unsigned long long int num2=0;
        while(i<n && A[i]!='.')
        {
            num1=num1*10+(A[i]-'0');
            i++;
        }
        
        while(j<m && B[j]!='.')
        {
            num2 = num2*10+(B[j]-'0');
            j++;
        }
        if(num1 != num2)
        {
           return num1 < num2 ? -1 : 1;
        }
        i++;
        j++;
      
    }
    return 0;
    
}
