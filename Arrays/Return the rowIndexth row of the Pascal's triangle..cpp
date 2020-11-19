/*Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
Could you optimize your algorithm to use only O(k) extra space?
 
Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:
Input: rowIndex = 0
Output: [1]
*/

class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
       vector<int>res(rowIndex+1,1);
        long long int ans =1;
        for(int i=1;i<rowIndex;i++)
        {
            
            ans = ans*(rowIndex - i + 1) / i;     // 4C1 => 4/1 , 5C2 => 5*4/1*2 i.e we always have same numbers of elements in numerator and denominator
            res[i]=ans;
        }
        
        return res;
        
    }
};
