//Recursion
class Solution {
public:

    bool solve(string s, string p, int strIdx, int pattIdx){
        if(strIdx < 0 && pattIdx < 0){
            return true;
        }
        if(strIdx >= 0 && pattIdx < 0){
            return false;    //No pattern remaining to match
        }
        if(strIdx < 0 && pattIdx >= 0){   //String is empty but pattern is present (it could be * - it can also be null)
              for(int i=0;i<=pattIdx;i++){
                if(p[i] != '*'){
                    return false;
                }
              }
              return true;
        }

        if(s[strIdx] == p[pattIdx] || p[pattIdx] == '?'){
            return solve(s,p,strIdx-1,pattIdx-1);
        }
        if(p[pattIdx] == '*'){ // '*' - can match with either 0 or more characters
            return solve(s,p,strIdx-1,pattIdx) || solve(s,p,strIdx,pattIdx-1);
        }

        return false;

    }
    bool isMatch(string s, string p) {
        int stringSize = s.size();
        int patternSize = p.size();

        return solve(s,p,stringSize-1,patternSize-1);
    }
};

//Recursion + Memo

class Solution {
public:
  
    int dp[2001][2001];

    bool solve(string &s, string &p, int strIdx, int pattIdx){
        if(strIdx < 0 && pattIdx < 0){
            return true;
        }
        if(strIdx >= 0 && pattIdx < 0){
            return false;    //No pattern remaining to match
        }
        if(strIdx < 0 && pattIdx >= 0){   //String is empty but pattern is present (it could be * - it can also be null)
              for(int i=0;i<=pattIdx;i++){
                if(p[i] != '*'){
                    return false;
                }
              }
              return true;
        }

        if(dp[strIdx][pattIdx] != -1){
            return dp[strIdx][pattIdx];
        }

        if(s[strIdx] == p[pattIdx] || p[pattIdx] == '?'){
            return dp[strIdx][pattIdx] = solve(s,p,strIdx-1,pattIdx-1);
        }
        if(p[pattIdx] == '*'){ // '*' - can match with either 0 or more characters
            return dp[strIdx][pattIdx] = solve(s,p,strIdx-1,pattIdx) || solve(s,p,strIdx,pattIdx-1);
        }

        return false;

    }
    bool isMatch(string s, string p) {
        int stringSize = s.size();
        int patternSize = p.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(s,p,stringSize-1,patternSize-1);
    }
};
