/*
Given arrival and departure times of all trains that reach a railway station. 
Your task is to find the minimum number of platforms required for the railway station so that no train waits.
Note: Consider that all the trains arrive on the same day and leave on the same day. 


Example:
Input:
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 


Output:
3
1


TC = O(nlogn)

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int testcases;
	cin>>testcases;
	
	while(testcases--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int dep[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>dep[i];
	    }
	  
	  
	    sort(arr,arr+n);
	    sort(dep,dep+n);
	    int minplatforms = 1;
	    int res=1;
	    
	    int i=1;
	    int j=0;
	    
	    while( i<n && j<n)
	    {
	        if(arr[i] <= dep[j])
	        {
	            minplatforms++;
	            i++;
	        }
	        else if(arr[i]>dep[j])
	        {
	            minplatforms--;
	            j++;
	        }
	        
	        res = max(res,minplatforms);
	    }
	  

	    cout<<res<<endl;
	}
	return 0;
}

----------------------------------------------------------------------------------

TC = O(n)
sc = O(n)

int minPlatform(int arrival[], int departure[], int n) 
{ 
  
    // as time range from 0 to 2359 in 24 hour clock, 
    // we declare an array for values from 0 to 2360 
    int platform[2361] = {}; 
    int requiredPlatform = 1; 
    for (int i = 0; i < n; i++) { 
  
        // increment the platforms for arrival 
        ++platform[arrival[i]];  
  
         // once train departs we decrease the platform count 
        --platform[departure[i] + 1]; 
    } 
  
    // We are running loop till 2361 because maximum time value 
    // in a day can be 23:60 
    for (int i = 1; i < 2361; i++) { 
  
        // taking cumulative sum of platform give us required 
        // number of platform fro every minute 
        platform[i] = platform[i] + platform[i - 1];  
        requiredPlatform = max(requiredPlatform, platform[i]); 
    } 
    return requiredPlatform; 
} 
