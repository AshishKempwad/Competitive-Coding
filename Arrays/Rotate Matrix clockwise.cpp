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
    
    //2)Reverse the element in each row.
    

    for(int i=0;i<n;i++)
    {
         int left = 0;
         int right = n-1;

        while(right >= left)
        {
            swap(A[i][left],A[i][right]);
            right--;
            left++;
        }
    }

}
