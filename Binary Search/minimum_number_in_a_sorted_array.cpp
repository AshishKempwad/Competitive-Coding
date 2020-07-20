//This problem is the minor variation of 'Number of times a sorted array is rotated 


int minNumber(int arr[], int low, int high)
{
    int N = high+1;
    int pivot=-1;
   while(low <= high)
   {
       
       if(arr[low]<=arr[high]) //this means the entire array is already sorted hence return the first index
       {
           return arr[low];
       }
       
       int mid = low + (high - low)/2;
       int prev = (mid +N -1)%N;  //to handle out of bound for left index(index 0)
       int nex = (mid + 1)%N;  // to handle out of bound for right index(index n-1)
       
       if(arr[mid] <= arr[prev] && arr[mid] <= arr[nex])
       {
           pivot = arr[mid];
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
    // Your code here
    
}
