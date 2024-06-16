class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        long maxReachable = 0;
        int patches = 0;
        int i = 0;


        while(maxReachable < n){
            if(i < nums.size() && nums[i] <= maxReachable+1){
                maxReachable += nums[i];
                i++;
            }else{
                maxReachable += (maxReachable+1);
                patches++;
            }
        }

        return patches;

    }
};


//TC : O(max(l, logN))
//.   l = nums.size() 
