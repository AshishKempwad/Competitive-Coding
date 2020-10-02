vector<vector<int> > Solution::solve(int A)
{
    vector<vector<int>>res(A);
    
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j || j==0)
            {
                res[i].push_back(1);
            }
            else
            {
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
        }

    }
    
    return res;
}

