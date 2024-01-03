//Recursion

class Solution {
public:
    static bool cmp(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool isPredecessor(string &prevWord, string &currWord){
            int n = prevWord.size();
            int m = currWord.size();

            if(m - n != 1){
                return false;
            }

            int i=0,j=0;
            while(i<n && j<m){
                if(prevWord[i] == currWord[j]){
                    i++;
                }
                j++;
            }

            if(i == n){
                return true;
            }

            return false;
    }

    int solve(int idx, int prev, vector<string>& words, int n){
        if(idx >= n){
            return 0;
        }

        int take = 0;
        if(prev == -1 || isPredecessor(words[prev],words[idx])){
            take = 1 + solve(idx+1,idx,words,n);
        }

        int skip = solve(idx+1,prev,words,n);

        return max(take,skip);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words),end(words),cmp);
        return solve(0,-1,words,n);
    }
};

//Recursion + Memo
class Solution {
public:
    
    int dp[1001][1001];
    static bool cmp(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool isPredecessor(string &prevWord, string &currWord){
            int n = prevWord.size();
            int m = currWord.size();

            if(m - n != 1){   //The size of currWord should be exactly 1 greater than prevWord
                return false;
            }

            int i=0,j=0;
            while(i<n && j<m){
                if(prevWord[i] == currWord[j]){
                    i++;
                }
                j++;
            }

            if(i == n){   //prevWord is subsequence of currWord
                return true;
            }

            return false;
    }

    int solve(int idx, int prev, vector<string>& words, int n){
        if(idx >= n){
            return 0;
        }

        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }

        int take = 0;
        if(prev == -1 || isPredecessor(words[prev],words[idx])){
            take = 1 + solve(idx+1,idx,words,n);
        }

        int skip = solve(idx+1,prev,words,n);

        if(prev != -1){
            dp[idx][prev] = max(take,skip);
        }
        return max(take,skip);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words),end(words),cmp);   //Sorting based on the length of words
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,words,n);
    }
};
