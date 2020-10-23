/*
Given a matrix of integers A of size N x M in which each row is sorted.
Find an return the overall median of the matrix A.
Note: No extra memory is allowed.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.


Input Format
The first and only argument given is the integer matrix A.

Output Format
Return the overall median of the matrix A.

Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd

For Example
Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=



*/
int Solution::findMedian(vector<vector<int> > &m)
{
    //Brute force
    // vector<int>res;
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)
    //     {
    //         res.push_back(A[i][j]);
    //     }
    // }
    // sort(res.begin(),res.end());
    
    // int n = res.size();
    // return res[n/2];
    
   //Optimal approach:
   
   //Constraint : M*N is odd
   
  int min = INT_MAX, max = INT_MIN;
  int r=m.size();
  int c=m[0].size();
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
 
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than mid
        for (int i = 0; i < r; i++)
            place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
   
    
};
