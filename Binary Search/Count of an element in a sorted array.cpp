//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int findlast(int nums[], int n, int target){
	    int l=0;
	    int h=n-1;
	    int temp=-1;
	    
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(nums[mid]==target){
	            temp=mid;
	            l=mid+1;
	        }else if(nums[mid]>target){
	            h=mid-1;
	        }else{
	            l=mid+1;
	        }
	    }
	    
	    return temp;
	}	
		
	int findfirst(int nums[], int n, int target){
	    int l =0;
	    int h=n-1;
	    int temp = -1;
	    while(l<=h){
	        int mid = l +(h-l)/2;
	        if(nums[mid]==target){
	            temp = mid;
	            h=mid-1;
	        }else if(nums[mid] > target){
	            h=mid-1;
	        }else{
	            l=mid+1;
	        }
	    }
	    
	    return temp;
	}	
	int count(int arr[], int n, int x) {
	    int res = -1;
	    int firstOccurance = findfirst(arr,n,x);
	    int lastOccurance = findlast(arr,n,x);
	    if(firstOccurance == -1 && lastOccurance == -1){
	        return 0;
	    }  
	    
	    res = lastOccurance - firstOccurance + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
