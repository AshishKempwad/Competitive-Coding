vector<int> Solution::solve(vector<int> &A) 
{
    int n = A.size();
    vector<int>res;
    res.push_back(A[n-1]);  // last element will always be the leader as there wont be any element to its right.

    int max_ele = A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(A[i] > max_ele)
        {
            res.push_back(A[i]);
            max_ele = A[i];
        }
    }
    
    return res;
    
}
