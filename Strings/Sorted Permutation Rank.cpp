void factorial(int n,vector<int>&res)
{
    res[0]=1;
    res[1]=1;
    for(int i=2;i<n;i++)
    {
        res[i]=(i*res[i-1])%1000003;
    }
}

int Solution::findRank(string A)
{
    //Using dictionary method
    
    string s=A;
    sort(s.begin(),s.end());
    int n=s.size();
    vector<int>res(n);
    factorial(n,res);
    
    int index=0;
    long long int ans=0;
    vector<int>check(n,0);
    
    for(int i=0;i<n;i++)
    {
        if(check[i]==0)
        {
            if(A[index]!=s[i])
            {
                ans+=res[n-index-1];
            }
            else
            {
                check[i]=-1;   //have already visisted that
                index++;
                i=-1;   //we again start checking from first
            }
        }
    }
    return (ans+1)%1000003;
}
