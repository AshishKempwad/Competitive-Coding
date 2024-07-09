class Solution {
public:

    //TC = O(n*n!)
   //We use extra unordered_set because we can find element using (st.find) in O(1) else in array we need O(n) time to check.
    void solve(vector<int>& nums, int n,unordered_set<int>&st, vector<int>&temp, vector<vector<int>>&res){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(st.find(nums[i]) == st.end()){

                //1.Do something
                st.insert(nums[i]);
                temp.push_back(nums[i]);

                //2. Explore
                solve(nums,n,st,temp,res);

                //3. Undo
                st.erase(nums[i]);
                temp.pop_back();

                //4. Explore further
                /* solve(nums,n,st,temp,res);  ---- We dont need to do the last step becuase we are already using for loop which does the same thing.
                We use for loop based approach for permutations, combinations, subsets based problems */
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        vector<int>temp;
        vector<vector<int>>res;

        solve(nums,n,st,temp,res);

        return res;
    }
};
