//Recursion
class Solution {
public:
    int solve(int i, int j, string text1, string text2){
        /*If length of any string has reached out of index, that means that string is empty
        Hence we will return 0. As there would be 0 common subsequence 
        between a string and empty string or between 2 empty strings*/

        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if(text1[i] == text2[j]){
            return 1 + solve(i+1, j+1, text1, text2);
        }else{
            return max(solve(i+1, j, text1, text2), solve(i, j+1, text1, text2));
        }

    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(0,0,text1,text2);
    }
};

//Recursion + Memo
class Solution {
public:

    int dp[1001][1001];

    int solve(int i, int j, string& text1, string& text2){
        /*If length of any string has reached out of index, that means that string is empty
        Hence we will return 0. As there would be 0 common subsequence 
        between a string and empty string or between 2 empty strings*/

        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, text1, text2);
        }else{
            return dp[i][j] = max(solve(i+1, j, text1, text2), solve(i, j+1, text1, text2));
        }

    }

    int longestCommonSubsequence(string text1, string text2) {
        cout<<text1.size()<<text2.size()<<endl;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);
    }
};
