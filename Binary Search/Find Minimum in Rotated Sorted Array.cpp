class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        int l = 0;
        int h = n-1;

        while(l<=h){
            if(nums[l]<=nums[h]){
                return nums[l];
            }

            int mid = l + (h - l)/2;
            int prev = (mid + n - 1)%n;
            int next = (mid+1)%n;

            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                pivot = nums[mid];
                break;
            }
            else if(nums[l]<=nums[mid]){
                l=mid+1;
            }else if(nums[mid]<=nums[h]){
                h=mid-1;
            }
        }
        return pivot;
    }
};
