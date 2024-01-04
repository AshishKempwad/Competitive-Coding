class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(auto &x : nums){
            mp[x]++;
        }

        int totalOperations = 0;

        for(auto &ele : mp){
            int freq = ele.second;
            if(freq < 2){
                return -1;   //If there is an elemeny with only 1 occurance, then we cannot delete that element hence returning -1
            }

            totalOperations += freq/3;   //Divide the frequency by 3, if it is not the multiple of 3, then increase the count by 1 more
            if(freq % 3 != 0){
                totalOperations++;
            }
        }

        return totalOperations;
    }
};
