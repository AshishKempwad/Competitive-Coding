/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
objects of the same color are adjacent, with the colors in the order red, white, and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Follow up:
Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/


//Two pass solution

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
       int n = nums.size();
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                cnt1++;
            }
            else if(nums[i]==1)
            {
                cnt2++;
            }
            else
            {
                cnt3++;
            }
        }
        
        int k=0;
        while(cnt1>0)
        {
            nums[k++]=0;
            cnt1--;
        }
        while(cnt2>0)
        {
            nums[k++]=1;
            cnt2--;
        }
        while(cnt3>0)
        {
            nums[k++]=2;
            cnt3--;
        }
    }
};

-------------------------------------------------------------------------------------
//One pass solution

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        
        // Idea, derived from quicksort of puting elements at the correct position
        
        int start=0;   // keeps track where 0 has to go
        int index=0;   // keeps moving
        int end=nums.size()-1;  // keeps track where 2 has to go
        
        while(index <=end && start<end)
        {
            if(nums[index]==0)
            {
                swap(nums[index],nums[start]);
                index++;
                start++;
            }
            else if(nums[index]==2)
            {
                swap(nums[index],nums[end]);
                end--;    // we dont move index here because we dont know with what we are swapping 2, it could happen that we might be swapping with 2 sitting at the back
            }
            else
            {
                index++;    // whenever we see a 1, we just skip
            }
        }
    }
};
