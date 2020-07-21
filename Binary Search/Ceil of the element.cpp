int findCeil(vector<long long> v, long long n, long long x)
{
    
    long long l = 0;
    long long h = n-1;
    long long res = -1;
    
    while(l <= h)
    {
        long long mid = l + (h - l)/2;
        
        if(v[mid] == x)
        {
            return mid;
        }
        else if( x > v[mid])
        {
            l = mid+1;
        }
        else 
        {
            res = mid;
            h = mid-1;
        }
    }
    
    return res;
    
    // Your code here
    
}
