class Solution {
public:
    int largestRectangleArea(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>right;
        vector<int>left;
        stack<pair<int,int>>s;
      
     
        
        for(int i=n-1;i>=0;i--)  // Next smallest element to right
       {
            while(!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                right.push_back(n);  //pseudo index
            }
            else
            {
                right.push_back(s.top().second);
            }

            s.push({arr[i],i});
      }
        
        
        while(!s.empty())
        {
            s.pop();
        }
        
        for(int i=0;i<n;i++)   //Next smallest element to left
       {
            while(!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                left.push_back(-1);  //pseudo index
            }
            else
            {
                left.push_back(s.top().second);
            }

            s.push({arr[i],i});
       } 
        
        
        
    int area=0;
    int max_area=0;
    for(int i=0;i<n;i++)
    {
        area=arr[i]*(right[n-1-i]-left[i]-1);
        max_area=max(area,max_area);
    }
    return max_area;
    

    }
};
