/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
You need to return the number of important reverse pairs in the given array.

Example1:
Input: [1,3,2,3,1]
Output: 2

Example2:
Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.

*/

// TC = 0(nlogn)
// SC = O(n)

class Solution {
public:
    
    int merge(vector<int>&nums,vector<int>&temp,int l,int mid,int r)
    {
        int reverse_pairs=0;
        // int i=l;
        int k=l;
        int j=mid;
        
        for(int i=l;i<mid;i++)    //Only this is the extra step rather than normal mergesort
        {
           
            while(j<=r && nums[i] > 2LL*nums[j])   // LL has been added to handle overflow condition
            {
                j++;
            }
            reverse_pairs+=(j-mid);
        }
        
        int i=l;
        j=mid;
        
        while(i<=(mid-1) && j<=r)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        
        while(i<=(mid-1))
        {
            temp[k++]=nums[i++];
        }
        while(j<=r)
        {
            temp[k++]=nums[j++];
        }
        
        for(int y=l;y<=r;y++)
        {
            nums[y]=temp[y];
        }
        
        return reverse_pairs;
    }
    
    
    int mergesort(vector<int>&nums,vector<int>&temp,int l,int r)
    {
        int reverse_pairs = 0;
        int mid;
        if(l<r)
        {
            mid = (l+r)/2;
            reverse_pairs+=mergesort(nums,temp,l,mid);
            reverse_pairs+=mergesort(nums,temp,mid+1,r);
            reverse_pairs+=merge(nums,temp,l,mid+1,r);
        }
        return reverse_pairs;
    }
    
    
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        vector<int>temp(n);
        return mergesort(nums,temp,0,n-1);
    }
};
