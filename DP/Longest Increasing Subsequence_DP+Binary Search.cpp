
int find_ceil(int tail[],int l,int r,int x) //find ceil of element
{
    while(r>l)//binary search
    {
       int mid = l +(r-l)/2;
       if(tail[mid] >= x)
       {
           r=mid;
       }
       else
       {
           l=mid+1;
       }
    }
    
    return r;
}

int Solution::lis(const vector<int> &A) 
{
    //DP+Binary search
    //TC=O(nlogn)
    
    int n = A.size();
    int tail[n];
    int len=1;
    tail[0]=A[0];
    
    for(int i=1;i<n;i++)
    {
        if(A[i]>tail[len-1])
        {
            tail[len]=A[i];
            len++;
        }
        else
        {
            int pos = find_ceil(tail,0,len-1,A[i]);
            tail[pos]=A[i];
        }
    }
    
    return len;
    
}
