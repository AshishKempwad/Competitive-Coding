/*Given an integer array A of size N.

You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.

If it exists return 1 else return 0.

NOTE:
Do not consider the corner elements i.e A[0] and A[N-1] as the answer.

Input 1:
 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]

Output 1:
 1
 
 Explanation 1:
 A[4] = 6 is the element we are looking for.
 All elements on left of A[4] are smaller than it and all elements on right are greater.


Problem Constraints
3 <= N <= 105
1 <= A[i] <= 109

TC = O(n)
SC = O(n)
*/








int Solution::perfectPeak(vector<int> &A)
{
    int n = A.size();
    vector<int>left_to_right(A.size(),0);   //maximum till that point from left
    vector<int>right_to_left(A.size(),0);    //lowest till that point from right
    
    left_to_right[0]=A[0];
    right_to_left[n-1]=A[n-1];
    
    for(int i=1;i<n;i++)
    {
        left_to_right[i]=max(A[i],left_to_right[i-1]);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        right_to_left[i]= min(A[i],right_to_left[i+1]);
    }
    
    for(int i=1;i<n-1;i++)
    {
        if(left_to_right[i-1] < A[i] && right_to_left[i+1] > A[i])
        {
            return 1;
        }
    }
    
    return 0;
}
