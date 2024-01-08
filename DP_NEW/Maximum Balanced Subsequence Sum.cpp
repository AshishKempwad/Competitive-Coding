//Recursion
class Solution {
public:
    long long solve(int idx, int prev,vector<int>& nums, int n){
        if(idx >= n){
            return 0;   //No element hence sum is 0
        }

        int take = 0;
        if(prev == -1 || nums[idx] - idx >= nums[prev] - prev){  //Either its 1st element or follows the condition of being balanced
            take = nums[idx] + solve(idx+1,idx,nums,n);
        }
        int skip = solve(idx+1,prev,nums,n);

        return max<long long>(take,skip);

    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(begin(nums),end(nums));
        if(maxElement <= 0){ //To handle the negative testcases
            return maxElement;
        }
        return solve(0,-1,nums,n);
    }
};

//Recursion + Memo
class Solution {
public:
    int dp[4900][4900];
    long long solve(int idx, int prev,vector<int>& nums, int n){
        if(idx >= n){
            return 0;   //No element hence sum is 0
        }
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        int take = 0;
        if(prev == -1 || nums[idx] - idx >= nums[prev] - prev){  //Either its 1st element or follows the condition of being balanced
            take = nums[idx] + solve(idx+1,idx,nums,n);
        }
        int skip = solve(idx+1,prev,nums,n);
        
        if(prev != -1){
            dp[idx][prev] = max<long long>(take,skip);
        }
        return max<long long>(take,skip);

    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(begin(nums),end(nums));
        if(maxElement <= 0){ //To handle the negative testcases
            return maxElement;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums,n);
    }
};

//Fails to pass all testcases even with DP. Optimal Solution TC = O(nlogn)

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long>mp;  //{nums[i]-i, sum}
        long long result = INT_MIN;

        for(int i=0;i<n;i++){
            auto it = mp.upper_bound(nums[i]-i);   //We need to find the smaller element hence we decrement it further
            long long sum = nums[i];

            if(it != mp.begin()){      //If its not the first element
                it--;                  //We decrement because we need to find the smaller element from map
                sum += it->second;     //Add its sum to the current sum
            }

            mp[nums[i]-i] = max(mp[nums[i]-i],sum);

            it = mp.upper_bound(nums[i]-i);  //Need to find and delete all suach elements from map which are larger than current element and have their sum less than or equal to current element

            while(it != mp.end()  && it->second <= sum){
                mp.erase(it++);
            }
            result = max(result, sum);
        }
        return result;
    }
};
