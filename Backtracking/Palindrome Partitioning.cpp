//TC = O(2^n * n)

class Solution {
public:
   bool isPalindrome(string s, int low, int high){
    while(low < high){
        if(s[low] != s[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
   }
    void solve(string s, int n, int start, vector<string>&temp, vector<vector<string>>&res){
        if(start >= n){
            res.push_back(temp);
            return;
        }

        for(int i=start;i<n;i++){
            if(isPalindrome(s,start,i)==true){
                temp.push_back(s.substr(start,i-start+1));
                solve(s,n,i+1,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string>temp;
        vector<vector<string>>res;

        solve(s,n,0,temp,res);
        return res;
    }
};
