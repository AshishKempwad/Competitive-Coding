class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int n = arr.size();
        vector<int>res;
        priority_queue<pair<int,int>>maxheap;
        for(int i=0;i<n;i++)
        {
            maxheap.push({abs(x-arr[i]),arr[i]});
            if(maxheap.size() > k)
            {
                maxheap.pop();
            }
        }
        
        while(!maxheap.empty())
        {
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};
