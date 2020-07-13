class Solution {
public:
    
     //Now apply normal Maximum area Histogram solution 
    int Hist(vector<int>&arr,int n)
    {
        stack<pair<int,int>>s;
        vector<int>left;
        vector<int>right;
        
         for(int i=0;i<n;i++)                    //Next smallest element to left
         {
             while(!s.empty() && s.top().first >= arr[i])
             {
                 s.pop();
             }
             if(s.empty())
             {
                 left.push_back(-1);
             }
             else
             {
                 left.push_back(s.top().second);
             }
             
             s.push({arr[i],i});
         }
        
        while(!s.empty())      //clear stack
        {
            s.pop();
        }
        
        
        for(int i=n-1;i>=0;i--)     //Next smallest element to right
        {
            while(!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(s.top().second);
            }
            
            s.push({arr[i],i});
        }
        
        int area=0;
        int max_area=0;
        for(int i=0;i<n;i++)
        {
            area = arr[i]*(right[n-i-1] - left[i]-1);
            max_area = max(max_area,area);    
        }
        
        return max_area;
   
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        if(m==0)
        {
            return 0;
        }
        int n = matrix[0].size();
        vector<int>arr;
        arr.resize(n,0);
        int area_of_rect=0;
        int max_area_rect=0;
      
        for(int i=0;i<m;i++)   //convert 2d matrix in 1d matrix
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    arr[j]=0;
                }
                else
                {
                    arr[j]++;
                }
            }
            area_of_rect=Hist(arr,n);
            max_area_rect = max(max_area_rect,area_of_rect);
        }
        
        
      
        return max_area_rect;
        
    }
};
