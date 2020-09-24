int Solution::candy(vector<int> &A) 
{
    int n = A.size();
   vector<int>res_left(n,1);
   vector<int>res_right(n,1);
   
   for(int i=1;i<n;i++)  //compare only with left neighbour
   {
       if(A[i] > A[i-1])
       {
           res_left[i] = res_left[i-1]+1;
       }
   }
   
   for(int i=n-2;i>=0;i--)  //Compare only with right neighbour
   {
       if(A[i] > A[i+1])
       {
           res_right[i] = res_right[i+1]+1;
       }
   }
   
   int count=0;
   for(int i=0;i<n;i++)   // Now take the max(left_neighbour, right_neighbour)
   {
       count = count + max(res_left[i],res_right[i]);
   }
   
   return count;
}
