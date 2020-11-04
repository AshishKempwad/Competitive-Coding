/*
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

*/

class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1=="0" || num2=="0")
        {
            return "0";
        }
        vector<int>num(num1.size()+num2.size(),0);
        
        for(int i=num1.size()-1;i>=0;i--)
        {
            for(int j=num2.size()-1;j>=0;j--)
            {
                num[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                num[i+j]+=num[i+j+1]/10;
                num[i+j+1]=num[i+j+1]%10;
            }
        }
        
        int x=0;
        while(x<num.size() && num[x]==0)
        {
            x++;
        }
        
        string res="";
        while(x<num.size())
        {
            res.push_back(num[x]+'0');
            x++;
        }
        
        return res;
    }
};
