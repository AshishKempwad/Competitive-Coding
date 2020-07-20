class Solution {
public:
    
    int find_min_index(vector<int>& arr)
    {
        int low = 0;
        int high = arr.size()-1;
        int N = arr.size();
       int pivot=-1;
       while(low <= high)
       {

           if(arr[low]<=arr[high]) //this means the entire array is already sorted hence return the first index
           {
               return low;
           }

           int mid = low + (high - low)/2;
           int prev = (mid +N -1)%N;  //to handle out of bound for left index(index 0)
           int nex = (mid + 1)%N;  // to handle out of bound for right index(index n-1)

           if(arr[mid] <= arr[prev] && arr[mid] <= arr[nex])
           {
               pivot = mid;
               break;
           }
           else if(arr[low] <= arr[mid]) //left half is sorted to find in right half
           {
               low = mid + 1;
           }
           else if(arr[mid] <= arr[high])//right is sorted hence search in left half
           {
               high = mid - 1;
           }
       }

       return pivot;
    }
    
 int bs(vector<int>& arr,int l,int h, int target)
 {
     
     while(l<=h)
     {
         int mid = l +(h-l)/2;
         
         if(arr[mid]==target)
         {
             return mid;
         }
         else if(target > arr[mid])
         {
             l = mid+1;
         }
         else
         {
             h = mid-1;
         }
     }
     
     return -1;
 }
    
    
    int search(vector<int>& nums, int target)
    {
        
        int n = nums.size();
        if(n==0)
        {
            return -1;
        }
        int index = find_min_index(nums);
        
        int bin_on_left = 0;
        int bin_on_right = 0;
     
        bin_on_left = bs(nums,0,index-1,target);
        bin_on_right = bs(nums,index,n-1,target);
        
        if(bin_on_left!=-1 && bin_on_right==-1)
        {
            return bin_on_left;
        }
        else if(bin_on_left==-1 && bin_on_right!=-1)
        {
            return bin_on_right;
        }
        else
        {
            return -1;
        }           
        
    }
};
