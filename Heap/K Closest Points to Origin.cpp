class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
       int n = points.size();
        priority_queue<pair<int,pair<int,int>>> maxheap;
        for(int i=0;i<n;i++)
        {
            maxheap.push({points[i][0]*points[i][0] + points[i][1]*points[i][1] , {points[i][0],points[i][1]}});
            if(maxheap.size() > K)
            {
                maxheap.pop();
            }
        }
        
        vector<vector<int>>res(K);
        int i=0;
        while(!maxheap.empty())
        {
            res[i].push_back(maxheap.top().second.first);
            res[i].push_back(maxheap.top().second.second);
            i++;
            maxheap.pop();
        }
        
        return res;
        
    }
};
