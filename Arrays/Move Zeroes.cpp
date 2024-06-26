class Solution {
public:

    // Similar to sort colors using 2 pointer approach
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for(int right=0;right<nums.size();right++){
            if(nums[right] != 0){
                swap(nums[left],nums[right]);
                left++;
            }
        }
    }
};
