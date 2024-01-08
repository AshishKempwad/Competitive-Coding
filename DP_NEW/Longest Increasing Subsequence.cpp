//Recursion

class Solution {
public:

    int solve(vector<int>& nums, int idx, int prev, int n){
        if(idx >= n){
            return 0;
        }

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1 + solve(nums,idx+1,idx,n);
        }
        int skip = solve(nums,idx+1,prev,n);

        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,-1,n);
    }
};


//Recursion + Memo
class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>& nums, int idx, int prev, int n){
        if(idx >= n){
            return 0;
        }
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1 + solve(nums,idx+1,idx,n);
        }
        int skip = solve(nums,idx+1,prev,n);

        if(prev != -1){
            dp[idx][prev] = max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1,n);
    }
};

//Best Solution : Using Patience Sorting TC = O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //Patience Sorting
        int n = nums.size();
        vector<int>sortedArray;

        for(int i=0;i<n;i++){
          auto it = lower_bound(begin(sortedArray),end(sortedArray),nums[i]); //Lower_bound gets the index of element just greater than or equal to current element.

          if(it == end(sortedArray)){            //If no such element exists
              sortedArray.push_back(nums[i]);    //Add the element in sortedArray
          }else{
              *it = nums[i];   //Else replace that element with the found element 
          } 
        }

        return sortedArray.size();
    }
};
