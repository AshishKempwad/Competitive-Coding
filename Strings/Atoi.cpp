/*There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?*/
//IB solution
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
----------------------------------------------------------------------------------------------------
    //Leetcode solution to even handle whitespaces before starting of any literal
    /*
    
    Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists 
because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 

Example 1:

Input: str = "42"
Output: 42
Example 2:

Input: str = "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign. 
Then take as many numerical digits as possible, which gets 42.


*/
    class Solution {
public:
    int myAtoi(string s)
    {
        long long int res=0;
        bool flag=false;
        int i=0;
        int n=s.size();
        if(s[i]==' ')
        {
            while(s[i]==' ')
            {
               i++;
            }
        }
        
        if(s[i]=='-')
        {
            flag=true;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        
        for(;i<n;i++)
        {
          
            int temp = s[i]-'0';
            if(temp>=0 && temp<=9)
            {
                res = res*10 + temp;
            }
            else
            {
                break;
            }
            if(res > INT_MAX)
           {
                if(flag==true)
                {
                    return INT_MIN;
                }
                return INT_MAX;
           }
        }

        if(res==0)
        {
            return 0;
        }
        if(flag==true)
        {
            res=(-1)*res;
        }
        
        return res;
    }
};
