/*Given two sorted integer arrays A and B, merge B into A as one sorted array.
 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

*/

void Solution::merge(vector<int> &A, vector<int> &B)
{
    //TC=O(n*logn)
     //SC=O(1)
    //Using gap method
    //Watch : https://www.youtube.com/watch?v=hVl2b3bLzBw
   int n = A.size();
   int m = B.size();
   
   int gap=(m+n)/2;;
   
   for(int i=0;i<m;i++)
   {
       A.push_back(B[i]);
   }
   
   int arr_size = A.size();
   while(gap>=1)
   {
       int i=0;
       int j=gap;
       
       while(j<arr_size)
       {
           if(A[i]>A[j])
           {
               swap(A[i],A[j]);
           }
           i++;
           j++;
       }
       
       gap=gap/2;
   }
}

-----------------------------------------------------------------------------------
 
 
 //TC = O(n+m)
 //SC=O(1)
 class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        
        while(i>=0 && j>=0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
            {
                nums1[k--]=nums2[j--];
            }
        }
        
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
};
