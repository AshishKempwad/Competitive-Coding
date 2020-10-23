int find_min(const vector<int>&A,int l,int h)
{
    int n = A.size();
    if(A[l]<A[h])
    {
        return l;
    }
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        int prev =  (mid-1+n)%n;  //to handle overflow condition
        int nex = (mid+1)%n;   //to handle overflow condition
        
        if(A[mid] <= A[prev] && A[mid] <= A[nex])
        {
            return mid;
        }
        else if(A[mid]>=A[l]) //left half is sorted, so go and search in right half
        {
            l=mid+1;
        }
        else if(A[mid]<=A[h]) //right half is sorted, hence go and find in left half
        {
            h=mid-1;
        }
    }
    
    return -1;
}


int bs(int l,int h,const vector<int>&A,int B)
{
    while(l<=h)
    {
        int mid = (l+h)/2;
        
        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[mid] > B)
        {
            h=mid-1;
        }
        else if(A[mid] < B)
        {
            l=mid+1;
        }
    }
    return -1;
}


int Solution::search(const vector<int> &A, int B) 
{
    
    //This question is based on the idea of finding minimum element.
    //1)Find minimum element.
    //2)Apply binary search from (0,minimum_ele_index-1)
    //3)Apply binary search from(minimum_ele_index,n-1)
    
    int n=A.size();
    int l=0;
    int h=n-1;
    int minimum_ele_index=find_min(A,l,h);
   
    int left_bs = bs(l,minimum_ele_index-1,A,B);
    int right_bs = bs(minimum_ele_index,h,A,B);
    
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
