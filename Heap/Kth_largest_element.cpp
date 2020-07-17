class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n=nums.size();
           //minheap
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i=0;i<n;i++)
        {
            minheap.push(nums[i]);
            if(minheap.size() > k)
            {
                minheap.pop();
            }
        }
        
        return minheap.top();
        
    }
};
