/* TC = O(nlogn) + O(n^2*logn) = O(n^2*logn)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4){
            return {};
        }

        sort(begin(nums),end(nums));
        vector<vector<int>>res;

        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                long long newTarget = (long long)target - (long long) nums[i] - (long long)nums[j];
                int l = j+1;
                int r = n-1;

                while(l<r){
                    if(nums[l]+nums[r] < newTarget){
                        l++;
                    }else if(nums[l]+nums[r] > newTarget){
                        r--;
                    }else{
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            l++;
                        }
                        while(l<r && nums[r] == nums[r-1]){
                            r--;
                        }
                        l++;
                        r--;
                    }
                }

            }
        }

        return res;

    }
};
