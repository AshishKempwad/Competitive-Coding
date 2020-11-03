/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Follow up: Could you solve it without converting the integer to a string?

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x<0)
        {
            return false;     //negative numbers can never be palindrome, as they "-121" is not same as "121-"
        }
        int y=x;
        long long int res=0;
        while(x)
        {
            res=res*10+x%10;
            x=x/10;
        }
        
        if(res==y)
        {
            return true;
        }
        return false;
    }
};
