/*


        In the first pass, compute the consecutive occurrence count for each element.
        In the second pass, traverse from the right end.
        a. If the recurrence count is not equal to B, append the corresponding element to the result string #recurrence times.
        b. If the recurrence count is equal to B, simply skip B elements and repeat process 2 until you reach the beginning.
        reverse the final string and return it

*/





string Solution::solve(string A, int B) 
{
    
    int n = A.size();
    int j = n-1;
    
    vector<int>res(n,1);
    string s="";
    
    for(int i=1;i<n;i++)
    {
        if(A[i]==A[i-1])
        {
            res[i] = res [i] + res[i-1];
        }
    }
    
    while( j >= 0)
    {
        if(res[j]!=B)
        {
            for(int i=0;i<res[j];i++)
            {
                s = s + A[j];
            }
            
        }
        
        j = j - res[j];
    }
    reverse(s.begin(),s.end());
    return s;
}
