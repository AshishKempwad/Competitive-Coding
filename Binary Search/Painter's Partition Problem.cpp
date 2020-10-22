
//Exactly like allocate min no of pages problem

bool isvalid(int painters,vector<int>&C,int mid)
{
    int no_of_painters=1;
    int Time=0;
    int n=C.size();
    for(int i=0;i<n;i++)
    {
        if(C[i]>mid)
        {
            return false;
        }
        Time=Time+C[i];
        if(Time > mid)
        {
            no_of_painters++;
            Time=C[i];
        }
        
        if(no_of_painters > painters)
        {
            return false;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    long long int h=C[0];
    int l=C[0];
   for(int i=1;i<C.size();i++)
   {
      h=h+C[i];
      l=max(l,C[i]);
   }
    h=h%10000003;
    
    long long int res=-1;
    
    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(isvalid(A,C,mid)==true)
        {
            res=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    
    return (res*B)%10000003;
}
