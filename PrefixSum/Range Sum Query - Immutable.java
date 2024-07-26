class NumArray {

    int[] preSum;

    public NumArray(int[] nums) {
        preSum = nums;

        for(int i=1;i<nums.length;i++){   //Construct prefix sum
            preSum[i] += preSum[i-1];
        }
    }
    
    public int sumRange(int left, int right) {
        if(left == 0){
            return preSum[right];   //If left is 0, then directly right as it would have sum of all the values from 0
        }

        return preSum[right] - preSum[left-1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
