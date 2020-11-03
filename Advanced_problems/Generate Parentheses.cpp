//*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    
    vector<string>res;
    
    void helper(string str,int left,int right)
    {
        if(left)
        {
            helper(str+'(',left-1,right);
        }
        if(right>left)
        {
            helper(str+')',left,right-1);
        }
        if(!right)
        {
            res.push_back(str);
        }
    }
    
    
    vector<string> generateParenthesis(int n) 
    {
        helper("",n,n);
        return res;
    }
};

 
