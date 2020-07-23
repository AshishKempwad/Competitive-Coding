class Solution {
public:
    bool isvalid(vector<int>& nums,int n, int m,int mid)
    {
        long long sum=0;
        int student=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mid)
            {
                return false;
            }
            
            sum = sum+nums[i];
            if(sum > mid)
            {
                student++;
                sum = nums[i];
            }
            
            if(student > m)
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    int splitArray(vector<int>& nums, int m) 
    {
        int n = nums.size();
        if(m > n)
        {
            return -1;
        }
        int res=-1;
        int max_ele=INT_MIN;
      for(int i=0;i<n;i++)
      {
          max_ele = max(max_ele,nums[i]);
      }
        long long overall_sum = 0;
        overall_sum = accumulate(nums.begin(),nums.end(),overall_sum);
        
        int l = max_ele;
        long long h = overall_sum;
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(isvalid(nums,n,m,mid)==true)
            {
                res = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return res;
        
    }
};
