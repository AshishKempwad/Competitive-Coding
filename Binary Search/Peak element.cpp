class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1)
        {
            return 0;
        }
        int l = 0;
        int h = nums.size()-1;
        
        while(l <= h)
        {
            int mid = l +(h-l)/2;
            if(mid > 0 && mid <n-1 ) // not the corner elements
            {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                {
                    return mid;
                }
                else if(nums[mid-1] > nums[mid])
                {
                    h = mid -1 ;
                    
                }
                else
                {
                    l = mid+1;
                }
            }
            
            else if(mid==0)//corner case, element at index 0, must be compared with only one element, that is one to the left of it.
            {
                    if(nums[0] > nums[1])
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                    
               
            }
            else if(mid == n-1)
            {
                if(nums[n-1] > nums[n-2])
                {
                    return n-1;
                }
                else
                {
                    return n-2;
                }
            }
        }
        
        return -1;
        
        
    }
};
