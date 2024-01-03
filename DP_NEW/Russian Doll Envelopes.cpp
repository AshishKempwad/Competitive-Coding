//Recursion

class Solution {
public:
    
    
    int solve(int idx, int prev, int n, vector<vector<int>>& envelopes){
        if(idx >= n){
            return 0;
        }

        int take = 0;
        if(prev == -1 || (envelopes[idx][0] > envelopes[prev][0] && envelopes[idx][1] > envelopes[prev][1])){
            take = 1 + solve(idx+1,idx,n,envelopes);
        }

        int skip = solve(idx+1,prev,n,envelopes);

        return max(take,skip);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(begin(envelopes), end(envelopes));
        return solve(0,-1,n,envelopes);
    }
};

//Recursion + Memo

//Failing with DP
