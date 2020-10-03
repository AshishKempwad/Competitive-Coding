/*Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j. 
Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).


Approach : Using mergesort.
          TC = O(nlogn)
          SC = O(n)
*/




#include <bits/stdc++.h>
using namespace std;



long int merge(int A[],int temp[],int l,int mid,int r)
{
    long int count=0;
    int i = l;
    int k = l;
    int j = mid;
    
    
    while( (i <= mid-1) && (j <= r))
    {
        if(A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            
            count = count +  (mid - i);
        }
    }
    
    while( i <= mid-1)
    {
        temp[k++] = A[i++];
    }
    
    while( j <= r)
    {
        temp[k++]=A[j++];
    }
    
    for(int i=l;i<=r;i++)
    {
        A[i]=temp[i];
    }
    return count;
}



long int mergesort(int A[],int temp[],int l,int r )
{
    long int count = 0;
    int mid;
    
    if( r > l)
    {
        // mid = (l + (r - l) )/2;
        mid = (l+r)/2;
        count+=mergesort(A,temp,l,mid);
        count+=mergesort(A,temp,mid+1,r);
        count+=merge(A,temp,l,mid+1,r);
    }
   
    return count;
}


int main()
{
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int n;
        cin>>n;
        
        int A[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        
        int temp[n];
        
        long int ans = mergesort(A,temp,0,n-1);
        cout<<ans<<endl;
        
    }


	return 0;
}
