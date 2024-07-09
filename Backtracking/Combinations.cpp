//Tc :  //TC = O(nCk) = (n!)/(n-k)!*k!
//Approach 1 :

class Solution {
public:

    void solve(int n, int k, int idx, vector<int>&temp,vector<vector<int>>&res){
        if(k == 0){
            res.push_back(temp);
            return;
        }

        if(idx > n){
            return;
        }

        temp.push_back(idx);
        solve(n,k-1,idx+1,temp,res);

        temp.pop_back();
        solve(n,k,idx+1,temp,res);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>res;

        solve(n,k,1,temp,res);
        return res;
    }
};



//Approach 2 : Same logic but with for loop

    void solve(int n, int k, int start, vector<int>&temp,vector<vector<int>>&res){
        if(k == 0){
            res.push_back(temp);
            return;
        }

        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solve(n,k-1,i+1,temp,res);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>res;

        solve(n,k,1,temp,res);
        return res;
    }

