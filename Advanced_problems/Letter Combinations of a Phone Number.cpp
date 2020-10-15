
/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

*/



/*Complexity Analysis

    Time complexity : O(3N×4M)\mathcal{O}(3^N \times 4^M)O(3N×4M) where N is the number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), and N+M is the total number digits in the input.

    Space complexity : O(3N×4M)\mathcal{O}(3^N \times 4^M)O(3N×4M) since one has to keep 3N×4M3^N \times 4^M3N×4M solutions.

*/


class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        
        if(digits.size()==0)
        {
            return {};
        }
        
        vector<string> words = {" ", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        deque<string>q;
        q.push_back("");
        
        for(auto x : digits)
        {
            int d = x - '0';
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string token = q.front();
                q.pop_front();
                
                for(char ch : words[d])
                {
                    q.push_back(token+ch);
                }
            }
        }
        vector<string>res(q.begin(),q.end());
        return res;
    }
};
