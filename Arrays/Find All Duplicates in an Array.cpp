class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;

        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            int idx = num - 1;

            if(nums[idx] > 0){
                nums[idx] = nums[idx] * -1;
            }else{
                res.push_back(num);
            }

        }

        return res;
    }
};
