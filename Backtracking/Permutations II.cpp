class Solution {
public:

    void solve(vector<int>& nums,int n,vector<int>&temp,vector<vector<int>>&res,vector<bool>&vis){
         if(temp.size() == n){
            res.push_back(temp);
            return;
         }

         for(int i=0;i<n;i++){
            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])){
                continue;
            }

            //Do something
            vis[i] = true;
            temp.push_back(nums[i]);

            //Explore
            solve(nums,n,temp,res,vis);


            //Undo
            vis[i]=false;
            temp.pop_back();
         }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>res;
        vector<bool>vis(n,false);
        sort(nums.begin(),nums.end());

        solve(nums,n,temp,res,vis);

        return res;
    }
};
