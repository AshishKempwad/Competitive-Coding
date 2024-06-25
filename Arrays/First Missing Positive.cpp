class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        //Watch Aditya Verma for logic
        
        //Use swap sort technique
        int n = nums.size();
        int i=0;
        while(i < n)
        {
            if(nums[i]>0 && nums[i]<n && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
            else
            {
                i++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
    
};
-------------------------------------------------------------------------
    //Approach 2 : TC = O(n) and SC = (1) - using index based approach when range [1,n]
    class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        //1. We are interested only with numbers in range [1,n]. Hence for all negative numbers and numbers greater than n will be marked with "1" - Some special marker
        //Hence now in array we have all the numbers in range of [1,n]
        for(int i=0;i<n;i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n+1;
            }
        }
        
        //2. Mark each cell appearing in the array by converting the index for number given to negative
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            int idx = num - 1;

            //3. Avoid marking the already marked elements 
            if(idx < n && nums[idx] > 0){
                nums[idx] = nums[idx]*-1;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] >= 0){
                //4. We have found first non marked/visited element and that is our answer.
                return i+1;
            }
        }
       
       //5. If all numbers [1,n] are present we return n+1
        return n+1;

    }
};
