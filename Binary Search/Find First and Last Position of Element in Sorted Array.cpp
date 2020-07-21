class Solution {
public:
   int firstocc(vector<int>& nums, int target)
   {
       int l = 0;
       int h = nums.size()-1;
       int res = -1;
       
       while(l <= h)
       {
           int mid = l +(h-l)/2;
           if(nums[mid] == target)
           {
               res = mid;
               h = mid-1;
           }
           else if(target > nums[mid])
           {
               l = mid+1;
           }
           else if(target < nums[mid])
           {
               h = mid-1;
           }
       }
       
       return res;
   }
    
    
    
    int lastocc(vector<int>& nums, int target)
   {
       int l = 0;
       int h = nums.size()-1;
       int res = -1;
       
       while(l <= h)
       {
           int mid = l +(h-l)/2;
           if(nums[mid] == target)
           {
               res = mid;
               l = mid+1;
           }
           else if(target > nums[mid])
           {
               l = mid+1;
           }
           else if(target < nums[mid])
           {
               h = mid-1;
           }
       }
       
       return res;
   }
    
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
         vector<int>res;
       int first = firstocc(nums,target);
       int last = lastocc(nums,target);
        res.push_back(first);
        res.push_back(last);
        return res;
        
    }
};
