int peak(int l,int h,int n,vector<int>&A)
{
     while(l<=h)
    {
        int mid=(l+h)/2;
        if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
        {
            return mid;
        }
        else if(A[mid-1]>A[mid])
        {
            h=mid-1;
        }
        else if(A[mid+1]>A[mid])
        {
            l=mid+1;
        }
     
    }
    return -1;
}

int bs(int l,int h,vector<int>&A,int B)
{
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[mid]>B)
        {
            h=mid-1;
        }
        else if(A[mid]<B)
        {
            l=mid+1;
        }
    }
    return -1;
}

int bs_r(int l,int h,vector<int>&A,int B)//the array is reverse sorted hence we modify our bs that way.
{
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[mid]>B)
        {
            l=mid+1;
        }
        else if(A[mid]<B)
        {
            h=mid-1;
        }
    }
    
    return -1;
}

int Solution::solve(vector<int> &A, int B) 
{
    //1)Find peak element.
    //2)All element before peak elemnts inlcuding peak element will be sorted in ascending.
    //3)All elements after peak elements,including peak will be sorted in descending.
    //4)Apply binary search on both halves.
    
    int l=0;
    int h=A.size()-1;
    int n=A.size();
    
    int peak_index = peak(l,h,n,A);
    
    int left_bs=bs(l,peak_index,A,B);
    int right_bs=bs_r(peak_index,h,A,B);
    
    if(left_bs==-1 && right_bs!=-1)
    {
        return right_bs;
    }
    else if(left_bs!=-1 && right_bs==-1)
    {
        return left_bs;
    }
   return -1;
}
