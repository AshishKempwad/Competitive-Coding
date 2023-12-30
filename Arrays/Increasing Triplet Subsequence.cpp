class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for(int i=0;i<n;i++){
            int num3 = nums[i];

            if(num3 <= num1){  //We always heck first with num1, and assign the lowest value to it
                num1 = num3;  
            }else if(num3 <= num2){ //We check for num2 if num1 has smallest value and assign num3 to num2
                num2=num3;
            }else{  //This means we have already found num1 and num2 which are smaller than num3 and hence we have found the triplet
                return true;
            }
        }
        return false;
    }
};
