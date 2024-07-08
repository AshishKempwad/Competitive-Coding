//Backtracking TC : O(2^T * n)
class Solution {
public:

   void solve(vector<int>& candidates, int idx, int target, int n,vector<int>&temp,vector<vector<int>>&res){
      if(idx >= n || target < 0){
        return;
      }

      if(target == 0){
        res.push_back(temp);
        return;
      }
 
      //Backtracking Classical Logic
      //1. Do Something
      temp.push_back(candidates[idx]);
  
      //2. Explore
      solve(candidates,idx,target-candidates[idx],n,temp,res); //The important thing is : The same number may be chosen unlimited times

      //3. Undo
      temp.pop_back();

      //4.Explore again
      solve(candidates,idx+1,target,n,temp,res);


   }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>temp;
        vector<vector<int>>res;
        solve(candidates,0,target,n,temp,res);

        return res;
    }
};




