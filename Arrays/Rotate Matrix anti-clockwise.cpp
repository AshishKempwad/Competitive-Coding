void Solution::rotate(vector<vector<int> > &A) 
{
    int n = A.size();
    
    //1)Transpose the matrix
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }
    
    //2)Reverse the element in each coloumn.
    

   
   for(int i=0;i<n;i++)
   {
       int top = 0;
       int down = n-1;
       while(down >= top)
       {
               swap(A[top][i],A[down][i]);
               top++;
               down--;
       }
   }

}
