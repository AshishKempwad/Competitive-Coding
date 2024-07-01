//Recursion : TC =O(n * 2^n)

class Solution {
public:
   
    unordered_set<string>st;

    bool solve(int idx, int n, string &s){
        if(idx >= n){
            return true;
        }
        if(st.find(s) != st.end()){
            return true;
        }

        for(int i=1;i<=n;i++){

            string temp = s.substr(idx,i);

            if(st.find(temp) != st.end() && solve(idx+i,n,s))
            {
                return true;
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
       for(auto &word : wordDict){
        st.insert(word);
       }

       return solve(0,n,s);   
    }
};


//Recursion + Memo
class Solution {
public:
   
    unordered_set<string>st;
    int dp[301];

    bool solve(int idx, int n, string &s){
        if(idx >= n){
            return true;
        }
        if(st.find(s) != st.end()){
            return true;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        for(int i=1;i<=n;i++){

            string temp = s.substr(idx,i);

            if(st.find(temp) != st.end() && solve(idx+i,n,s))
            {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

       for(auto &word : wordDict){
        st.insert(word);
       }

       memset(dp,-1,sizeof(dp));
       return solve(0,n,s);   
    }
};
