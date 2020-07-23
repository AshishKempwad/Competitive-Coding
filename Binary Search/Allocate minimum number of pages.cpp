
bool isvalid(int arr[],int n,int m,int mid)
{
    int sum=0;
    int student=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > mid)
        {
            return false;
        }
        sum = sum + arr[i];
        if(sum > mid)
        {
            student++;
            sum = arr[i];
        }
        
        if(student > m)
        {
            return false;
        }
    }
    
    return true;
}

int findPages(int *arr, int n, int m)
{
    
    if(m > n)   //if number of students are more than the number of books
    {
        return -1;
    }
      int res = -1;
    int max_one = INT_MIN;
    int overall_sum = 0;
    for(int i=0;i<n;i++)
    {
        max_one = max(max_one,arr[i]);
        overall_sum = overall_sum + arr[i];
    }
    
    int l = max_one;
    int h = overall_sum;
    
    while(l<=h)
    {
        int mid = l + (h-l)/2;
      
        if(isvalid(arr,n,m,mid)==true)
        {
            res = mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    
    return res;
    //code here
}
